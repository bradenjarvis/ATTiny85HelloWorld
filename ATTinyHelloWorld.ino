
int led = 1;
int but = 0;

int buttonValue = 0;
int butCount = 0;
int preVal = 0;

int newState = LOW;

unsigned long previousMillis = 0;
const long butInterval = 100;


void setup() {

  pinMode(led, OUTPUT);
  pinMode(but, INPUT);

}

void loop() {

  buttonValue = digitalRead(but);
  unsigned long currentMillis = millis();


  if (buttonValue != preVal) { //if button is pressed add state
    if (buttonValue == HIGH) {
      butCount++;


      if (butCount > 2) {  //reset state counter
        butCount = 0;

      }
    }
  }
  preVal = buttonValue;

  if (butCount == 0) { // state 1 (LED on)
    digitalWrite(led, HIGH);
  }
  else if (butCount == 1) { //state 2 (LED off)
    digitalWrite(led, LOW);
  }

  else if (butCount == 2) { //state 3 (blinking LED 100m)

    if (currentMillis - previousMillis >= butInterval) { // blinking with a timer
      previousMillis = currentMillis;
      if (newState == LOW) {
        newState = HIGH;
      }
      else {
        newState = LOW;
      }
      digitalWrite(led, newState);

    }
  }

}
