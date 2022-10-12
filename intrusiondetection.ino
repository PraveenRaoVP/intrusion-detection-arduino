const int trigPin = 8; 
const int echoPin = 7;
const int led = 10;

const int speaker = 3;
//GND - POWER GND
//VCC - VIN
// Trig - 8
// Echo - 7
// LED + - 10
// LED - = GND


long duration;
long distance;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led,OUTPUT);
  pinMode(speaker, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delay(5);

  digitalWrite(trigPin, HIGH);
  delay(50);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;




  if(distance<10) {
    digitalWrite(led,HIGH);
    tone(speaker, 1000,1000);
    //delay(500);
    tone(speaker, 1500,1000);
    //delay(500);
    tone(speaker, 1000,1000);
    //delay(500);
    tone(speaker, 1500,1000);
    //delay(500);
  } else
  if(distance<50) {
    digitalWrite(led,HIGH);
    tone(speaker, 1000,1000);
    digitalWrite(led,LOW);
    delay(distance*10);
    tone(speaker, 1500,1000);
    digitalWrite(led,HIGH);
    delay(distance*10);
    tone(speaker, 1000,1000);
    digitalWrite(led,LOW);
    delay(distance*10);
    tone(speaker, 1500,1000);
    digitalWrite(led,HIGH);
    delay(distance*10);
    
    //delayMicroseconds(10);
  } 
   else{
    digitalWrite(led, LOW);
  }

  Serial.print("Distance : ");
  Serial.println(distance);
  Serial.print("Delay: ");
  Serial.print(distance*10);
}