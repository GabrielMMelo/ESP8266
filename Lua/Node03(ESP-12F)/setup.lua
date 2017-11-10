local module = {}

gpio.mode(config.LED_PIN,gpio.OUTPUT)

local function wifi_wait_ip()
  if wifi.sta.getip() == nil then
    print("IP indisponivel, esperando...")
  else
    tmr.stop(1)
    print("\n====================================")
    print("ESP8266 modo: " .. wifi.getmode())
    print("Chip ID: "..node.chipid());
    print("Endereço MAC: " .. wifi.ap.getmac())
    print("IP: "..wifi.sta.getip())
    print("====================================")
    app.start()
  end
end

local function wifi_start(list_aps)
    if list_aps then
        for key,value in pairs(list_aps) do
            if config.SSID and config.SSID[key] then
                wifi.setmode(wifi.STATION);
                wifi.sta.config(key,config.SSID[key])
                wifi.sta.connect()
                print("Conectando a " .. key .. " ...")
                --config.SSID = nil  -- can save memory
                tmr.alarm(1, 2500, 1, wifi_wait_ip)
            end
        end
    else
        print("Erro ao pegar lista de AP")
    end
end

function module.start()
  print("Configurando Wifi ...")
  wifi.setmode(wifi.STATION);
  wifi.sta.getap(wifi_start)
end

return module
