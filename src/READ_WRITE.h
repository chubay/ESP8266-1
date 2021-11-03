//#include <Arduino.h>
//#include <PubSubClient.h>
String ngay;
String thang ;
String nam ;
String nhietdo ;
String gio ;
String phut ;
String giay ;
String doam ;
void READDATA()
{
    ngay = Serial.readStringUntil('\n');
    thang = Serial.readStringUntil('\n');
    nam = Serial.readStringUntil('\n');
    nhietdo = Serial.readStringUntil('\n');
    gio = Serial.readStringUntil('\n');
    phut = Serial.readStringUntil('\n');
    giay = Serial.readStringUntil('\n');
    doam = Serial.readStringUntil('\n');
}
void PUSH()
{
    READDATA();
     client.publish(topic1,ngay.c_str());
     client.publish(topic2,thang.c_str());
     client.publish(topic3,nam.c_str());
     client.publish(topic4,nhietdo.c_str());
     client.publish(topic5,gio.c_str());
     client.publish(topic6,phut.c_str());
     client.publish(topic7,giay.c_str());
     client.publish(topic8,doam.c_str());
     //client.subscribe(topic);
}