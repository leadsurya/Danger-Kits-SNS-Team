// C++ code
//
int distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  distance = 0.01723 * readUltrasonicDistance(5, 4);
  Serial.println(distance);
  if (distance <= 35) {
    digitalWrite(6, HIGH);
    digitalWrite(3, LOW);
  } else {
    digitalWrite(6, LOW);
    digitalWrite(3, HIGH);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
