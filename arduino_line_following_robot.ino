// Pin definitions
const int LDRLeftPin = A0;  // LDR for left side
const int LDRRightPin = A1; // LDR for right side
const int motor1Pin1 = 9;   // Motor 1 Pin 1 (forward)
const int motor1Pin2 = 10;  // Motor 1 Pin 2 (backward)
const int motor2Pin1 = 6;   // Motor 2 Pin 1 (forward)
const int motor2Pin2 = 5;   // Motor 2 Pin 2 (backward)

// Threshold for light intensity difference
const int threshold = 500;

void setup() {
  // Set motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  
  // Initialize serial monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Read values from LDRs
  int leftLDRValue = analogRead(LDRLeftPin);
  int rightLDRValue = analogRead(LDRRightPin);

  // Debugging: Print LDR values
  Serial.print("Left LDR: ");
  Serial.print(leftLDRValue);
  Serial.print("  Right LDR: ");
  Serial.println(rightLDRValue);
  
  // If left sensor detects more light
  if (leftLDRValue > rightLDRValue + threshold) {
    moveLeft();  // Turn left
  }
  // If right sensor detects more light
  else if (rightLDRValue > leftLDRValue + threshold) {
    moveRight();  // Turn right
  }
  // If both sensors detect equal or similar light
  else {
    moveForward();  // Move forward
  }
}

void moveForward() {
  // Move both motors forward
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void moveLeft() {
  // Turn left (stop right motor, move left motor)
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void moveRight() {
  // Turn right (stop left motor, move right motor)
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}


