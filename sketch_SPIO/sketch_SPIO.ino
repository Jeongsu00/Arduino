//SPI-Slave
#include<SPI.h>                 // SPI 라이브러리에서 제공하는 함수를 사용 가능하게 함

int buttonPin = 2;
int ledPin =7;
volatile boolean received;      // volatile 휘발성 함수
volatile byte slaveReceived, slaveSend;
int buttonValue;
int x;

void setup()
{
  Serial.begin(1000000);
//  pinMode(ledPin, OUTPUT);
//  pinMode(buttonPin, INPUT);
  pinMode(MISO, OUTPUT);
  SPCR |=_BV(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR|=_BV(SPIE);
  received=false;
}

ISR(SPI_STC_vect){

  slaveReceived = SPDR;
  Serial.println(slaveReceived);
      if (slaveReceived==1) 
      {
        digitalWrite(ledPin,HIGH);         
        Serial.println("Slave LED ON");
      }else
      {
        digitalWrite(ledPin,LOW);          
        Serial.println("Slave LED OFF");
      }
      
      buttonValue = digitalRead(buttonPin);  
      // if (buttonValue == LOW)              
      //   x=1;
        
      // }else
      // {
      //   x=0;
      // }
      
      // slaveSend=x;                             
      // SPDR = slaveSend; 
}

void loop()
{
                          
}