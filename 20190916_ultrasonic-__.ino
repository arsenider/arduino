#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C mylcd (0x27, 16, 2);

void setup() {
  mylcd.init();
  mylcd.backlight();
  Serial.begin (9600);
  pinMode (4, INPUT);   //echo pin
  pinMode (5, OUTPUT);  //trigger pin
  pinMode (6, OUTPUT);  //buzzer
}

int distance;

void display()
{
  mylcd.setCursor (0, 0);
  mylcd.print ("dist : ");
  mylcd.print (distance);
  mylcd.print ("Cm");
}

void loop() {
  digitalWrite (5, HIGH);
  delayMicroseconds(10);
  digitalWrite (5, LOW);

  distance = pulseIn (4, HIGH) / 58;
  
  display();



  if (distance < 50 && distance > 40)      //&&  and    50 > distance > 40  X
  {
    display();
    digitalWrite (6, HIGH);
    delay(500);
    digitalWrite (6, LOW);
    delay(500);
  }
  else if (distance < 40 && distance > 30)
  {
    display();
    digitalWrite (6, HIGH);
    delay(250);
    digitalWrite (6, LOW);
    delay(250);
  }
  else if (distance < 30 && distance > 20)
  {
    display();
    digitalWrite (6, HIGH);
    delay(125);
    digitalWrite (6, LOW);
    delay(125);
  }
  else if (distance < 20 && distance > 10)
  {
    display();
    digitalWrite (6, HIGH);
    delay(63);
    digitalWrite (6, LOW);
    delay(63);
  }
  else if (distance < 10)
  {
    display();
    digitalWrite (6, HIGH);
   
  }
  else
  {
    display();
    digitalWrite (6, LOW);
  }
  delay(200);
  mylcd.clear();
  
}
