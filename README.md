## Mbed SIM800
>> WIP

Adds support for SIM800L module to [mbed os network stack](https://os.mbed.com/docs/mbed-os/v6.7/apis/network-interface-apis.html)

Only AT mode is supported.

## Settings

Requires a minimum of the following settings in your [mbed_app.json](https://os.mbed.com/docs/mbed-os/latest/program-setup/advanced-configuration.html)

```json
{
    "YOUR_TARGET":{
        "target.network-default-interface-type": "CELLULAR",
        "nsapi.default-cellular-sim-pin": null,
        "nsapi.default-cellular-plmn": null,
        "nsapi.default-cellular-apn": "\"safaricom.com\"",
        "nsapi.default-cellular-username": "\"saf\"",
        "nsapi.default-cellular-password": "\"data\"",
        "SIM800.provide-default": true,
        "SIM800.tx": "PD_5",
        "SIM800.rx": "PD_6",
        "SIM800.baudrate": 115200
    }
}

```

You can add the following to disable lwip

```json
{
    "YOUR_TARGET":{
        "cellular.debug-at": true,
        "lwip.ppp-enabled": false,
        "lwip.tcp-enabled": false
    }
}
```
