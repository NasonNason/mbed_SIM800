

#ifndef SIM800_CELLULAR_NETWORK_H_
#define SIM800_CELLULAR_NETWORK_H_

#include "AT_CellularNetwork.h"

namespace mbed {

class SIM800_CellularNetwork : public AT_CellularNetwork {

public:
    SIM800_CellularNetwork(ATHandler &atHandler, AT_CellularDevice &device);
    
    virtual ~SIM800_CellularNetwork();

};

} // namespace mbed

#endif // SIM800_CELLULAR_NETWORK_H_
