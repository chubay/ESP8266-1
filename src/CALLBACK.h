void callback(char *topic, byte *payload, unsigned int length) {
  for ( i = 0; i < length; i++) {
      //Serial.print((char) payload[i]);
       if ((char) payload[i] == '1')
      {
        /*digitalWrite(2,LOW);*/
      }


      if ((char) payload[i] == '0')
      {
        /*digitalWrite(2,HIGH);
        client.publish(topic1, "OFF LED");*/
      }
  }
}