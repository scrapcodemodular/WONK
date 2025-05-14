/*
   check mode and type switches for changes
*/

void setMode() {

  modeState1 = digitalRead(modeSwitch1);
  modeState2 = digitalRead(modeSwitch2);

  if (modeState1 == LOW) {
    mode = 0;                         // A
  } else if (modeState2 == LOW) {
    mode = 2;                         // A+R
  } else {
    mode = 1;                         // R
  }

  typeState1 = digitalRead(typeSwitch1);
  typeState2 = digitalRead(typeSwitch2);

  if (typeState2 == LOW) {
    EGType = 2;                         // Loop
  } else if (typeState1 == LOW) {
    EGType = 0;                         // AR
  } else {
    EGType = 1;                         // HR
  }

}
