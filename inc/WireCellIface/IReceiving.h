#ifndef WIRECELL_IRECEIVING
#define WIRECELL_IRECEIVING

#include <memory>

namespace WireCell {

    /** A DFP base for any node that accepts input of a certain type.
     */
    template<typename InputType>
    class IReceiving {
    public:
	virtual ~IReceiving() {}

	// Accept a data object for input.  Return false if unable to
	// accept.
	virtual bool insert(const std::shared_ptr<const InputType>& in) = 0;
    };

}

#endif