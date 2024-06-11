/*
    Project name : Piezoelectric Sensor
    Modified Date: 11-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-piezoelectric-sensor
*/

const int piezoPin = A0; // Analog pin connected to the piezoelectric sensor

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the voltage value from the piezoelectric sensor
  int sensorValue = analogRead(piezoPin);
  
  // Print the sensor value to the serial monitor
  Serial.print("Piezoelectric Sensor Value: ");
  Serial.println(sensorValue);
  
  // Check if a tap or knock is detected
  if (detectTap(sensorValue)) {
    Serial.println("Tap detected!");
  }
  
  // Add a delay before taking the next reading
  delay(1000);
}

bool detectTap(int value) {
  // Define a threshold value for detecting taps
  const int tapThreshold = 100;
  
  // Check if the sensor value exceeds the tap threshold
  return value > tapThreshold;
}
