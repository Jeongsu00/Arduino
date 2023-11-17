//SPI-Slave
#include<SPI.h>                 // SPI 라이브러리에서 제공하는 함수를 사용 가능하게 함
#include<string.h>

int buttonPin = 2;
int ledPin =7;
//volatile boolean received;      // volatile 휘발성 함수
volatile uint16_t slaveReceived;//, slaveSend;
int buttonValue;
uint16_t x;
int temp = 0;

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

//  temp = 0;
}

ISR(SPI_STC_vect){

  slaveReceived = SPDR;

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
