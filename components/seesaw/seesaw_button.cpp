#include "esphome/core/hal.h"
#include "seesaw_button.h"
#include "esphome/core/log.h"

namespace esphome {
namespace seesaw {

static const char *const TAG = "seesaw.binary_sensor";

void SeesawButton::setup() {
  this->parent_->set_pinmode(this->pin_, gpio::FLAG_PULLUP);
  this->parent_->set_gpio_interrupt(this->pin_, true);
  this->publish_initial_state(this->parent_->digital_read(this->pin_) != this->inverted_);
}

void SeesawButton::dump_config() {
  LOG_BINARY_SENSOR("", "Seesaw Button", this);
}

void SeesawButton::loop() { this->publish_state(this->parent_->digital_read(this->pin_) != this->inverted_); }

}  // namespace seesaw
}  // namespace esphome
