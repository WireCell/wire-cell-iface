/** A clustering consumes a stream of blob sets and produces clusters.
 *
 * Note, implementations may levy restrictions on order and overlap of
 * input blob sets.
*/

#ifndef WIRECELL_ICLUSTERING
#define WIRECELL_ICLUSTERING

#include "WireCellIface/IQueuedoutNode.h"
#include "WireCellIface/IBlobSet.h"
#include "WireCellIface/ICluster.h"

namespace WireCell {

    class IClustering : public IQueuedoutNode<IBlobSet, ICluster> {
    public:
	typedef std::shared_ptr<IClustering> pointer;

	virtual ~IClustering() ;

	virtual std::string signature() {
            return typeid(IClustering).name();
	}

        /// supply:
        // virtual bool operator()(const input_pointer& in, output_queue& outq) = 0;
    };
}

#endif

