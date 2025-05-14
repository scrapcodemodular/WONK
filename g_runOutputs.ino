/*
   check timer, if progressed then modify output levels and output
*/

void runOutputs() {

  if (currentMillis > lastMillis) {         // if 1ms has passed
    lastMillis = currentMillis;      


    // off stages

    if (EGStage1 == 0) {
      output1Value = 0;
    }
    if (EGStage2 == 0) {
      output2Value = 0;
    }
    if (EGStage3 == 0) {
      output3Value = 0;
    }
    if (EGStage4 == 0) {
      output4Value = 0;
    }


    // attack stages

    if (EGStage1 == 1) {
      output1Value = output1Value + attackStep1;
    }
    if (EGStage2 == 1) {
      output2Value = output2Value + attackStep2;
    }
    if (EGStage3 == 1) {
      output3Value = output3Value + attackStep3;
    }
    if (EGStage4 == 1) {
      output4Value = output4Value + attackStep4;
    }


    // hold stages

    if (EGStage1 == 2) {
      output1Value = 255;
    }
    if (EGStage2 == 2) {
      output2Value = 255;
    }
    if (EGStage3 == 2) {
      output3Value = 255;
    }
    if (EGStage4 == 2) {
      output4Value = 255;
    }


    // release stages

    if (EGStage1 == 3) {
      output1Value = output1Value - releaseStep1;
    }
    if (EGStage2 == 3) {
      output2Value = output2Value - releaseStep2;
    }
    if (EGStage3 == 3) {
      output3Value = output3Value - releaseStep3;
    }
    if (EGStage4 == 3) {
      output4Value = output4Value - releaseStep4;
    }


    // check min/maxes

    if (output1Value > 255) {
      output1Value = 255;
    }
    if (output2Value > 255) {
      output2Value = 255;
    }
    if (output3Value > 255) {
      output3Value = 255;
    }
    if (output4Value > 255) {
      output4Value = 255;
    }

    if (output1Value < 0) {
      output1Value = 0;
    }
    if (output2Value < 0) {
      output2Value = 0;
    }
    if (output3Value < 0) {
      output3Value = 0;
    }
    if (output4Value < 0) {
      output4Value = 0;
    }


    // run outputs!

    analogWrite(output1, output1Value);
    analogWrite(output2, output2Value);
    analogWrite(output3, output3Value);
    analogWrite(output4, output4Value);


  }

}
