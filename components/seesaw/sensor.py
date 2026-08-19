import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import (
    CONF_ID,
    CONF_MAX_VALUE,
    CONF_MIN_VALUE,
    CONF_NUMBER,
    ICON_ROTATE_RIGHT,
    STATE_CLASS_NONE,
    UNIT_STEPS,
)

from . import CONF_SEESAW_ID, Seesaw, seesaw_ns

SeesawRotaryEncoder = seesaw_ns.class_(
    "SeesawRotaryEncoder", sensor.Sensor, cg.Component
)

CONFIG_SCHEMA = sensor.sensor_schema(
    SeesawRotaryEncoder,
    unit_of_measurement=UNIT_STEPS,
    icon=ICON_ROTATE_RIGHT,
    accuracy_decimals=0,
    state_class=STATE_CLASS_NONE,
).extend(
    {
        cv.GenerateID(CONF_SEESAW_ID): cv.use_id(Seesaw),
        cv.Optional(CONF_NUMBER, default=0): cv.int_range(min=0, max=3),
        cv.Optional(CONF_MIN_VALUE): cv.int_,
        cv.Optional(CONF_MAX_VALUE): cv.int_,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await sensor.register_sensor(var, config)

    seesaw = await cg.get_variable(config[CONF_SEESAW_ID])
    cg.add(var.set_parent(seesaw))
    cg.add(var.set_number(config[CONF_NUMBER]))

    if CONF_MIN_VALUE in config:
        cg.add(var.set_min_value(config[CONF_MIN_VALUE]))
    if CONF_MAX_VALUE in config:
        cg.add(var.set_max_value(config[CONF_MAX_VALUE]))
