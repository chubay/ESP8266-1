/*unsigned int i;
// WiFi
const char *ssid = "Chan Hung"; 
const char *password = "chanhung996"; */
// MQTT Broker
const char *mqtt_broker = "broker.hivemq.com";
const char *topic = "READ";
const char *topic1 = "NGAY";
const char *topic2 = "THANG";
const char *topic3 = "NAM";
const char *topic4 = "NHIETDO";
const char *topic5 = "GIO";
const char *topic6 = "PHUT";
const char *topic7 = "GIAY";
const char *topic8 = "DOAM";
const char *mqtt_username = "";
const char *mqtt_password = "";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);