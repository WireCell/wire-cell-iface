#ifndef WIRECELL_ICELLMAKER
#define WIRECELL_ICELLMAKER

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IConverter.h"
#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"

namespace WireCell {

    /** A cell maker is a processor component which outputs a
     * collection of cells associated with the input collection or
     * wires.
     */
    class ICellMaker
	: public IComponent<ICellMaker> 
	, public IConverter<IWire::vector,ICell::vector>
    {
    public:
	virtual ~ICellMaker() {}
	
    };

}

#endif

