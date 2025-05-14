/*
   use timestamps and attack times to update stages
   EGType dependant!
   reset loop mode if triggered
*/

void updateStages() {

  // A-R type

  if (EGType == 0) {

    if (arGateMode == 1) {        // gate mode (jumper operation)

      if ((EGStage1 == 0) && (input1On == 1) && (input1OnTime == currentMillis)) {   // if off and triggered (attack)
        EGStage1 = 1;
      }
      if ((EGStage1 == 1) && (output1Value == 255)) {    // once output is at full value (hold)
        EGStage1 = 2;
      }
      if ((EGStage1 == 1) && (input1On == 0)) {   // when attacking but gate released (release)
        EGStage1 = 3;
      }
      if ((EGStage1 == 2) && (input1On == 0)) {   // when holding and no gate present (release)
        EGStage1 = 3;
      }
      if ((EGStage1 == 3) && (input1On == 1) && (input1OnTime == currentMillis)) {   // when releasing and retriggered (attack)
        EGStage1 = 1;
      }
      if ((EGStage1 == 3) && (output1Value == 0)) {    // once output is at zero (off)
        EGStage1 = 0;
      }

      if ((EGStage2 == 0) && (input2On == 1) && (input2OnTime == currentMillis)) {
        EGStage2 = 1;
      }
      if ((EGStage2 == 1) && (output2Value == 255)) {
        EGStage2 = 2;
      }
      if ((EGStage2 == 1) && (input2On == 0)) {
        EGStage2 = 3;
      }
      if ((EGStage2 == 2) && (input2On == 0)) {
        EGStage2 = 3;
      }
      if ((EGStage2 == 3) && (input2On == 1) && (input2OnTime == currentMillis)) {
        EGStage2 = 1;
      }
      if ((EGStage2 == 3) && (output2Value == 0)) {
        EGStage2 = 0;
      }

      if ((EGStage3 == 0) && (input3On == 1) && (input3OnTime == currentMillis)) {
        EGStage3 = 1;
      }
      if ((EGStage3 == 1) && (output3Value == 255)) {
        EGStage3 = 2;
      }
      if ((EGStage3 == 1) && (input3On == 0)) {
        EGStage3 = 3;
      }
      if ((EGStage3 == 2) && (input3On == 0)) {
        EGStage3 = 3;
      }
      if ((EGStage3 == 3) && (input3On == 1) && (input3OnTime == currentMillis)) {
        EGStage3 = 1;
      }
      if ((EGStage3 == 3) && (output3Value == 0)) {
        EGStage3 = 0;
      }

      if ((EGStage4 == 0) && (input4On == 1) && (input4OnTime == currentMillis)) {
        EGStage4 = 1;
      }
      if ((EGStage4 == 1) && (output4Value == 255)) {
        EGStage4 = 2;
      }
      if ((EGStage4 == 1) && (input4On == 0)) {
        EGStage4 = 3;
      }
      if ((EGStage4 == 2) && (input4On == 0)) {
        EGStage4 = 3;
      }
      if ((EGStage4 == 3) && (input4On == 1) && (input4OnTime == currentMillis)) {
        EGStage4 = 1;
      }
      if ((EGStage4 == 3) && (output4Value == 0)) {
        EGStage4 = 0;
      }

    } else {          // trigger mode (normal operation)

      if ((EGStage1 == 0) && (input1On == 1) && (input1OnTime == currentMillis)) {   // if off and triggered (attack)
        EGStage1 = 1;
      }
      if ((EGStage1 == 1) && (output1Value == 255)) {    // once output is at full value (release)
        EGStage1 = 3;
      }
      if (EGStage1 == 2) {   // if holding (release)
        EGStage1 = 3;
      }
      if ((EGStage1 == 3) && (input1On == 1) && (input1OnTime == currentMillis)) {   // when releasing and retriggered (attack)
        EGStage1 = 1;
      }
      if ((EGStage1 == 3) && (output1Value == 0)) {    // once output is at zero (off)
        EGStage1 = 0;
      }

      if ((EGStage2 == 0) && (input2On == 1) && (input2OnTime == currentMillis)) {
        EGStage2 = 1;
      }
      if ((EGStage2 == 1) && (output2Value == 255)) {
        EGStage2 = 3;
      }
      if (EGStage2 == 2) {
        EGStage2 = 3;
      }
      if ((EGStage2 == 3) && (input2On == 1) && (input2OnTime == currentMillis)) {
        EGStage2 = 1;
      }
      if ((EGStage2 == 3) && (output2Value == 0)) {
        EGStage2 = 0;
      }

      if ((EGStage3 == 0) && (input3On == 1) && (input3OnTime == currentMillis)) {
        EGStage3 = 1;
      }
      if ((EGStage3 == 1) && (output3Value == 255)) {
        EGStage3 = 3;
      }
      if (EGStage3 == 2) {
        EGStage3 = 3;
      }
      if ((EGStage3 == 3) && (input3On == 1) && (input3OnTime == currentMillis)) {
        EGStage3 = 1;
      }
      if ((EGStage3 == 3) && (output3Value == 0)) {
        EGStage3 = 0;
      }

      if ((EGStage4 == 0) && (input4On == 1) && (input4OnTime == currentMillis)) {
        EGStage4 = 1;
      }
      if ((EGStage4 == 1) && (output4Value == 255)) {
        EGStage4 = 3;
      }
      if (EGStage4 == 2) {
        EGStage4 = 3;
      }
      if ((EGStage4 == 3) && (input4On == 1) && (input4OnTime == currentMillis)) {
        EGStage4 = 1;
      }
      if ((EGStage4 == 3) && (output4Value == 0)) {
        EGStage4 = 0;
      }

    }
  }


  // H-R mode

  if (EGType == 1) {

    if ((EGStage1 == 0) && (input1On == 1) && (input1OnTime == currentMillis)) {   // if off and triggered (attack)
      EGStage1 = 1;
    }
    if ((EGStage1 == 1) && (output1Value == 255)) {    // once output is at full value (hold)
      EGStage1 = 2;
    }
    if ((EGStage1 == 2) && (currentMillis >= (input1OnTime + attackTime1))) {   // when holding and hold time passed (release)
      EGStage1 = 3;
    }
    if ((EGStage1 == 3) && (input1OnTime == currentMillis)) {   // when releasing and retriggered (attack)
      EGStage1 = 1;
    }
    if ((EGStage1 == 3) && (output1Value == 0)) {    // once output is at zero (off)
      EGStage1 = 0;
    }

    if ((EGStage2 == 0) && (input2On == 1) && (input2OnTime == currentMillis)) {
      EGStage2 = 1;
    }
    if ((EGStage2 == 1) && (output2Value == 255)) {
      EGStage2 = 2;
    }
    if ((EGStage2 == 2) && (currentMillis >= (input2OnTime + attackTime2))) {
      EGStage2 = 3;
    }
    if ((EGStage2 == 3) && (input2OnTime == currentMillis)) {
      EGStage2 = 1;
    }
    if ((EGStage2 == 3) && (output2Value == 0)) {
      EGStage2 = 0;
    }

    if ((EGStage3 == 0) && (input3On == 1) && (input3OnTime == currentMillis)) {
      EGStage3 = 1;
    }
    if ((EGStage3 == 1) && (output3Value == 255)) {
      EGStage3 = 2;
    }
    if ((EGStage3 == 2) && (currentMillis >= (input3OnTime + attackTime3))) {
      EGStage3 = 3;
    }
    if ((EGStage3 == 3) && (input3OnTime == currentMillis)) {
      EGStage3 = 1;
    }
    if ((EGStage3 == 3) && (output3Value == 0)) {
      EGStage3 = 0;
    }

    if ((EGStage4 == 0) && (input4On == 1) && (input4OnTime == currentMillis)) {
      EGStage4 = 1;
    }
    if ((EGStage4 == 1) && (output4Value == 255)) {
      EGStage4 = 2;
    }
    if ((EGStage4 == 2) && (currentMillis >= (input4OnTime + attackTime4))) {
      EGStage4 = 3;
    }
    if ((EGStage4 == 3) && (input4OnTime == currentMillis)) {
      EGStage4 = 1;
    }
    if ((EGStage4 == 3) && (output4Value == 0)) {
      EGStage4 = 0;
    }
  }

  // loop mode

  if (EGType == 2) {

    if (EGStage1 == 0) {   // if off (attack)
      EGStage1 = 1;
    }
    if ((EGStage1 == 1) && (output1Value == 255)) {    // once output is at full value (release)
      EGStage1 = 3;
    }
    if (EGStage1 == 2) {   // if holding (release)
      EGStage1 = 3;
    }
    if ((EGStage1 == 3) && (output1Value == 0)) {    // once output is at zero (attack)
      EGStage1 = 1;
    }
    if ((input1On == 1) && (input1WasOnLoop == 0)) {    // if triggered (off)
      EGStage1 = 0;
      input1WasOnLoop = 1;
    }
    if (input1On == 0) {    // disallows retrigger from button hold
      input1WasOnLoop = 0;
    }

    if (EGStage2 == 0) {
      EGStage2 = 1;
    }
    if ((EGStage2 == 1) && (output2Value == 255)) {
      EGStage2 = 3;
    }
    if (EGStage2 == 2) {
      EGStage2 = 3;
    }
    if ((EGStage2 == 3) && (output2Value == 0)) {
      EGStage2 = 1;
    }
    if ((input2On == 1) && (input2WasOnLoop == 0)) {
      EGStage2 = 0;
      input2WasOnLoop = 1;
    }
    if (input2On == 0) {
      input2WasOnLoop = 0;
    }

    if (EGStage3 == 0) {
      EGStage3 = 1;
    }
    if ((EGStage3 == 1) && (output3Value == 255)) {
      EGStage3 = 3;
    }
    if (EGStage3 == 2) {
      EGStage3 = 3;
    }
    if ((EGStage3 == 3) && (output3Value == 0)) {
      EGStage3 = 1;
    }
    if ((input3On == 1) && (input3WasOnLoop == 0)) {
      EGStage3 = 0;
      input3WasOnLoop = 1;
    }
    if (input3On == 0) {
      input3WasOnLoop = 0;
    }

    if (EGStage4 == 0) {
      EGStage4 = 1;
    }
    if ((EGStage4 == 1) && (output4Value == 255)) {
      EGStage4 = 3;
    }
    if (EGStage4 == 2) {
      EGStage4 = 3;
    }
    if ((EGStage4 == 3) && (output4Value == 0)) {
      EGStage4 = 1;
    }
    if ((input4On == 1) && (input4WasOnLoop == 0)) {
      EGStage4 = 0;
      input4WasOnLoop = 1;
    }
    if (input4On == 0) {
      input4WasOnLoop = 0;
    }
  }

}
