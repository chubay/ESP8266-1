#include <Arduino.h>
#include <ESP8266WebServer.h>
#include <PubSubClient.h>
unsigned int i;
// WiFi
const char *ssid = "Chan Hung"; 
const char *password = "chanhung996"; 
#include "BROKER_TOPIC.h"
#include "CALLBACK.h"
#include "SETUP.h"
#include "READ_WRITE.h"
void setup() 
 {
   MO_DAU();
 }
void loop()
{
  PUSH();
   client.loop();
}