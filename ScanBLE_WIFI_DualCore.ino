#include <WiFi.h>
#include <BLEDevice.h>

// Pin definitions
#define SCAN_TIME 5 // Time in seconds to scan for BLE devices and Wi-Fi networks

// Function prototypes
void scanWiFiTask(void *parameter);
void scanBLETask(void *parameter);

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  // Initialize Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Initialize BLE
  BLEDevice::init("");
}

void loop() {
  // Create two tasks to scan for Wi-Fi networks and BLE devices
  xTaskCreatePinnedToCore(scanWiFiTask, "scanWiFiTask", 10000, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(scanBLETask, "scanBLETask", 10000, NULL, 1, NULL, 1);

  // Wait for the tasks to complete
  vTaskDelay(SCAN_TIME * 1000 / portTICK_PERIOD_MS);
}

void scanWiFiTask(void *parameter) {
  int numNetworks = WiFi.scanNetworks();
  Serial.printf("Found %d Wi-Fi networks:\n", numNetworks);
  for (int i = 0; i < numNetworks; i++) {
    Serial.printf("%s (%d dBm)\n", WiFi.SSID(i).c_str(), WiFi.RSSI(i));
  }
}

void scanBLETask(void *parameter) {
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setActiveScan(true);
  BLEScanResults results = pBLEScan->start(SCAN_TIME, false);
  Serial.printf("Found %d BLE devices:\n", results.getCount());
  for (int i = 0; i < results.getCount(); i++) {
    BLEAdvertisedDevice device = results.getDevice(i);
    Serial.printf("%s (%s)\n", device.getName().c_str(), device.getAddress().toString().c_str());
  }
}
