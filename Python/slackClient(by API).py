# CTEC 121 / Intro to Programming and Problem Solving
# Lab - Using the Slack API
# by Bruce Elgort, 2016
 
# pip install slackclient to install SlackClient library
from slackclient import SlackClient
import channel
import im
import user
import util
import version 
import client
import server
import slackrequest
import json
 
def test_slack(sc):         #DEBUG
    print("Testing API...")
    print (sc.api_call('api.test'))
 
def get_channel_info(sc,channel):
    print("Getting Channel Info...")
    print (sc.api_call('channels.info', channel=channel))
 
def get_list_of_channels(sc):
    print("Getting List of Channels...")
    channels = sc.api_call('channels.list')
    channels = json.dumps(channels)
    channels = json.loads(str(channels))
    return channels
 
def display_channels(channels):
    print("Display Channels:")
    for i in channels['channels']:
        print("Channel:"+i['name']+" ID:"+i['id'])
 
def post_message(sc,text,channel,icon_url,username):
    print("Posting Message to Slack...")
    print (sc.api_call('chat.postMessage',channel=channel,text=text,username=username,icon_url=icon_url,unfurl_links='true'))
 
def get_users(sc):
    print("Get Users")
    print("80 * =")
    #call the users.list api call and get list of users
    users = (sc.api_call('users.list'))
    users = json.dumps(users)
    users = json.loads(str(users))
    return users
 
def display_users(sc,users):
    print("User List")
    print("80 * =")
    # display active users
    for i in users['members']:
        # don't display slackbot
        if i['profile']['real_name'] != 'slackbot':
            # don't display deleted users
            if not i['deleted']:
                # display real name
                print (i['profile']['real_name'].encode('utf-8') + " " + i['id'].encode('utf-8'))
def main():
    # define variables
    token = "xoxp-262082926544-262788675828-264168445702-d81a37c8cb377f0a1f653657c7cad837"
    channel = "C7Q2ETC8G"
    username = "ESP"
    icon_url = "http://lorempixel.com/48/48"
    dm = "U7QP6KVQC"
    # connect to Slack
    sc = SlackClient(token)
    # test slack
    test_slack(sc)
    # get channel info
    get_channel_info(sc,channel)
    # get list of channels
    channels = get_list_of_channels(sc)
    # display channels
    display_channels(channels)
    # post message
  #  post_message(sc,"Visit http://slack.com",channel,icon_url,username)
    post_message(sc,"Visit http://slack.com",dm,icon_url,username)
    # get users
    users = get_users(sc)
    # display users
    display_users(sc,users)
 
main()