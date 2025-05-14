/*
   calculate next step values from attack and release times

   fixed attack time in HR EGType
*/

void generateSteps() {

  if (EGType == 1) {          // if type is HR
    if (EGTypeWasHR == 0) {   // on change do this once

      attackStep1 = 255. / minAttackTime;
      attackStep2 = 255. / minAttackTime;
      attackStep3 = 255. / minAttackTime;
      attackStep4 = 255. / minAttackTime;

      EGTypeWasHR = 1;
    }

  }

  if (EGType != 1) {      // if type is not HR

    attackStep1 = 255. / attackTime1;
    attackStep2 = 255. / attackTime2;
    attackStep3 = 255. / attackTime3;
    attackStep4 = 255. / attackTime4;


    EGTypeWasHR = 0;
  }

  releaseStep1 = 255. / releaseTime1;
  releaseStep2 = 255. / releaseTime2;
  releaseStep3 = 255. / releaseTime3;
  releaseStep4 = 255. / releaseTime4;

}
