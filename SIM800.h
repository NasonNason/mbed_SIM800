#ifndef MBED_SIM800_H_
#define MBED_SIM800_H_

#include "AT_CellularDevice.h"
#include "drivers/BufferedSerial.h"


namespace mbed {

class SIM800 : public AT_CellularDevice {

  public:
    SIM800(FileHandle* fh);

};

} // namespace mbed

#endif // SIM800_H_