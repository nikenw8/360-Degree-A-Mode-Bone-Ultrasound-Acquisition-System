#define directionPin 2
#define stepPin 3
#define directionPin1 4
#define stepPin1 5
#define directionPin3 6
#define stepPin3 7

#define stepPerRevolution 6400  
#define stepDelay 1500          
#define stepFor2cm 6400         
#define step10Deg 640          
#define stepFor6cm 12800

void setup() {
  Serial.begin(9600);
  pinMode(directionPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(directionPin1, OUTPUT);
  pinMode(stepPin1, OUTPUT);
  pinMode(directionPin3, OUTPUT);
  pinMode(stepPin3, OUTPUT);
}

void loop() {
  for (int i = 0; i < 2; i++) {
    Serial.println("Siklus ke-" + String(i + 1));
    
    
    digitalWrite(directionPin, HIGH);
    for (int j = 0; j < 5; j++) {
      delay(60000);
      stepMotorSingle(stepPin, step10Deg);
      Serial.println("putaran ke-" + String(j + 1));
    }
    Serial.println("Motor 1 selesai clockwise");

    delay(500);

    // Motor 1: Balik -360 derajat
    digitalWrite(directionPin, LOW);
    stepMotorSingle(stepPin, stepPerRevolution);
    Serial.println("Motor 1 selesai counter-clockwise");

    delay(500);

    // Reset pin sebelum motor 2 & 3
    digitalWrite(directionPin1, LOW);
    digitalWrite(directionPin3, LOW);
    delay(10);
    
    // Motor 2 & 3: Naik 2 cm
    digitalWrite(directionPin1, HIGH);
    digitalWrite(directionPin3, HIGH);
    stepMotorDual(stepPin1, stepPin3, stepFor2cm);
    Serial.println("Motor 2 & 3 selesai");

    delay(500);
  }

  // Turun 8 cm
  digitalWrite(directionPin1, LOW);
  digitalWrite(directionPin3, LOW);
  stepMotorDual(stepPin1, stepPin3, stepFor6cm);
  Serial.println("Turun 8 cm selesai");

  while (true); // Stop setelah selesai
}

void stepMotorSingle(int stepPinInput, int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinInput, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPinInput, LOW);
    delayMicroseconds(stepDelay);
  }
}

void stepMotorDual(int stepPinA, int stepPinB, int steps) {
  Serial.println("Menggerakkan motor 2 & 3, stepPin3: " + String(digitalRead(stepPin3)));
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPinA, HIGH);
    digitalWrite(stepPinB, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPinA, LOW);
    digitalWrite(stepPinB, LOW);
    delayMicroseconds(stepDelay);
    if (i % 1000 == 0) {
      Serial.println("Langkah ke-" + String(i));
    }
  }
  Serial.println("Selesai motor 2 & 3");
}