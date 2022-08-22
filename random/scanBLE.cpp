/*include the libraries*/
#include <string>
#include <esp_log.h>
#include "BLUEtils.h"
#include "BLUEscan.h"
#include "BLEDevice.h"
#include "BLEAdvertisedDevice.h"
#include "sdkconfig.h"

/*define the log tag*/
static const char LOG_TAG[] = "scanBLE";

/*define the log level*/
class MyAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks
{
    void onResult(BLEAdvertisedDevice advertisedDevice)
    {
        ESP_LOGD(LOG_TAG, "onResult: %s", advertisedDevice.toString().c_str());
    }
};

static void run()
{
    /*create the callback object*/
    ESP_LOGD(LOG_TAG, "run BLE scan");
    BLEDevice::init("ESP32-BLEScan");
    BLEScan * pBLEScan = BLEDevice::getScan();
    pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
    pBLEScan->start(0x00, true);
    BLEScanResults scanResults = pBLEScan->getResults();
    /*print the results*/
    ESP_LOGD(LOG_TAG, "program found %d devices", scanResults.getCount());
    ESP_LOGD(LOG_TAG, "finished BLE scan");
}

void SampleScan(void)
{
    run();
}