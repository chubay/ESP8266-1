#include <Arduino.h>
#include <ESP8266WebServer.h>
#include <PubSubClient.h>
unsigned int i;
// WiFi
const char *ssid = "Chan Hung"; 
const char *password = "chanhung996"; 

// MQTT Broker
const char *mqtt_broker = "broker.hivemq.com";
const char *topic = "READ";
const char *topic1 = "WRITE";
const char *topic2 = "ANALOG";
const char *mqtt_username = "";
const char *mqtt_password = "";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);
void callback(char *topic, byte *payload, unsigned int length) {
 // Serial.print("Message arrived in topic: ");
  //Serial.println(topic);
  //Serial.print("Message:");
  for ( i = 0; i < length; i++) {
      //Serial.print((char) payload[i]);
       if ((char) payload[i] == '1')
      {
        digitalWrite(2,LOW);
        client.publish(topic1, "ON LED");
      }


      if ((char) payload[i] == '0')
      {
        digitalWrite(2,HIGH);
        client.publish(topic1, "OFF LED");
      }
      String x = String (analogRead(A0));
      client.publish(topic2,x.c_str());
      Serial.println(x.c_str());
  }
}
void setup() {
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  Serial.begin(9600);
  // connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  //connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()) {
      String client_id = "esp8266-client-";
      client_id += String(WiFi.macAddress());
      //Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
      if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
          Serial.println("Public emqx mqtt broker connected");
      } else {
          Serial.print("failed with state ");
          Serial.print(client.state());
          digitalWrite(2,HIGH);
      }
  }
 
  client.subscribe(topic);
 /*  String x = String (analogRead(A0));
      client.publish(topic2,x.c_str());
      Serial.println(x.c_str());*/
}
void loop()
{
 client.loop();
}