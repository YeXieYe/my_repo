#include <Servo.h>

Servo myservo;
int currentAngle = 0;
int targetAngle = 0;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  Serial.println("Enter angle (0-180):");
  myservo.write(0);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (isDigits(input)) {
      int newAngle = input.toInt();
      if (newAngle >= 0 && newAngle <= 180) {
        targetAngle = newAngle;
        Serial.print("Moving to: ");
        Serial.print(targetAngle);
        Serial.println("°");
      } else {
        Serial.println("Error: Angle must be 0-180°");
      }
    } else {
      Serial.println("Error: Numbers only (0-180)");
    }
  }
  if (currentAngle != targetAngle) {
    if (currentAngle < targetAngle) currentAngle++;
    else currentAngle--;
    myservo.write(currentAngle);
    delay(20);
  }
}

bool isDigits(const String &str) {
  for (unsigned int i = 0; i < str.length(); i++) {
    if (!isdigit(str[i])) return false;
  }
  return true;
}