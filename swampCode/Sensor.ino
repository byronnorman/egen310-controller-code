const int pump = 9;

void setup() {
 // Initialize the pump output
 pinMode(pump, OUTPUT);
}

void loop() {
  // Get sesor reading
  int sensorReading = analogRead(A0);

  // If above the defined level, turn the pump on
  if (sensorReading > 480) {
    Serial.println("Pump on");
    analogWrite(pump, 255);
  }
  
   delay(1000);  // delay between reads
}
