const int photoPin = A0;
const int redLedPin = 9;
const int greenLedPin = 5;
const int threshold = 512;
const int openTime = 5000;
bool doorOpen = false;
unsigned long doorTimer = 0;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
  Serial.begin(9600);
  Serial.println("Door close");
}

void loop() {
  int photoValue = analogRead(photoPin);
  if (photoValue > threshold) {
    if (!doorOpen) {
      openDoor();
    }
    doorTimer = millis();
  }
  if (doorOpen && (millis() - doorTimer > openTime)) {
    if (analogRead(photoPin) <= threshold) {
      closeDoor();
    } else {
      doorTimer = millis();
    }
  }
  delay(100);
}

void openDoor() {
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, HIGH);
  doorOpen = true;
  doorTimer = millis();
  Serial.println("Door open");
  Serial.println(analogRead(photoPin));
}

void closeDoor() {
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, HIGH);
  doorOpen = false;
  Serial.println("Door close");
  Serial.println(analogRead(photoPin));
}