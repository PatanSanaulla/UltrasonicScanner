int trigPin = 4;
int echoPin = 3;
const int pinServo = 10;
int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(pinServo, OUTPUT);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    //Serial.print(pos);
    angle(pos);              // tell servo to go to position in variable 'pos'
    dist();                  // Calculate the distance to the nearest object
    delay(15);               // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    //Serial.print(pos);
    angle(pos);              // tell servo to go to position in variable 'pos'
    dist();                  // Calculate the distance to the nearest object
    delay(15);               // waits 15ms for the servo to reach the position
  }
}

void angle(int a){
  int highDur, lowDur;
  highDur = map(a, 0, 180, 500, 2600);
  lowDur = 20000 - highDur;

  digitalWrite(pinServo, HIGH);
  delayMicroseconds(highDur);
  digitalWrite(pinServo, LOW);
  delayMicroseconds(lowDur);
}

  
void dist(){
  long dur, dist = -1;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  dur = pulseIn(echoPin, HIGH);
  dist = (dur/2) * 0.0343;

  if(dist >= 200){
    Serial.println("Out of range");
    //Serial.println(" No"); //Print No obstacle near a range of 200 cms at the particular angle.
  }else{
    Serial.print(dist);
    Serial.println(" cm");
    //Serial.println(" Yes"); //Print obstacle within a range of 200 cms at the particular angle.
  }
}
