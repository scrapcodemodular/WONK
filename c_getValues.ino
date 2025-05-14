/*
   get values for knob positions
   convert to ms values for attack and release

   check trigger/gate statuses (timestamps)

*/

void getValues() {

  attackTimeBase = analogRead(attackPin);
  releaseTimeBase = analogRead(releasePin);
  wonkBase = analogRead(wonkPin);


  if (EGType == 0) {      // AR
    attackTimeBase = map(attackTimeBase, 0, 1023, minAttackTime, maxAttackTime);
    releaseTimeBase = map(releaseTimeBase, 0, 1023, minReleaseTime, maxReleaseTime);
  }

  if (EGType == 1) {      // HR
    attackTimeBase = map(attackTimeBase, 0, 1023, minHoldTime, maxHoldTime);
    releaseTimeBase = map(releaseTimeBase, 0, 1023, minReleaseTime, maxReleaseTime);
  }

  if (EGType == 2) {       // Loop
    attackTimeBase = map(attackTimeBase, 0, 1023, minLoopAttackTime, maxLoopAttackTime);
    releaseTimeBase = map(releaseTimeBase, 0, 1023, minLoopReleaseTime, maxLoopReleaseTime);
  }


  // trigger/gate statuses and timestamps

  currentMillis = millis();           // captures current time

  if ((digitalRead(input1) == LOW) && (input1WasOn == 0)) {
    input1On = 1;
    input1OnTime = currentMillis;
    input1WasOn = 1;
  }
  if (digitalRead(input1) == HIGH) {
    input1On = 0;
    input1WasOn = 0;
  }

  if ((digitalRead(input2) == LOW) && (input2WasOn == 0)) {
    input2On = 1;
    input2OnTime = currentMillis;
    input2WasOn = 1;
  }
  if (digitalRead(input2) == HIGH) {
    input2On = 0;
    input2WasOn = 0;
  }

  if ((digitalRead(input3) == LOW) && (input3WasOn == 0)) {
    input3On = 1;
    input3OnTime = currentMillis;
    input3WasOn = 1;
  }
  if (digitalRead(input3) == HIGH) {
    input3On = 0;
    input3WasOn = 0;
  }

  if ((digitalRead(input4) == LOW) && (input4WasOn == 0)) {
    input4On = 1;
    input4OnTime = currentMillis;
    input4WasOn = 1;
  }
  if (digitalRead(input4) == HIGH) {
    input4On = 0;
    input4WasOn = 0;
  }



}
