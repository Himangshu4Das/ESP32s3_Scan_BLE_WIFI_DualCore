# ESP32s3_Scan_BLE_WIFI_DualCore
Scan available Bluetooth and WiFi devices using Xiao's Esp32s3. Implement this using multiprocessing (dual cores).

# ESP32-S3 Bluetooth and Wi-Fi Scanner

This is a simple project that demonstrates how to scan for Bluetooth devices and Wi-Fi networks using the ESP32-S3 with dual core support. The code is written in C++ using the Arduino framework and uses the [WiFi](https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi) and [BLEDevice](https://github.com/espressif/arduino-esp32/tree/master/libraries/BLE) libraries.

## Prerequisites

Before you begin, you'll need the following:

- An ESP32-S3 development board
- A USB cable to connect the board to your computer
- The Arduino IDE installed on your computer
- The [ESP32 core for Arduino](https://github.com/espressif/arduino-esp32) installed in the Arduino IDE

## Installation

1. Clone this repository to your local machine:

```
git clone https://github.com/your-username/esp32s3-bluetooth-wifi-scanner.git
```

2. Open the Arduino IDE and navigate to File > Open. Browse to the folder where you cloned this repository and select the `esp32s3-bluetooth-wifi-scanner.ino` file.

3. Connect your ESP32-S3 development board to your computer using a USB cable.

4. Select the board and port from the Tools menu in the Arduino IDE. For the board, select "ESP32 Dev Module" and for the port, select the port your board is connected to.

5. Upload the code to your board by clicking the "Upload" button in the Arduino IDE.

6. Open the Serial Monitor by clicking the magnifying glass icon in the top right corner of the Arduino IDE. Make sure the baud rate is set to 9600.

7. The code will start running and you should see the results of the Bluetooth and Wi-Fi scans in the Serial Monitor.

## Usage

The code scans for Bluetooth devices and Wi-Fi networks simultaneously using the ESP32-S3's dual core architecture. The scans run for a specified amount of time (defined by the `SCAN_TIME` constant in the code) and then display the results in the Serial Monitor.

You can modify the code to suit your specific requirements. For example, you could change the scan time, add additional functionality to the code, or integrate it with other projects.

## Contributing

If you'd like to contribute to this project, feel free to fork the repository and submit a pull request. You can also submit issues or feature requests in the GitHub issue tracker.

## Acknowledgements

This project is based on the ESP32 Bluetooth and Wi-Fi scanner example code provided by the [ESP32 core for Arduino](https://github.com/espressif/arduino-esp32) repository.
