#include "seesaw_neopixel.h"
#include "esphome/core/log.h"

namespace esphome {
namespace seesaw {

static const char *const TAG = "seesaw.neopixel";

void SeesawNeopixel::setup() {
  this->buffer_.assign(this->num_leds_ * 3, 0);
  this->effect_data_.assign(this->num_leds_, 0);
  this->parent_->setup_neopixel(this->pin_, this->num_leds_);
}

light::LightTraits SeesawNeopixel::get_traits() {
  auto traits = light::LightTraits();
  traits.set_supported_color_modes({light::ColorMode::RGB});
  return traits;
}

void SeesawNeopixel::clear_effect_data() {
  for (auto &effect_data : this->effect_data_)
    effect_data = 0;
}

void SeesawNeopixel::write_state(light::LightState *state) {
  for (uint16_t i = 0; i < this->num_leds_; i++) {
    const uint8_t *base = &this->buffer_[i * 3];
    this->parent_->color_neopixel(i, base[0], base[1], base[2]);
  }
  this->parent_->update_neopixel();
}

light::ESPColorView SeesawNeopixel::get_view_internal(int32_t index) const {
  uint8_t *base = &this->buffer_[index * 3];
  return light::ESPColorView(base, base + 1, base + 2, nullptr, &this->effect_data_[index], &this->correction_);
}

}  // namespace seesaw
}  // namespace esphome
