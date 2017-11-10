

import network
import urequests
import time
from machine import Pin

def wifi_connect(ssid, pwd):
    """
    Connect to a wifi 'ssid' with password 'pwd'
    """

    sta_if = network.WLAN(network.STA_IF)
    ap_if = network.WLAN(network.AP_IF)
    if ap_if.active():
        ap_if.active(False)
    if not sta_if.isconnected():
        print('connecting to network...')
        sta_if.active(True)
        sta_if.connect(ssid, pwd)
        while not sta_if.isconnected():
            pass
    return 'IP address: %s' % sta_if.ifconfig()[0]

def to_slack(slack_hook_url, slack_icon_url, slack_message, slack_username):
    """
    Send the 'slack_message' using an incoming webhook
    """
    data = {
            "link_names": 1,
            "icon_url": slack_icon_url,
            "username": slack_username,
            "text": slack_message
           }
    res = urequests.post(slack_hook_url, json=data)
    return res.status_code == 200


if __name__ == "__main__":

    SSID = "Dougras"
    pwd = "eusouodougrasvocenaoehodougras"
    slack_hook_url = "https://hooks.slack.com/services/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"
    slack_icon_url = "https://pbs.twimg.com/profile_images/1462227900/cda288d94c3e99d0ccc4e8d1c61d7073_normal.jpg"
    slack_message = "#GoEMakers - mensagem enviada pelo ESP8266"
    slack_username = "esp_milgrau"
    led_pin = 0 # D3
    button_pin = 12 #D6

    wifi_connect(SSID, pwd)

    led = Pin(led_pin, Pin.OUT)
    button = Pin(button_pin, Pin.IN, Pin.PULL_UP)

    while True:       
        ok = to_slack(slack_hook_url, slack_icon_url, slack_message, slack_username)
        # If succeed, light the LED during 1s
        if ok:
            print("Succeeded posting to Slack")
            time.sleep(1)
        time.sleep_ms(15000)