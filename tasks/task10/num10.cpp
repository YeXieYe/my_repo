#include <Servo.h>

Servo myservo;
int currentAngle = 90;
int targetAngle = 90;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  Serial.println("Enter angle (0-180):");
  myservo.write(90);
  delay(1000);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.length() > 0 && isDigits(input)) {
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