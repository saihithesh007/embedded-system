/*
  HC-SR04 Ultrasonic Sensor with Arduino UNO

  Connections:
  VCC  -> 5V
  GND  -> GND
  TRIG -> D10
  ECHO -> D9
*/

#define TRIG_PIN 10
#define ECHO_PIN 9

long duration;
float distance;

void setup()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);
  Serial.println("HC-SR04 Ultrasonic Sensor");
}

void loop()
{
  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send a 10 µs pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo pulse duration
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance (cm)
  distance = duration * 0.0343 / 2;

  // Display distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
