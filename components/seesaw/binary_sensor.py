import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import CONF_ID, CONF_INVERTED, CONF_PIN

from . import CONF_SEESAW_ID, Seesaw, seesaw_ns

SeesawButton = seesaw_ns.class_("SeesawButton", binary_sensor.BinarySensor, cg.Component)

CONFIG_SCHEMA = binary_sensor.binary_sensor_schema(SeesawButton).extend(
    {
        cv.GenerateID(CONF_SEESAW_ID): cv.use_id(Seesaw),
        cv.Optional(CONF_PIN, default=24): cv.int_range(min=0, max=31),
        cv.Optional(CONF_INVERTED, default=True): cv.boolean,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await binary_sensor.register_binary_sensor(var, config)

    seesaw = await cg.get_variable(config[CONF_SEESAW_ID])
    cg.add(var.set_parent(seesaw))
    cg.add(var.set_pin(config[CONF_PIN]))
    cg.add(var.set_inverted(config[CONF_INVERTED]))
