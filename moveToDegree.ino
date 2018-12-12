/*

*/

int positionPin = A0;      // Alalog pin for reading potentiometer reading.
int motorPin = 13;         // Pin with pulse for motor.
int breakPin = 12;         // Pin for disc break.
int targetAngle = 180;
float currentVoltage = 0;  // A variable for storing the voltage from the inverter and scaler circuit.
int currentAngle = 0;      // A variable for storing the current angle of the motor.
int verDelay = 1500;       // 1000 to 2000, reverse to forward, 1500 is no movment.

void setup() {
  pinMode(motorPin, OUTPUT);    // Set the pin for the motor as an output.
  pinMode(positionPin, INPUT);  // set the pin for the potentiometer reading as an input.
  pinMode(breakPin, OUTPUT);    // set the pin for the break as an output.
  verDelay = 1500;              // set the speed of the motor to stop.
  digitalWrite(breakPin, HIGH); // activate the break.

  
}

void loop() {
  /*
  read the voltage on the position pin and save the reading to the variable 'currentVoltage'.
  Expected voltage on the pin range from 0v to 5v. When the alalog pin is read it will return a number between 0 and 1023.
  Convert the alalog 0 to 1023 range to an angle in degrees.
  The potentiometer after going through the inverter and scaler has a range of 0v to 5v, the analog pin has a range from 0 to 1023,
  and the circle has a range of 360 degrees.
  */
  currentVoltage = analogRead(positionPin);             // store the voltage from the inverter and scaler circuit in variable to 'currentVoltage'. (between 0 and 1023)
  currentAngle = map(currentVoltage, 0, 1023, 0, 359);  // convert currentVoltage to currentAngle. 
  verDelay = 1800;                                      // start the motor.
  
  if ( currentAngle > 190 ) {      // If the angle of the disc is greater than 190 degrees, move the disc forward.
    for (int i = 0; i < 50; i++) { // run this loop 50 times. 
      digitalWrite(breakPin, LOW); // disengage the break.
      verDelay = 1800;             // set motor to turn forward slowly.
      digitalWrite(motorPin, HIGH);
      delayMicroseconds(verDelay);
      digitalWrite(motorPin, LOW);
      delay(20);
      currentVoltage = analogRead(positionPin);             // store the voltage from the inverter and scaler circuit in variable to 'currentVoltage'. (between 0 and 1023)
      currentAngle = map(currentVoltage, 0, 1023, 0, 359);  // convert currentVoltage to currentAngle.
      if (currentAngle >170 && currentAngle <190) {         // If the current angle is in the range of 170 and 190 degrees then end the 'for loop' prematurly.
        verDelay = 1500;                                    // set the speed of the motor to stop.
        digitalWrite(breakPin, HIGH);                       // activate the break.
        break;
      };
    };
  };

  
  if ( currentAngle < 170 ) {      // If the angle of the disc is greater than 190 degrees, move the disc forward.
    for (int i = 0; i < 50; i++) { // run this loop 50 times. 
      digitalWrite(breakPin, LOW); // disengage the break.
      verDelay = 1800;             // set motor to turn forward slowly.
      digitalWrite(motorPin, HIGH);
      delayMicroseconds(verDelay);
      digitalWrite(motorPin, LOW);
      delay(20);
      currentVoltage = analogRead(positionPin);             // store the voltage from the inverter and scaler circuit in variable to 'currentVoltage'. (between 0 and 1023)
      currentAngle = map(currentVoltage, 0, 1023, 0, 359);  // convert currentVoltage to currentAngle.
      if (currentAngle >170 && currentAngle <190) {         // If the current angle is in the range of 170 and 190 degrees then end the 'for loop' prematurly.
        verDelay = 1500;                                    // set the speed of the motor to stop.
        digitalWrite(breakPin, HIGH);                       // activate the break.  
        break;
      };
    };
  };
  delay(2000);  // wait two seconds on the correct angle before moving off again.
}
