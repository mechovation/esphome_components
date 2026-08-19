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
    address: 0x37

sensor:
  - platform: seesaw
    name: "Black Encoder"
    seesaw_id: ss_black

binary_sensor:
  - platform: seesaw
    name: "Black Encoder Button"
    seesaw_id: ss_black

light:
  - platform: seesaw
    name: "Black Encoder NeoPixel"
    seesaw_id: ss_black
```

The Adafruit rotary encoder board defaults are used when omitted:

- Encoder number: `0`
- Button pin: `24`
- Button inverted: `true`
- NeoPixel pin: `6`

See [examples/vandemo-idf.yaml](examples/vandemo-idf.yaml) for a three-encoder ESP32-S3 example.
