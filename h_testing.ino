void testing() {

bool arValue = digitalRead(arJumper);
bool loopValue = digitalRead(loopJumper);
bool longValue = digitalRead(longJumper);


  digitalWrite(output1, arValue);
  digitalWrite(output2, loopValue);
  digitalWrite(output3, longValue);


  /*
    Serial.print("Type:");
    Serial.print(EGType);
    Serial.print(" Mode:");
    Serial.print(mode);

    Serial.print("   A:");
    Serial.print(attackTimeBase);
    Serial.print(" R:");
    Serial.print(releaseTimeBase);
    Serial.print(" W:");
    Serial.print(wonkBase);

    Serial.print("   Inputs 1:");
    Serial.print(input1On);
    Serial.print(" 2:");
    Serial.print(input2On);
    Serial.print(" 3:");
    Serial.print(input3On);
    Serial.print(" 4:");
    Serial.print(input4On);

    Serial.print("A:");
    Serial.print(attackTime1);
    Serial.print("   R1:");
    Serial.print(releaseTime1);
    Serial.print("   EG:");
    Serial.print(EGStage1);

    Serial.print("   AStep:");
    Serial.print(attackStep1);
    Serial.print("   RStep:");
    Serial.print(releaseStep1);
    Serial.print("   Output:");
  */
  //  Serial.println(output1Value);



  //  Serial.println(" ");
}
