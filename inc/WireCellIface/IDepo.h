#ifndef WIRECELL_IDEPO
#define WIRECELL_IDEPO

#include "WireCellIface/IData.h"
#include "WireCellUtil/Point.h"
#include "WireCellUtil/Units.h"

#include <boost/signals2.hpp>
#include <set>

namespace WireCell {

    /** An interface to information about a deposition of charge.
     */
    class IDepo : public IData<IDepo> {
    public:
	
	virtual ~IDepo() {};

	/// The location of the deposition.
	virtual const Point& pos() const = 0;

	/// The number of seconds from some absolute start time to
	/// when the deposition occur ed.
	virtual double time() const = 0;

	/// The number charge (in units of number of electrons) deposited.
	virtual double charge() const = 0;
	
	/// If the deposition is drifted, this accesses the original.
	/// Note, return value is an IDepoPtr.
	virtual const_ptr original() const { return 0; }

    };


    /// Compare how "far" two depositions are from the origin along
    /// the drift-line (metric: dT + dX/V_drift) given a drift velocity.
    struct IDepoPtrDriftCompare {
	double drift_velocity;
	IDepoPtrDriftCompare(double drift_velocity = 1.6 *units::mm/units::microsecond)
	    : drift_velocity(drift_velocity) {};
	bool operator()(const IDepo::const_ptr& lhs, const IDepo::const_ptr& rhs) const {
	    double t1 = lhs->time() + lhs->pos().x()/drift_velocity;
	    double t2 = rhs->time() + rhs->pos().x()/drift_velocity;
	    if (t1 == t2) {
		// make sure there are no ties due to precision!
		return lhs.get() < rhs.get(); 
	    }
	    return t1 < t2;
	}
    };
    typedef std::set<IDepo::const_ptr, IDepoPtrDriftCompare> DepoTauSortedSet;


}

#endif
