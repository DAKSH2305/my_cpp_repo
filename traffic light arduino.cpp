const int trafficRed = 10;
const int trafficYellow = 9;
const int trafficGreen = 8;

const int pedGreen = 6;
const int pedRed = 5;

const int buttonPin = 7;

// Timing (milliseconds)
const int yellowTime = 2000;
const int walkTime = 5000;
const int resetTime = 1000;

bool pedestrianRequest = false;

void setup() {
  pinMode(trafficRed, OUTPUT);
  pinMode(trafficYellow, OUTPUT);
  pinMode(trafficGreen, OUTPUT);

  pinMode(pedGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  // Start with default state
  digitalWrite(trafficRed, LOW);
  digitalWrite(trafficYellow, LOW);
  digitalWrite(trafficGreen, HIGH);

  digitalWrite(pedRed, HIGH);
  digitalWrite(pedGreen, LOW);
}

void loop() {
  // Check button press
  if (digitalRead(buttonPin) == LOW) {
    delay(50); // Debounce
    if (digitalRead(buttonPin) == LOW) {
      pedestrianRequest = true;
      while (digitalRead(buttonPin) == LOW); // Wait for release
    }
  }

  if (pedestrianRequest) {
    // Transition: Green OFF → Yellow ON
    digitalWrite(trafficGreen, LOW);
    digitalWrite(trafficYellow, HIGH);
    delay(yellowTime);

    // Yellow OFF → Red ON
    digitalWrite(trafficYellow, LOW);
    digitalWrite(trafficRed, HIGH);

    // Pedestrian: Red OFF → Green ON
    digitalWrite(pedRed, LOW);
    digitalWrite(pedGreen, HIGH);
    delay(walkTime);

    // Pedestrian: Green OFF → Red ON
    digitalWrite(pedGreen, LOW);
    digitalWrite(pedRed, HIGH);
    delay(resetTime);

    // Traffic: Red OFF → Green ON
    digitalWrite(trafficRed, LOW);
    digitalWrite(trafficGreen, HIGH);

    pedestrianRequest = false; // Reset
  }

  delay(100);
}
