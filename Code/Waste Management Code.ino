#include<SoftwareSerial.h>

#define trigPin 8

#define echoPin 7

SoftwareSerial mySerial(10, 11);

int normalDistance=3;

boolean triggered = false;

long duration, distance;

void setup()

{

mySerial.begin(9600);

Serial.begin (9600);

delay(100);

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

long duration, distance;

while (millis() < 5000)

{

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;

Serial.print("Distance: ");

Serial.println(distance);


} }

void loop()

{

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;

Serial.print("Distance: ");

Serial.println(distance);

if (distance < normalDistance)

{

triggered = true;
Serial.println("Message Sent!");
delay(1000);

}

else

{

triggered = false;

}

if (triggered)

{

delay(250);

mySerial.println("AT+CMGF=1");

//Sets the GSM Module in Text Mode

delay(1000);

// Delay of 1000 milli seconds or 1 second 
mySerial.println("AT+CMGS=\"+919497087143\"\r");

// Replace x with mobile number

delay(1000);

mySerial.println("I am SMS from GSM Module");

// The SMS text you want to send delay(100);

mySerial.println((char)26);

// ASCII code of CTRL+Z

delay(1000);

} }
