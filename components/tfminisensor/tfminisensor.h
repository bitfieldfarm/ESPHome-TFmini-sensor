#include "esphome.h"

class TFminiSensor : public Component, public UARTDevice, public Sensor {
 public:
  TFminiSensor(UARTComponent *parent) : UARTDevice(parent) {}

  void setup() override {
    // Eventuell sensor-initialisering her
  }

  void loop() override {
    // Les data fra UART
    while (available()) {
      uint8_t c = read();
      if (c == 0x59) {  // Startbyte for TFmini Plus
        float distance = readDistance();
        publish_state(distance);
      }
    }
  }

  float readDistance() {
    // Implementer tolkning av data fra sensoren
    return 100.0;  // Dummyverdi for testing
  }
};
