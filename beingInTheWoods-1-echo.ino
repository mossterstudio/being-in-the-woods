/*
HC-SR04 Ping distance sensor
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 9 Trig to Arduino pin 10
Red POS to Arduino pin 11
Green POS to Arduino pin 12
560 ohm resistor to both LED NEG and GRD power rail
More info at: http://goo.gl/kJ8Gl
*/

#define trigPin 9
#define echoPin 10
#define led 11
#define led2 12

long duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {

  // Clears the trigPin
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = (duration/2) / 29.1;

  // Prints the distance on the Serial Monitor
  if (distance >= 150 || distance <= 0){
    //Serial.println("Out of range");
    Serial.println("Noone");
    digitalWrite(led,HIGH);
    digitalWrite(led2,LOW);
  }
  else {
    //Serial.print(distance);
    //Serial.println(" cm");
    Serial.println("Someone");
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  delay(100);
}
