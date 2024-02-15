const int analogInputPin = A0;  // Analog pin for reading voltage levels
const float voltageThreshold = 0.06; // Set your voltage threshold here
int receivedBit = 0;            // Store the received bit
int receivedBits[9];            // Store 9 received bits to form a number
int count = 0;
int N = 10;

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 9; i++) {  // Fix the loop condition
    float receivedVoltage = analogRead(analogInputPin) * (5.0 / 1023.0); // Read voltage
    Serial.println(receivedVoltage);
    if (receivedVoltage > voltageThreshold) {
      receivedBit = 0; // Voltage is below threshold, consider it as 0
    } else {
      receivedBit = 1; // Voltage is above threshold, consider it as 1
      Serial.println("567");
    }

    receivedBits[i] = receivedBit;
    delay(1000);
  }

  // Convert the received 4-bit binary to a decimal number (0 to 15)
   decimalNumber = receivedBits[0] * 8 + receivedBits[1] * 4 + receivedBits[2] * 2 + receivedBits[3];
}

// Print the mapped number to the serial monitor
  Serial.print("Received Bits: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(receivedBits[i]);
  }
  Serial.print(" Decimal Number: ");
  Serial.println(decimalNumber);

  delay(1000); // Adjust the delay as needed
}
