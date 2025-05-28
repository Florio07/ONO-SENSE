#include <Arduino.h>
#include <RadioLib.h>
#include <LSM6DS3.h>
#include <Wire.h>

#define P0_13       13  // The battery internal pin
#define YLED        6   // RJ45 Yellow LED pin
#define GLED        7   // RJ45 Green LED pin

// LoRa module (Wio-SX1262) pin definitions
#define BTN         0   // Button pin with pull-up resistor
#define LORA_DIO1   1   // DIO1 pin: interrupt active when the operation is complete 
#define LORA_RST    2   // Reset pin
#define LORA_BUSY   3   // Busy pin
#define NSS         4   // SPI Chip Select pin (Not Slave Select)
#define LORA_RF_SW  5   // RF switch pin
#define SCK         8   // SPI Clock pin
#define MISO        9   // SPI MISO pin LoRa → XIAO
#define MOSI        10  // SPI MOSI pin XIAO → LoRa

// Create RadioLib SX1262 instance
SX1262 lora = new Module(NSS, LORA_DIO1, LORA_RST, LORA_BUSY);

// Create LSM6DS3 instance
LSM6DS3 imu(I2C_MODE, 0x6A); // I²C mode and address

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);   // Configure built-in LED pin
  digitalWrite(LED_BUILTIN, LOW); // Turn off the built-in LED
  
  pinMode(P0_13, OUTPUT); // Configure battery pin
  Wire.begin(); // Initialize I²C communication

  Serial.begin(115200); // Initialize serial communication for debugging

  if (imu.begin() != 0) {
    Serial.println("IMU initialization failed!");
  } else {
    Serial.println("IMU initialized successfully.");
  }

  imu.writeRegister(LSM6DS3_ACC_GYRO_CTRL2_G, 0x00); // Desable gyroscope for power saving
}

void loop() {
  digitalWrite(P0_13, LOW); // Battery charge current HIGH: 50 mA; LOW: 100 mA
}
