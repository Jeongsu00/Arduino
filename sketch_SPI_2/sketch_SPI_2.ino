//SPI-Slave
#include<SPI.h>                 // SPI 라이브러리에서 제공하는 함수를 사용 가능하게 함

int buttonPin = 2;
int ledPin =7;
volatile boolean received;      // volatile 휘발성 함수
volatile uint8_t slaveReceived, slaveSend;
int buttonValue;
uint8_t x;
int temp;

void setup()
{
  Serial.begin(1000000);

  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);
  pinMode(SCK, INPUT);
  pinMode(SS, INPUT);
  SPI.setClockDivider(SPI_CLOCK_DIV16);

  SPCR |=_BV(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR|=_BV(SPIE);
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  temp = 0;
}

ISR(SPI_STC_vect){

  slaveReceived = SPDR;

    if (slaveReceived == 100){
      Serial.println(slaveReceived);
      digitalWrite(ledPin,HIGH);         
      Serial.println("Slave LED ON");
    }

    else if(slaveReceived == 110){
      Serial.println(slaveReceived);
      digitalWrite(ledPin,LOW);     
      Serial.println("Slave LED OFF");
    }

    buttonValue = digitalRead(buttonPin);
    if (buttonValue == HIGH){              
      temp += 1;
      if(temp == 1){
        x = 0x01;
        Serial.println(x);
      }
      else if(temp == 2){
        x = 0xFF;
        Serial.println(x);
        temp = 0;        
      }
    _delay_ms(200);
    }
                                 
    SPDR = x;
}

void loop()
{
                          
}