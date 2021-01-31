
#ifndef SIM800_CELLULARCONTEXT_H_
#define SIM800_CELLULARCONTEXT_H_

#include "AT_CellularContext.h"
#include "SIM800_CellularNetwork.h"

namespace mbed {

class SIM800_CellularContext: public AT_CellularContext {
public:
    SIM800_CellularContext(ATHandler &at, CellularDevice *device, const char *apn, bool cp_req = false, bool nonip_req = false);
    virtual ~SIM800_CellularContext();

    virtual void do_connect();

    virtual void do_disconnect();

    virtual nsapi_error_t get_gateway(SocketAddress *addr);

    const char *get_apn(void);

    const char *get_uname(void);

    const char *get_pwd(void);

    CellularContext::AuthenticationType get_auth(void);

 
protected:
    virtual NetworkStack *get_stack();

    /** Connect the on board IP stack of the modem.
     *
     * @return      True if successful, otherwise false.
     */

    nsapi_error_t define_context();

private:

    /** Length of IMSI buffer.
     */
    static const int MAX_IMSI_LENGTH = 15;

    /** The type of authentication to use.
     */
    AuthenticationType _auth;

    /** Activate one of the on-board modem's connection profiles.
     *
     * @param apn      The APN to use.
     * @param username The user name to use.
     * @param password The password to use.
     * @param auth     The authentication method to use
     *                 (NOAUTH, PAP,
     *                 CHAP or AUTOMATIC).
     * @return         True if successful, otherwise false.
     */

    bool activate_profile(const char *apn, const char *username, const char *password, AuthenticationType auth);


    /** Disconnect the on board IP stack of the modem.
     *
     * @return      True if successful, otherwise false.
     */
    bool disconnect_modem_stack();

    /** Read IMSI of modem.
     */
    nsapi_error_t get_imsi(char *imsi);
};

} /* namespace mbed */

#endif // SIM800_CELLULARCONTEXT_H_
