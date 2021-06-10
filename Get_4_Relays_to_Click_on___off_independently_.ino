#include <LowPower.h>
#include <avr/sleep.h>
#include <avr/power.h>
const int ledPin = LED_BUILTIN;
const byte Relay1 = 7;
const byte Relay2 = 6;
const byte Relay3 = 5;
const byte Relay4 = 4;
int ledState = LOW;
int Relay1State = LOW;
int Relay2State = HIGH;
int Relay3State = LOW;
int Relay4State = HIGH;
unsigned long previousTimeLED = 0;
unsigned long previousTime1 = 0;
unsigned long previousTime2 = 0;
unsigned long previousTime3 = 0;
unsigned long previousTime4 = 0;
const unsigned long eventIntervalLED = 1000;
const unsigned long eventInterval1 = 1500;
const unsigned long eventInterval2 = 1000;
const unsigned long eventInterval3 = 500;
const unsigned long eventInterval4 = 2000;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  digitalWrite(Relay1, Relay1State);
  digitalWrite(Relay2, Relay2State);
  digitalWrite(Relay3, Relay3State);
  digitalWrite(Relay4, Relay4State);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  if (currentTime - previousTimeLED >= eventIntervalLED) {
    previousTimeLED = currentTime;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    } digitalWrite(ledPin, ledState);
  }


  if (currentTime - previousTime1 >= eventInterval1) {
    previousTime1 = currentTime;
    if (Relay1State == LOW) {
      Relay1State = HIGH;
    } else {
      Relay1State = LOW;
    }
    
    digitalWrite(Relay1, Relay1State);
  }

  if (currentTime - previousTime2 >= eventInterval2) {
    previousTime2 = currentTime;
    if (Relay2State == HIGH) {
      Relay2State = LOW;
    } else {
      Relay2State = HIGH;
    }
  
    digitalWrite(Relay2, Relay2State);
  }

  if (currentTime - previousTime3 >= eventInterval3) {
    previousTime3 = currentTime;
    if (Relay3State == LOW) {
      Relay3State = HIGH;
    } else {
      Relay3State = LOW;
    }
    
    digitalWrite(Relay3, Relay3State);
  }

  if (currentTime - previousTime4 >= eventInterval4) {
    previousTime4 = currentTime;
    if (Relay4State == HIGH) {
      Relay4State = LOW;
    } else {
      Relay4State = HIGH;
    }
    
    digitalWrite(Relay4, Relay4State);

  }
  Serial.println("Arduino:- I am going for a Nap");
  delay(200);
  
  LowPower.idle(SLEEP_1S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, 
                 SPI_OFF, USART0_OFF, TWI_OFF);
  Serial.println("Arduino:- Hey I just Woke up");
  Serial.println("");
  delay(500);
}
