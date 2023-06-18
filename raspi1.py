import sys
print(sys.version)

from AWSIoTPythonSDK.MQTTLib import AWSIoTMQTTClient
import logging
import time
import argparse
import json
import paho.mqtt.client as mqtt

host = "a34bliikezz80j-ats.iot.us-east-1.amazonaws.com"
rootCAPath = "AmazonRootCA1.pem"
certificatePath = "device certificate.crt"
privateKeyPath = "private.pem.key"
clientId = "sdk-python"
topic = "sdk/test/python"

myAWSIoTMQTTClient = AWSIoTMQTTClient(clientId)
myAWSIoTMQTTClient.configureEndpoint(host, 8883)
myAWSIoTMQTTClient.configureCredentials(rootCAPath, privateKeyPath, certificatePath)

myAWSIoTMQTTClient.connect()

def on_connect(client, userdata, flags, rc):
    print(f"Connected with result code {rc}")
    client.subscribe("esp32/test")

def on_message(client, userdata, message):
    print("Received message '" + str(message.payload) + "' on topic '"
          + message.topic + "' with QoS " + str(message.qos))

    # Decode bytes payload to string
    decoded_payload = message.payload.decode()

    # Create a JSON object from the decoded payload
    json_payload = json.dumps({"message": decoded_payload})

    # Publish received payload to AWS IoT
    myAWSIoTMQTTClient.publish(topic, json_payload, 0)
    print('message sent')

mqtt_client = mqtt.Client()
mqtt_client.on_connect = on_connect
mqtt_client.on_message = on_message

mqtt_client.connect("localhost", 1883, 60)

# Blocking call that processes network traffic, dispatches callbacks and
# handles reconnecting.
mqtt_client.loop_forever()

#message = {}
#message['message'] = 'Hello, World!'
#message['sequence'] = 1
#messageJson = json.dumps(message)


#import time

#while True:  # Run forever
    
#    myAWSIoTMQTTClient.publish(topic, messageJson, 1)
#    print("message sent")
#    time.sleep(1)


#myAWSIoTMQTTClient.publish(topic, messageJson, 1)

#myAWSIoTMQTTClient.disconnect()
