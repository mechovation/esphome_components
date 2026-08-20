#pragma once

#include "esphome/components/light/addressable_light.h"
#include "seesaw.h"
#include <vector>

namespace esphome {
namespace seesaw {

class SeesawNeopixel : public light::AddressableLight {
 public:
  void setup() override;
  void set_parent(Seesaw *parent) { parent_ = parent; }
  void set_pin(uint8_t pin) { pin_ = pin; }
  void set_num_leds(uint16_t num_leds) { num_leds_ = num_leds; }
  int32_t size() const override { return this->num_leds_; }
  void clear_effect_data() override;
  light::LightTraits get_traits() override;
  void write_state(light::LightState *state) override;

 protected:
  light::ESPColorView get_view_internal(int32_t index) const override;

  Seesaw *parent_;
  uint8_t pin_{6};
  uint16_t num_leds_{1};
  mutable std::vector<uint8_t> buffer_;
  mutable std::vector<uint8_t> effect_data_;
};

}  // namespace seesaw
}  // namespace esphome
