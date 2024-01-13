#include <LiquidCrystal.h>

const int sig = 13;
const int motorPin = 9;
const int led1pin = 8;
const int buzzerpin = 10;
const int led3pin = 6;
const int led2pin = 7;


int seconds = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.

  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(led1pin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(led3pin, OUTPUT);
  pinMode(led2pin, OUTPUT);

  // Print a message to the LCD.
  lcd_1.print("    WAITING    ");
}

void loop()
{
  long duration, cm;

  pinMode(sig, OUTPUT);
  digitalWrite(sig, LOW);
  delayMicroseconds(10);
  digitalWrite(sig, HIGH);
  delayMicroseconds(20);
  digitalWrite(sig, LOW);
  pinMode(sig, INPUT);

  duration = pulseIn(sig, HIGH);
  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  if (cm < 100)
  {
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("   PROCESSING   ");
    
    for (int i = 0; i <= 6; i++) {
      if (i < 3) {
        digitalWrite(motorPin, HIGH);
    	digitalWrite(led1pin, HIGH);
      }
      
      if (i > 3) {
        digitalWrite(motorPin, LOW);
      }
        lcd_1.setCursor(0, 1);
    	// print the number of seconds since reset:
   		 lcd_1.print(seconds);
   		 delay(1000); // Wait for 1000 millisecond(s)
   		 seconds += 1;
    }
    
    for (int i = 0; i < 6; i++) {
      
         digitalWrite(led2pin, HIGH);
   		 digitalWrite(led1pin, LOW);
         lcd_1.setCursor(0, 1);
    	// print the number of seconds since reset:
   		 lcd_1.print(seconds);
   		 delay(1000); // Wait for 1000 millisecond(s)
   		 seconds += 1;
    }
    
    for (int i = 0; i < 6; i++) {
        digitalWrite(led2pin, LOW);
      	digitalWrite(led3pin, HIGH);

         lcd_1.setCursor(0, 1);
    	// print the number of seconds since reset:
   		 lcd_1.print(seconds);
   		 delay(1000); // Wait for 1000 millisecond(s)
   		 seconds += 1;
    }
    
    for (int i = 0; i < 2; i++) {
      digitalWrite(buzzerpin, HIGH);
      
      
      lcd_1.setCursor(0, 1);
    	// print the number of seconds since reset:
	  lcd_1.print(seconds);
      delay(1000); // Wait for 1000 millisecond(s)
   	  seconds += 1;
      	 
    }
    
    lcd_1.clear();
    lcd_1.setCursor(0, 1);  // Corrected line
    lcd_1.print("TQ U VISIT AGAIN");  // Corrected line
    
    
    digitalWrite(buzzerpin, LOW);
    digitalWrite(led3pin, LOW);
    delay(500);
    digitalWrite(led3pin, HIGH);
    digitalWrite(led2pin, HIGH);
    digitalWrite(led1pin, HIGH);
    delay(500);
     digitalWrite(led3pin, LOW);
      	 digitalWrite(led2pin, LOW);
     	 digitalWrite(led1pin, LOW);
    delay(500);
    digitalWrite(led3pin, HIGH);
      	 digitalWrite(led2pin, HIGH);
     	 digitalWrite(led1pin, HIGH);
    lcd_1.clear();  // Corrected line
    seconds = 0;
    digitalWrite(led3pin, LOW);
    digitalWrite(led2pin, LOW);
    digitalWrite(led1pin, LOW);
    
    delay(1000);
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("    WAITING    ");
    
  }

  else
  {
    digitalWrite(motorPin, LOW);
    digitalWrite(led1pin, LOW);
    digitalWrite(buzzerpin, LOW);
    digitalWrite(led3pin, LOW);
  }

  delay(200);
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
