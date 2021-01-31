
#include "SIM800.h"
#include "mbed_trace.h"

using namespace mbed;

// by default all properties are supported
//@todo set correctly
static const intptr_t cellular_properties[AT_CellularDevice::PROPERTY_MAX] = {
    0, // C_EREG
    AT_CellularNetwork::RegistrationModeLAC, // C_GREG
    AT_CellularNetwork::RegistrationModeLAC, // C_REG
    1,                                       // AT_CGSN_WITH_TYPE
    1,                                       // AT_CGDATA
    1,                                       // AT_CGAUTH
    1,                                       // AT_CNMI
    1,                                       // AT_CSMP
    1,                                       // AT_CMGF
    1,                                       // AT_CSDH
    1,                                       // PROPERTY_IPV4_STACK
    1,                                       // PROPERTY_IPV6_STACK
    1,                                       // PROPERTY_IPV4V6_STACK
    0,                                       // PROPERTY_NON_IP_PDP_TYPE
    1,                                       // PROPERTY_AT_CGEREP
    1,                                       // PROPERTY_AT_COPS_FALLBACK_AUTO
    5,                                       // PROPERTY_SOCKET_COUNT #TODO: Please check if this number is okay later on
    1,                                       // PROPERTY_IP_TCP
    1,                                       // PROPERTY_IP_UDP
    0,                                       // PROPERTY_AT_SEND_DELAY
};

SIM800::SIM800(FileHandle* fh) : AT_CellularDevice(fh) {
    set_cellular_properties(cellular_properties);

}


#if MBED_CONF_SIM800_PROVIDE_DEFAULT


CellularDevice* CellularDevice::get_default_instance() {
    static BufferedSerial serial(MBED_CONF_SIM800_TX, MBED_CONF_SIM800_RX, MBED_CONF_SIM800_BAUDRATE);
#if defined (MBED_CONF_SIM800_RTS) && defined(MBED_CONF_SIM800_CTS)
    tr_debug("SIM800 flow control: RTS %d CTS %d", MBED_CONF_SIM800_RTS, MBED_CONF_SIM800_CTS);
    serial.set_flow_control(SerialBase::RTSCTS, MBED_CONF_SIM800_RTS, MBED_CONF_SIM800_CTS);
#endif
    static SIM800 device(&serial);
    return &device;
}

#endif
