char softwareVersion[] = "v1";    // software version
// Modifiables
byte minAttackTime = 1;            // AR specific
int maxAttackTime = 400;

byte minHoldTime = 10;             // HR specific
int maxHoldTime = 1200;
byte HRAttackTime = 10;

byte minReleaseTime = 20;          // AR + HR
int maxReleaseTime = 1200;

byte minLoopAttackTime = 20;       // Loop specific
int maxLoopAttackTime = 4000;
byte minLoopReleaseTime = 20;
int maxLoopReleaseTime = 4000;


byte minLongReleaseTime = 100;     // AR + HR if long jumper in use
int maxLongReleaseTime = 8000;

byte minFastLoopAttackTime = 1;      // Fast loop if jumper in use
byte maxFastLoopAttackTime = 20;
byte minFastLoopReleaseTime = 1;
byte maxFastLoopReleaseTime = 20;


// Microcontroller Pins
const int attackPin = A0;
const int releasePin = A1;
const int wonkPin = A2;

const byte typeSwitch1 = 4;
const byte typeSwitch2 = 5;
const byte modeSwitch1 = 6;
const byte modeSwitch2 = 7;

const int input1 = A5;
const int input2 = A4;
const int input3 = A3;
const byte input4 = 2;

const byte output1 = 11;
const byte output2 = 9;
const byte output3 = 10;
const byte output4 = 3;

const byte longJumper = 8;
const byte loopJumper = 12;
const byte arJumper = 13;


// Modes
bool typeState1 = 0;
bool typeState2 = 0;
byte EGType = 0;      // 0 = AR, 1 = HR, 2 = loop
bool EGTypeWasHR = 0;

bool modeState1 = 0;
bool modeState2 = 0;
byte mode = 2;      // 0 = A, 1 = R, 2 = A+R

bool arGateMode = 0;


// Parameters
int wonkBase = 512;
int attackWonk1 = 512;
int attackWonk2 = 512;
int attackWonk3 = 512;
int attackWonk4 = 512;
int releaseWonk1 = 512;
int releaseWonk2 = 512;
int releaseWonk3 = 512;
int releaseWonk4 = 512;

int attackTimeBase = 500;
int attackTime1 = 100; // time in ms between start and end of attack stage
int attackTime2 = 100;
int attackTime3 = 100;
int attackTime4 = 100;

int releaseTimeBase = 500;
int releaseTime1 = 100; // time in ms between start and end of release stage
int releaseTime2 = 100;
int releaseTime3 = 100;
int releaseTime4 = 100;

float attackStep1; // amount output1 needs to increase every ms to go from 0-255 in attackTime
float attackStep2;
float attackStep3;
float attackStep4;

float releaseStep1; // amount output1 needs to decrease every ms to go from 255-0 in releaseTime
float releaseStep2;
float releaseStep3;
float releaseStep4;

float output1Value = 0;
float output2Value = 0;
float output3Value = 0;
float output4Value = 0;

unsigned long currentMillis;
unsigned long lastMillis;

byte EGStage1 = 0;   // current envelope stage 0 = off, 1 = attack, 2 = hold, 3 = release
byte EGStage2 = 0;
byte EGStage3 = 0;
byte EGStage4 = 0;

bool input1On = 0;
bool input2On = 0;
bool input3On = 0;
bool input4On = 0;
bool input1WasOn = 0;
bool input2WasOn = 0;
bool input3WasOn = 0;
bool input4WasOn = 0;
bool input1WasOnLoop = 0;
bool input2WasOnLoop = 0;
bool input3WasOnLoop = 0;
bool input4WasOnLoop = 0;

unsigned long input1OnTime;
unsigned long input2OnTime;
unsigned long input3OnTime;
unsigned long input4OnTime;

unsigned long input1OffTime;
unsigned long input2OffTime;
unsigned long input3OffTime;
unsigned long input4OffTime;


void setup() {

  // Pinmodes
  pinMode(attackPin, INPUT);
  pinMode(releasePin, INPUT);
  pinMode(wonkPin, INPUT);

  pinMode(typeSwitch1, INPUT_PULLUP);
  pinMode(typeSwitch2, INPUT_PULLUP);
  pinMode(modeSwitch1, INPUT_PULLUP);
  pinMode(modeSwitch2, INPUT_PULLUP);

  pinMode(input1, INPUT_PULLUP);
  pinMode(input2, INPUT_PULLUP);
  pinMode(input3, INPUT_PULLUP);
  pinMode(input4, INPUT_PULLUP);

  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);

  pinMode(arJumper, INPUT_PULLUP);
  pinMode(longJumper, INPUT_PULLUP);
  pinMode(loopJumper, INPUT_PULLUP);


  // timer 1 - 62.5kHz x1 fast PWM
  TCCR1B = 0b00000001;
  TCCR1A = 0b00001001;

  // timer 2 - 62.5kHz x1 fast PWM
  TCCR2B = 0b00000001;
  TCCR2A = 0b00000011;

  // jumpers - modify WONK's behaviour if jumpers on rear of module have been removed
  
  delay(100);

  if (digitalRead(longJumper) == HIGH) {
    minReleaseTime = minLongReleaseTime;
    maxReleaseTime = maxLongReleaseTime;
  }

  if (digitalRead(loopJumper) == HIGH) {
    minLoopAttackTime = minFastLoopAttackTime;
    maxLoopAttackTime = maxFastLoopAttackTime;
    minLoopReleaseTime = minFastLoopReleaseTime;
    maxLoopReleaseTime = maxFastLoopReleaseTime;
  }

  if (digitalRead(arJumper) == HIGH) {
    arGateMode = 1;
  }
  
  delay(100);
  
  //  Serial.begin(9600);   // ONLY FOR TESTING

}


void loop() {
  setMode();
  getValues();
  wonkify();
  updateStages();
  generateSteps();
  runOutputs();

  //  testing();
}
