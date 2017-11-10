--3977335 chipid
local module = {}

module.LED_PIN = 2
module.SSID = {}
module.SSID["Dougras"] = "eusouodougrasvocenaoehodougras"

module.HOST = "m11.cloudmqtt.com"
module.PORT = 16119
module.USERNAME = "node02"
module.PASSWORD = "node02"
module.ID = node.chipid()

module.ENDPOINT = "/node02"
return module
