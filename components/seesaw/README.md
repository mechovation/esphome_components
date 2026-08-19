# Seesaw

ESPHome component for the Adafruit seesaw rotary encoder board.

Define each I2C seesaw device under `seesaw`, then reference it from the encoder sensor, button binary sensor, and NeoPixel light with `seesaw_id`.

```yaml
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

Optional fields:

- `sensor.number`: rotary encoder number, default `0`
- `sensor.min_value`: optional minimum published encoder value
- `sensor.max_value`: optional maximum published encoder value
- `binary_sensor.pin`: button pin, default `24`
- `binary_sensor.inverted`: button active-low handling, default `true`
- `light.pin`: NeoPixel pin, default `6`
