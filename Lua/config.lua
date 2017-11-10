--3977335 chipid
local module = {}

module.EMISSOR_PIN = 4
module.READER_PIN = 9
module.SSID = {}
module.SSID["Dougras"] = "eusouodougrasvocenaoehodougras"
--module.SSID["UFLA+"] = ""

module.HOST = "m11.cloudmqtt.com"
module.PORT = 16119
module.USERNAME = "node01"
module.PASSWORD = "node01"
module.ID = node.chipid()

module.ENDPOINT = "/node01"--..node.chipid()
return module
