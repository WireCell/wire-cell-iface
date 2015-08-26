#ifndef WIRECELL_WIREPLANEID
#define WIRECELL_WIREPLANEID

#include <ostream>

namespace WireCell {


    /// Enumerate layer IDs.  These are not indices!
    enum WirePlaneLayer_t { kUnknownLayer=0, kUlayer=1, kVlayer=2, kWlayer=4 };

    class WirePlaneId {
    public:
	WirePlaneId(WirePlaneLayer_t layer = kUnknownLayer, int face = 0, int apa = 0);

	/// Unit ID as integer 
	int ident() const;

	/// Layer as enum
	WirePlaneLayer_t layer() const;

	/// Layer as integer (not index!)
	int  ilayer() const;

	/// Layer as index number (0,1 or 2).  -1 if unknown
	int index() const;

	/// APA face number
	int face() const;

	/// APA number
	int apa() const;

	/// return true if valid
	operator bool() const;

	bool operator==(const WirePlaneId& rhs);

	bool operator!=(const WirePlaneId& rhs);
	
	bool operator<(const WirePlaneId& rhs);

    private:
	int m_pack;
    };
    
    

}

std::ostream& operator<<(std::ostream& o, const WireCell::WirePlaneId& wpid);
std::ostream& operator<<(std::ostream& o, const WireCell::WirePlaneLayer_t& layer);

#endif
