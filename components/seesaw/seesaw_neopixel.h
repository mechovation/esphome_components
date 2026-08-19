#pragma once

#include "esphome/core/component.h"
#include "esphome/components/light/light_output.h"
#include "seesaw.h"

namespace esphome {
namespace seesaw {

class SeesawNeopixel : public light::LightOutput, public Component {
 public:
  void setup() override;
  void set_parent(Seesaw *parent) { parent_ = parent; }
  void set_pin(uint8_t pin) { pin_ = pin; }
  light::LightTraits get_traits() override;
  void write_state(light::LightState *state) override;
 protected:
  Seesaw *parent_;
  uint8_t pin_{6};
};

}  // namespace seesaw
}  // namespace esphome
