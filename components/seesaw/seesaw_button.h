#pragma once

#include "esphome/core/component.h"
#include "esphome/components/binary_sensor/binary_sensor.h"
#include "seesaw.h"

namespace esphome {
namespace seesaw {

class SeesawButton : public binary_sensor::BinarySensor, public Component {
 public:
  void setup() override;
  void dump_config() override;
  void loop() override;
  void set_parent(Seesaw *parent) { parent_ = parent; }
  void set_pin(uint8_t pin) { pin_ = pin; }
  void set_inverted(bool inverted) { inverted_ = inverted; }

 protected:
  Seesaw *parent_;
  uint8_t pin_{24};
  bool inverted_{true};
};

}  // namespace seesaw
}  // namespace esphome
