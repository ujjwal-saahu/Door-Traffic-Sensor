#include <WiFi.h>
#include <PubSubClient.h>
#include <Ultrasonic.h>

const char* ssid = "Galaxy A33 5G9A9E";
const char* password =  "ywvt0455";
const char* mqttServer = "192.168.117.35";
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long previousMillis = 0;
const unsigned long interval = 10000; // 10 second interval


Ultrasonic ultrasonic2(5, 18); //(trig, echo)
Ultrasonic ultrasonic1(2, 4);

long duration1;
long duration2;
float distanceCm1;
float distanceCm2;

int ultrasonic1_status=0;
int ultrasonic2_status=0;
int people=0;
int in_state=0;
int out_state=0;
int in_timeout;
int out_timeout;
int timeout=1000000;
int distance=80;

void peoplecount(){

  distanceCm1 = ultrasonic1.read();
  if (distanceCm1<3){distanceCm1=300;}
  distanceCm2 = ultrasonic2.read();
  if (distanceCm2<3){distanceCm2=300;}

  if(distanceCm1<distance){ultrasonic1_status=1;}

  else{ultrasonic1_status=0;}

  if(distanceCm2<distance){ultrasonic2_status=1;}

  else{ultrasonic2_status=0;}

  if(ultrasonic1_status==1 && ultrasonic2_status==0 && out_state==0 && in_state==0){
    in_state=1;
    in_timeout=micros();
  }
  if(micros()-in_timeout>timeout){
    in_state=0;
  }
  if(in_state==1 && ultrasonic2_status==1){
    people++;
    delay(100);
    in_state=0;
  }

  if(ultrasonic1_status==0 && ultrasonic2_status==1 && in_state==0 && out_state==0){
    out_state=1;
    out_timeout=micros();
  }
  if(micros()-out_timeout>timeout){
    out_state=0;
  }
  if(out_state==1 && ultrasonic1_status==1){
    people--;
    delay(100);
    out_state=0;
  }

}


void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to the WiFi network");

  client.setServer(mqttServer, mqttPort);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    client.setKeepAlive(10);
    // if (client.connect("ESP32Client")) {
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");  
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
  
  client.publish("testTopic", "Hello from ESP32");
}
void mqttpublish(){
  if (client.connected()) {
  String payload = "1 people= " + String(people);
  client.publish("esp32/test", payload.c_str());
  // client.publish("esp32/test", "Hello from ESP32(2)");
  }
}
void print_readings(){
    Serial.print("distanceCm1 = ");
    Serial.print(distanceCm1);
    Serial.print("  | distanceCm2 = ");
    Serial.print(distanceCm2);
    Serial.print("  | ultrasonic1_status = ");
    Serial.print(ultrasonic1_status);
    Serial.print("  | ultrasonic2_status = ");
    Serial.print(ultrasonic2_status);
    Serial.print("  | people = ");
    Serial.println(people);
}
void loop() {

  peoplecount();
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    mqttpublish();
    // print_readings();
  }
  print_readings();
  delay(100);
}
