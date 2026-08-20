# esphome-seesaw

ESPHome external component support for the Adafruit I2C seesaw rotary encoder board.

This component targets ESP32 projects using the ESP-IDF framework. It talks to seesaw directly through ESPHome's I2C APIs and does not require Arduino libraries.

## Supported features

- Rotary encoder position sensor
- Encoder pushbutton binary sensor
- On-board NeoPixel RGB light

## Usage

```yaml
external_components:
  - source: github://mechovation/esphome-seesaw
    components: [seesaw]

esp32:
  board: esp32-s3-devkitc-1
  variant: esp32s3
  framework:
    type: esp-idf

i2c:
  sda: 43
  scl: 44

seesaw:
  - id: ss_black
    address: 0x39

sensor:
  - platform: seesaw
    name: "Black Encoder"
    seesaw_id: ss_black

binary_sensor:
  - platform: gpio
    name: "Black Encoder Button"
    pin:
      seesaw: ss_black
      number: 24
      mode: input_pullup
      inverted: true

light:
  - platform: seesaw
    name: "Black Encoder NeoPixel"
    seesaw_id: ss_black
    pin: 6
    num_leds: 1
```

The Adafruit rotary encoder board defaults are used when omitted:

- Encoder number: `0`
- NeoPixel pin: `6`
- NeoPixel LEDs: `1`

Use ESPHome's `gpio` binary sensor platform with a `seesaw` pin for the encoder button. See [examples/seesaw-esp32s3-idf.yaml](examples/seesaw-esp32s3-idf.yaml) for a minimal ESP32-S3 ESP-IDF example.
