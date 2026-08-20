# Seesaw

ESPHome component for the Adafruit seesaw rotary encoder board.

Define each I2C seesaw device under `seesaw`, then reference it from the encoder sensor, button binary sensor, and NeoPixel light with `seesaw_id`.

```yaml
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

Optional fields:

- `sensor.number`: rotary encoder number, default `0`
- `sensor.min_value`: optional minimum published encoder value
- `sensor.max_value`: optional maximum published encoder value
- `light.pin`: NeoPixel pin, default `6`
- `light.num_leds`: number of NeoPixels, default `1`

Use ESPHome's `gpio` binary sensor platform with a `seesaw` pin for the encoder button.
