int mq6Pin = A0;   // MQ-6 analog pin connected to A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(mq6Pin);

  Serial.print("MQ6 Sensor Value: ");
  Serial.println(sensorValue);

  delay(1000);   // 1-second delay
}
