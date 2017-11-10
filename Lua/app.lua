local module = {}
m = nil
-- Envia um ping ao broker
local function send_ping()
    m:publish(config.ENDPOINT .."/rele/fromnode",gpio.read(config.READER_PIN),0,1)
    print("Status publicado!")
end

local function consume_data( payload )
  --Faz alguma coisa com o valor de payload e envia resposta
    send_ping()
end
-- Envia o ID para broker para registra-lo
local function register_myself()
    m:subscribe(config.ENDPOINT.."/rele/tonode", 0,function(conn)
     print("subscribe success")
    end)
    send_ping()
end

local function ligar_LED(condicao)
    if condicao == "desliga" then
        gpio.write(config.EMISSOR_PIN, gpio.HIGH)
    end
    if condicao == "liga" then
        gpio.write(config.EMISSOR_PIN, gpio.LOW)
    end
end

local function mqtt_start()
    m = mqtt.Client(config.ID, 120,config.USERNAME,config.PASSWORD)
    -- Função on que recebe "connect" como parametro. Realiza algo ao conectar ao criar o client
    m:on("connect", function(conn)
      print("subscribe ok!")
      register_myself()
    end)
    -- Função on que recebe "message" como parametro. Realiza algo ao receber uma mensagem
    m:on("message", function(conn, topic, data)
      if data ~= nil then
        print(topic .. ": " .. data)
        consume_data(data)
        ligar_LED(data)
        if data == "liga" then 
            print("Ligar relé")
        end
        if data == "desliga" then
            print("Desligar relé")
        end
      end
    end)
    -- Conecta ao broker
    m:connect(config.HOST, config.PORT, 0, 1, function(conn)
        register_myself()
    end)
end

function module.start()
  mqtt_start()
end

return module
-- ID do ESP8266 = 3977335
