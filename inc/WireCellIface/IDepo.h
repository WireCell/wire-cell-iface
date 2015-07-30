#ifndef WIRECELL_IDEPO
#define WIRECELL_IDEPO

#include "WireCellIface/ISequence.h"

#include "WireCellUtil/Point.h"

namespace WireCell {

    /** An interface to information about a deposition of charge.
     */
    class IDepo {
    public:
	virtual ~IDepo() {};

	/// The location of the deposition.
	virtual Point point() const = 0;

	/// The number of seconds from some absolute start time to
	/// when the deposition occur ed.
	virtual double time() const = 0;

	/// The number charge (in units of number of electrons) deposited.
	virtual double charge() const = 0;
	
    };

}


WIRECELL_SEQUENCE_ITR(Depo,depo);
WIRECELL_SEQUENCE_ABC(Depo,depo);
WIRECELL_SEQUENCE_SINK(Depo,depo);



#endif
