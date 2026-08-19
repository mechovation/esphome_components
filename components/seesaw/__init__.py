import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c
from esphome.const import CONF_ID

CODEOWNERS = ["@mechovation"]
MULTI_CONF = True

seesaw_ns = cg.esphome_ns.namespace("seesaw")
Seesaw = seesaw_ns.class_("Seesaw", i2c.I2CDevice, cg.Component)

CONF_SEESAW_ID = "seesaw_id"

CONFIG_SCHEMA = cv.COMPONENT_SCHEMA.extend(
    {
        cv.GenerateID(): cv.declare_id(Seesaw),
    }
).extend(i2c.i2c_device_schema(0x37))

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await i2c.register_i2c_device(var, config)
