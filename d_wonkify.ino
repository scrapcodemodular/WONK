/*
  create individual attack and release times modified by wonkiness
  mode dependant!

*/

void wonkify() {


  if (mode != 1) {    // attack times in A & A+R modes

    if (EGType == 2) { // if in loop mode

      if (wonkBase < 500) {   // if wonk is negative
        attackWonk1 = map(wonkBase, 500, 0, 0, (minLoopAttackTime - attackTimeBase * 0.95));
        attackWonk2 = map(wonkBase, 500, 0, 0, (minLoopAttackTime - attackTimeBase * 0.55));
        attackWonk3 = map(wonkBase, 500, 0, 0, (minLoopAttackTime - attackTimeBase * 0.15));
        attackWonk4 = map(wonkBase, 500, 0, 0, (minLoopAttackTime - attackTimeBase * -0.25));
      }

      else if (wonkBase > 520) {    // if wonk is positive
        attackWonk1 = map(wonkBase, 520, 1023, 0, (maxLoopAttackTime * 0.95));
        attackWonk2 = map(wonkBase, 520, 1023, 0, (maxLoopAttackTime * 0.55));
        attackWonk3 = map(wonkBase, 520, 1023, 0, (maxLoopAttackTime * 0.15));
        attackWonk4 = map(wonkBase, 520, 1023, 0, (maxLoopAttackTime * -0.25));
      }
    }

    else  if (wonkBase < 500) {   // if wonk is negative
      attackWonk1 = map(wonkBase, 500, 0, 0, (minAttackTime - attackTimeBase * 0.95));
      attackWonk2 = map(wonkBase, 500, 0, 0, (minAttackTime - attackTimeBase * 0.55));
      attackWonk3 = map(wonkBase, 500, 0, 0, (minAttackTime - attackTimeBase * 0.15));
      attackWonk4 = map(wonkBase, 500, 0, 0, (minAttackTime - attackTimeBase * -0.25));
    }

    else if (wonkBase > 520) {    // if wonk is positive
      attackWonk1 = map(wonkBase, 520, 1023, 0, (maxAttackTime * 0.95));
      attackWonk2 = map(wonkBase, 520, 1023, 0, (maxAttackTime * 0.55));
      attackWonk3 = map(wonkBase, 520, 1023, 0, (maxAttackTime * 0.15));
      attackWonk4 = map(wonkBase, 520, 1023, 0, (maxAttackTime * -0.25));
    }

    else {    // if wonk is zero(ish)
      attackWonk1 = 0;
      attackWonk2 = 0;
      attackWonk3 = 0;
      attackWonk4 = 0;
    }

    attackTime1 = attackTimeBase + attackWonk1; // modify values
    attackTime2 = attackTimeBase + attackWonk2;
    attackTime3 = attackTimeBase + attackWonk3;
    attackTime4 = attackTimeBase + attackWonk4;

  } else {   // attack time in R mode

    attackTime1 = attackTimeBase;
    attackTime2 = attackTimeBase;
    attackTime3 = attackTimeBase;
    attackTime4 = attackTimeBase;
  }



  if (mode != 0) {    // release times in R & A+R modes

    if (EGType == 2) {

      if (wonkBase < 500) {   // if wonk is negative
        releaseWonk1 = map(wonkBase, 500, 0, 0, (minLoopReleaseTime - releaseTimeBase * 0.95));
        releaseWonk2 = map(wonkBase, 500, 0, 0, (minLoopReleaseTime - releaseTimeBase * 0.55));
        releaseWonk3 = map(wonkBase, 500, 0, 0, (minLoopReleaseTime - releaseTimeBase * 0.15));
        releaseWonk4 = map(wonkBase, 500, 0, 0, (minLoopReleaseTime - releaseTimeBase * -0.25));
      }

      else if (wonkBase > 520) {    // if wonk is positive
        releaseWonk1 = map(wonkBase, 520, 1023, 0, (maxLoopReleaseTime * 0.95));
        releaseWonk2 = map(wonkBase, 520, 1023, 0, (maxLoopReleaseTime * 0.55));
        releaseWonk3 = map(wonkBase, 520, 1023, 0, (maxLoopReleaseTime * 0.15));
        releaseWonk4 = map(wonkBase, 520, 1023, 0, (maxLoopReleaseTime * -0.25));
      }
    }

    else if (wonkBase < 500) {   // if wonk is negative
      releaseWonk1 = map(wonkBase, 500, 0, 0, (minReleaseTime - releaseTimeBase * 0.95));
      releaseWonk2 = map(wonkBase, 500, 0, 0, (minReleaseTime - releaseTimeBase * 0.55));
      releaseWonk3 = map(wonkBase, 500, 0, 0, (minReleaseTime - releaseTimeBase * 0.15));
      releaseWonk4 = map(wonkBase, 500, 0, 0, (minReleaseTime - releaseTimeBase * -0.25));
    }

    else if (wonkBase > 520) {    // if wonk is positive
      releaseWonk1 = map(wonkBase, 520, 1023, 0, (maxReleaseTime * 0.95));
      releaseWonk2 = map(wonkBase, 520, 1023, 0, (maxReleaseTime * 0.55));
      releaseWonk3 = map(wonkBase, 520, 1023, 0, (maxReleaseTime * 0.15));
      releaseWonk4 = map(wonkBase, 520, 1023, 0, (maxReleaseTime * -0.25));
    }

    else {    // if wonk is zero(ish)
      releaseWonk1 = 0;
      releaseWonk2 = 0;
      releaseWonk3 = 0;
      releaseWonk4 = 0;
    }

    releaseTime1 = releaseTimeBase + releaseWonk1;
    releaseTime2 = releaseTimeBase + releaseWonk2;
    releaseTime3 = releaseTimeBase + releaseWonk3;
    releaseTime4 = releaseTimeBase + releaseWonk4;

  } else {    // release times in A mode

    releaseTime1 = releaseTimeBase;
    releaseTime2 = releaseTimeBase;
    releaseTime3 = releaseTimeBase;
    releaseTime4 = releaseTimeBase;
  }

  // min safeties

  if (EGType == 2) {

    if (attackTime1 < minLoopAttackTime) {
      attackTime1 = minLoopAttackTime;
    }
    if (attackTime2 < minLoopAttackTime) {
      attackTime2 = minLoopAttackTime;
    }
    if (attackTime3 < minLoopAttackTime) {
      attackTime3 = minLoopAttackTime;
    }
    if (attackTime4 < minLoopAttackTime) {
      attackTime4 = minLoopAttackTime;
    }


    if (releaseTime1 < minLoopReleaseTime) {
      releaseTime1 = minLoopReleaseTime;
    }
    if (releaseTime2 < minLoopReleaseTime) {
      releaseTime2 = minLoopReleaseTime;
    }
    if (releaseTime3 < minLoopReleaseTime) {
      releaseTime3 = minLoopReleaseTime;
    }
    if (releaseTime4 < minLoopReleaseTime) {
      releaseTime4 = minLoopReleaseTime;
    }

  } else {

    if (attackTime1 < minAttackTime) {
      attackTime1 = minAttackTime;
    }
    if (attackTime2 < minAttackTime) {
      attackTime2 = minAttackTime;
    }
    if (attackTime3 < minAttackTime) {
      attackTime3 = minAttackTime;
    }
    if (attackTime4 < minAttackTime) {
      attackTime4 = minAttackTime;
    }


    if (releaseTime1 < minReleaseTime) {
      releaseTime1 = minReleaseTime;
    }
    if (releaseTime2 < minReleaseTime) {
      releaseTime2 = minReleaseTime;
    }
    if (releaseTime3 < minReleaseTime) {
      releaseTime3 = minReleaseTime;
    }
    if (releaseTime4 < minReleaseTime) {
      releaseTime4 = minReleaseTime;
    }
  }




  /*
      ARE MAXIMUM RELEASE TIMES NEEDED?

    if (releaseTime1 > maxReleaseTime) {
      releaseTime1 = maxReleaseTime;
    }
    if (releaseTime2 > maxReleaseTime) {
      releaseTime2 = maxReleaseTime;
    }
    if (releaseTime3 > maxReleaseTime) {
      releaseTime3 = maxReleaseTime;
    }
    if (releaseTime4 > maxReleaseTime) {
      releaseTime4 = maxReleaseTime;
    }

        if (attackTime1 > maxAttackTime) {
      attackTime1 = maxAttackTime;
    }
    if (attackTime2 > maxAttackTime) {
      attackTime2 = maxAttackTime;
    }
    if (attackTime3 > maxAttackTime) {
      attackTime3 = maxAttackTime;
    }
    if (attackTime4 > maxAttackTime) {
      attackTime4 = maxAttackTime;
    }
  */


}
