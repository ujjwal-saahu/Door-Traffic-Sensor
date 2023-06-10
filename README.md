# Visitor-Counting-System-
The Visitor Counting System is a project that utilizes Raspberry Pi, an ultrasonic sensor, ESP32, AWS, Cloud, and Fog computing to count and track the number of visitors in a specific location or area. This system provides real-time visitor counting and enables data analysis and management through cloud and fog computing technologies.

## Team Members
M11107820 - FELIX GUNAWAN​
M11115817 – UJJWAL SAHU​
M11107818 – HANIFA ZULKADRIA​
M11151011 – 柳博凱

## Hardware Components
To set up the Visitor Counting System, you will need the following hardware components:

Raspberry Pi: A single-board computer that will act as the main processing unit.
Ultrasonic Sensor: To detect the presence of visitors and measure the distance.
ESP32: A microcontroller that will communicate with the ultrasonic sensor and send data to the Raspberry Pi.
Internet Connection: To enable communication between the Raspberry Pi, ESP32, and cloud services.

## Software Requirements
You will also need to install and configure the following software:

Raspbian OS: Install the Raspbian operating system on your Raspberry Pi.
AWS Account: Sign up for an AWS account to utilize cloud services. (In my case we have used AWS Academy Learner Lab)
AWS IoT Core: Create an AWS IoT Core Thing and obtain the necessary security credentials.
AWS DynamoDB: Set up a DynamoDB table to store the visitor count data.
Arduino IDE: Install the Arduino IDE to program the ESP32.

## Usage
To use the Visitor Counting System:

Ensure that the Raspberry Pi, ESP32, and cloud services are running and properly connected.
The ultrasonic sensor will detect the presence of visitors and measure the distance.
The ESP32 will communicate the visitor count data to the Raspberry Pi.
The Raspberry Pi will process the data and send it to the AWS Lambda function.
Access the DynamoDB dashboard or retrieve the data programmatically to monitor the visitor count.
