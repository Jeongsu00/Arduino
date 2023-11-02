#include <stdio.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(3, 2); 

char BluetoothData;

void setup() {
  pinMode(8, OUTPUT);    //HC-05
  digitalWrite(8,HIGH);
  Serial.begin(38400);
  BTSerial.begin(38400);
  // Serial.println("ATcommand");  //ATcommand Start
}

void loop() {

  if (BTSerial.available()){
    Serial.write(BTSerial.read());
    BluetoothData=BTSerial.read();
      if(BluetoothData='b'){
        digitalWrite(8,LOW);
        delay(1000);
        digitalWrite(8,HIGH);
      }
      else if(BluetoothData='a'){
        digitalWrite(8,LOW);
      }
//  if (Serial.available())
//    BTSerial.write(Serial.read());
  }
}
