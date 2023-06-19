# Gate-Traffic-Sensor
The Gate Traffic Sensor is a project that utilizes Raspberry Pi, an ultrasonic sensor, ESP32, and AWS to count and track the number of visitors in a specific location or area. This system provides real-time visitor counting and enables data analysis and management through cloud and fog computing technologies.

The ESP32-based people counters (with ultrasonic modules)
The Raspberry Pi 3 acting as a gateway to Amazon AWS
The web interface to view the data

## Team Members
@M11107820 - FELIX GUNAWAN​

@M11115817 – UJJWAL SAHU​

@M11107818 – HANIFA ZULKADRIA​

@M11151011 – 柳博凱

## Hardware Components
To set up the Gate Traffic Sensor, you will need the following hardware components:

Ultrasonic Sensor-4pc

ESP32-2pc

PCB-2pc

Raspbarry Pi 3B

Jumpper Wire

Power Adapter

Raspberry Pi: A single-board computer that will act as the main processing unit.
![image](https://github.com/ujjwal-saahu/Visitor-Counting-System-/assets/106102738/6205559a-975e-41d4-a79b-3aebf232632e)


Ultrasonic Sensor: To detect the presence of visitors and measure the distance.
![image](https://github.com/ujjwal-saahu/Visitor-Counting-System-/assets/106102738/166ff912-5556-45fd-a3c7-9598b9421703)


ESP32: A microcontroller that will communicate with the ultrasonic sensor and send data to the Raspberry Pi.
![image](https://github.com/ujjwal-saahu/Visitor-Counting-System-/assets/106102738/35a46551-4042-42a1-ac2e-b1472016bc95)


Internet Connection: To enable communication between the Raspberry Pi, ESP32, and cloud services.

## Software Requirements
You will also need to install and configure the following software:

**Raspbian OS:** Install the Raspbian operating system on your Raspberry Pi.

Prepare the SD Card:

Insert the SD card into your computer's SD card reader.
Download the Raspbian OS image from the official Raspberry Pi website.
Use Etcher or a similar tool to write the Raspbian image to the SD card.

Configure the Raspberry Pi:

Connect a keyboard, mouse, and display to the Raspberry Pi.
Insert the prepared SD card into the Raspberry Pi's SD card slot.
Connect the power supply to boot up the Raspberry Pi.

Install Raspbian:

Follow the on-screen instructions to complete the initial setup, including language, time zone, password, and Wi-Fi configuration.

Complete the Setup:

After the initial setup, the Raspbian desktop will appear.

**AWS Account:** Sign up for an AWS account to utilize cloud services. (In my case we have used AWS Academy Learner Lab)

**AWS IoT Core:** Create an AWS IoT Core Thing and obtain the necessary security credentials.

we will register your Raspberry Pi as a thing in AWS IoT Core.

Log into AWS Console and navigate to the AWS IoT Core service.

In the left navigation pane, click on Manage > Things.

Click "Create" button to create a new Thing, follow the steps to complete the Thing creation process.

After the Thing is created, you'll be able to create security credentials (certificates) for it. Download these credentials to your Raspberry Pi.

**Arduino IDE:** Install the Arduino IDE to program the ESP32.

**WIX:** WIX is a user-friendly platform for creating professional websites without coding


## Follow These Steps-

## Step 1: Configure the Raspberry Pi Gateway

The Raspberry Pi will act as a gateway, which is essentially an intermediary device that communicates with the ESP32 devices, collects their data, and uploads it to AWS.

**Establish a communication protocol between the Raspberry Pi and the ESP32 devices:** We can use MQTT (Message Queuing Telemetry Transport) because that  MQTT is a popular choice for IoT applications due to its lightweight nature, scalability, and flexibility, making it well-suited for communication between Raspberry Pi and ESP32 devices in an IoT ecosystem.

**Set up an AWS IoT Core service:** This will allow your Raspberry Pi to securely connect to AWS and transmit data. AWS IoT Core supports MQTT, which should align well with your ESP32 devices. You will have to register your Raspberry Pi as a "Thing" in the AWS IoT console, which will allow AWS to recognize and trust it.

**Install and configure the AWS IoT SDK on the Raspberry Pi:** This will allow your Raspberry Pi to interact with the AWS IoT Core service.


## Step 2: Configure the AWS Service

You would need to configure AWS to receive and store the data from your Raspberry Pi.

Set up a DynamoDB table: DynamoDB is a NoSQL database service from AWS that will allow you to store and retrieve the data sent from your Raspberry Pi.

Create an AWS IoT Rule to store data in DynamoDB: AWS IoT Rules allow you to process and act upon data sent to AWS IoT Core. In this case, you would create a rule that takes the data sent from your Raspberry Pi and stores it in your DynamoDB table.

## Step 3: Create the Web Interface

This is where you will view the data.
We create our web interface using wix and display our data in monitor tab. There we can monitor how many people currently in the room 


## Circuit Diagram
![image](https://github.com/ujjwal-saahu/Visitor-Counting-System-/assets/106102738/c827a0dd-5df3-4198-9429-66158e5d94c0)

## Cloud Architecture
![image](https://github.com/ujjwal-saahu/Visitor-Counting-System-/assets/106102738/ad6a7102-f9fd-48a8-9104-d83f3730f58c)



## Usage
To use the Gate Traffic Sensor:

Ensure that the Raspberry Pi, ESP32, and cloud services are running and properly connected.

The ultrasonic sensor will detect the presence of visitors and measure the distance.

The ESP32 will communicate the visitor count data to the Raspberry Pi.

The Raspberry Pi will process the data and send it to IoT Core than AWS Lambda function.

Access the DynamoDB dashboard or retrieve the data programmatically to monitor the visitor count.

Reflect the graph data through AWS S3 on WIX 

## Benefits of a Gate traffic system :
Understanding foot traffic patterns and peak hours.

Evaluating marketing and promotional campaigns.

Optimizing staffing and resource allocation.

Enhancing security and safety measures.

## Demo Video
I hope you have enjoyed this article. Lastly, I left you this demo video where you can see in action the complete flow. For this case, I used a real tiime visitor counting, and the sensor data is reflect to the WIX.

https://github.com/ujjwal-saahu/Door-Traffic-Sensor/assets/106102738/ece5a3f0-c143-4a3a-976c-5035e9938b67

