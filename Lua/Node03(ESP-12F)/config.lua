--3977335 chipid
local module = {}

module.LED_PIN = 2
module.SSID = {}
module.SSID["Dougras"] = "eusouodougrasvocenaoehodougras"
module.HOST = "m11.cloudmqtt.com"
module.PORT = 16119
module.USERNAME = "node03"
module.PASSWORD = "node03"
module.ID = node.chipid()

module.ENDPOINT = "/node03"
return module
