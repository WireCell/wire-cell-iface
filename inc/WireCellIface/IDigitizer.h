#ifndef WIRECELL_IDIGITIZER
#define WIRECELL_IDIGITIZER

#include "WireCellUtil/IComponent.h"

#include "WireCellIface/IConverter.h"
#include "WireCellIface/IChannelSlice.h"
#include "WireCellIface/IPlaneSlice.h"
#include "WireCellIface/IWire.h"

namespace WireCell {

    /** A digitizer is a processor which produces channel slices from
     * an input vector of place slices, one per plane given the input
     * wire vector.
     */
    class IDigitizer
	: public IComponent<IDigitizer>
	, public IConverter<IPlaneSliceVector, IChannelSlice::pointer>
    {
    public:
	virtual ~IDigitizer() {}

	virtual bool set_wires(const IWireVector& wires) = 0;
    };

}

#endif