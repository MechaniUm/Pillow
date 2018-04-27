#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 52
#define PIN1 6

#define NUMPIXELS 8
#define NUMPIXELS1 22

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(40, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(40, PIN, NEO_GRB + NEO_KHZ800);

#include <fix_fft.h>
#define AUDIOPIN 13

const int I1 = 17;
const int I2 = 16;
const int I3 = 15;
const int I4 = 14;
boolean Read_Status = false;
boolean Standby_Mode = false;
boolean Command_Status = false;
boolean I1_mode = false;
boolean I2_mode = false;
boolean I3_mode = false;
boolean I4_mode = false;
boolean bit_1_input = false;
boolean bit_2_input = false;
boolean bit_3_input = false;
boolean bit_4_input = false;
const int O1 = 5;
const int O2 = 4;
const int O3 = 3;
const int O4 = 2;
unsigned long t20 = 0;
unsigned long t21 = 0;
const int speed_read = 1000;
int director = 0;
int slave = 0;

int COMPLEX = 0;

boolean SETTINGS = false;
boolean MOVE = false;

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

const int s1 = 8;
const int s2 = 9;
const int s3 = 10;
const int s4 = 11;

boolean ServoLoop = false; 
boolean ServoDirection = false;
unsigned long ServoSpeed;
unsigned long t1 = 0;
unsigned long t2 = 0;
int MAX_deg = 180;
int MIN_deg = 170;
int pos = MIN_deg;
int count = 0;
int n = 0;

int Love_Speed = 0;
int Love_Speed1 = 0;
int Love_Speed2 = 0;
int ShowTime = 0;

boolean Servo1_move = false;
boolean Servo2_move = false;
boolean Servo3_move = false;
boolean Servo4_move = false;
int rounds_count = 0;
boolean Loop2 = false;

boolean Loop3 = false;
boolean Loop5 = false;
boolean Loop6 = false;
boolean Loop10 = false;

char im[128], data[128]; int b = 0, val; int out = 0; int br = 0;  

const int ISens1 = 0; const int ISens2 = 1; const int ISens3 = 2; const int ISens4 = 3; const int ISens5 = 4; 
const int ISens6 = 5; const int ISens7 = 6; const int ISens8 = 7; const int ISens9 = 8; const int ISens10 = 9;

const int X = 10; const int Y = 11; const int Z = 12; boolean POSITION_Z = false; boolean POSITION_Y = false; boolean POSITION = false;

int X_count; int Y_count; int Z_count; int X_deg; int Y_deg; int Z_deg;

int Delta1 = 0; int Delta2 = 0; int Delta3 = 0; int Delta4 = 0; int Delta5 = 0; int Delta6 = 0; int Delta7 = 0; int Delta8 = 0; int Delta9 = 0; int Delta10 = 0;

int D1_F = 0; int D1_S = 0; int D2_F = 0; int D2_S = 0; int D3_F = 0; int D3_S = 0; int D4_F = 0; int D4_S = 0; int D5_F = 0; int D5_S = 0;
int D6_F = 0; int D6_S = 0; int D7_F = 0; int D7_S = 0; int D8_F = 0; int D8_S = 0; int D9_F = 0; int D9_S = 0; int D10_F = 0; int D10_S = 0;

boolean START_MACHINE = false;
boolean START_DIRECTION = false; 
boolean LIGHT = true; 

boolean BurnLED_R = false; 
boolean BurnLED_B = false; 
boolean BurnLED_G = false;
boolean BurnLED_Y = false;
boolean BurnLED_O = false;
boolean BurnLED_V = false;

int Rp = 0;
int Gp = 0;
int Bp = 0;
int Rp1 = 0;
int Gp1 = 0;
int Bp1 = 0;


int red = 0;
int green = 0;
int blue = 0;
int orange = 0;
int yellow = 0;
int violet = 0;

int red_action = 0;
int orange_action = 0;
int green_action = 0;
int blue_action = 0;
int yellow_action = 0;
int violet_action = 0;

boolean R_flash = false;
boolean G_flash = false;
boolean B_flash = false;
boolean Y_flash = false;
boolean O_flash = false;
boolean V_flash = false;

unsigned long t3 = 0;
unsigned long t4 = 0;
const int light_interval = 500;

boolean Loop11 = false;
unsigned long t5 = 0;
unsigned long t6 = 0;
const int axel_interval = 1000;
const int servo_interval = 1000;

boolean Loop12 = false;
boolean Loop32 = false;
unsigned long t15 = 0;
boolean ServoSuperStart = false;

unsigned long t7 = 0; unsigned long t8 = 0; boolean Loop1 = false; unsigned long Time_Sens1_detection = 0; unsigned long Time_Sens2_detection = 0; 
unsigned long Time_Sens3_detection = 0; unsigned long Time_Sens4_detection = 0; unsigned long Time_Sens5_detection = 0;
unsigned long Time_Sens6_detection = 0; unsigned long Time_Sens7_detection = 0; unsigned long Time_Sens8_detection = 0; 
unsigned long Time_Sens9_detection = 0; unsigned long Time_Sens10_detection = 0;

boolean Lock_Sens1 = false; boolean Lock_Sens2 = false; boolean Lock_Sens3 = false; boolean Lock_Sens4 = false; boolean Lock_Sens5 = false;
boolean Lock_Sens6 = false; boolean Lock_Sens7 = false; boolean Lock_Sens8 = false; boolean Lock_Sens9 = false; boolean Lock_Sens10 = false;

int ANSWER = 0; // три значения переменной - если 0 ожидание ответа или его нет, 1 это да, 2 это нет //
int ANSWER_YES = 0;
int ANSWER_NO = 0;

boolean ANSWERTIME = false;
boolean Loop78 = false;
boolean Loop79 = false;
unsigned long t100 = 0;
unsigned long t101 = 0;


boolean Loop14 = false;
boolean Loop77 = false;
boolean TUPICA = false;
unsigned long t14 = 0;
boolean FallAnswer = false;
boolean LoopAnswerY = false;
boolean LoopAnswerN = false;
const int delta_wait_answer = 3000;
const int time_wait_answer = 20000;
const int TimeReaction = 100; 
const int Sensitivity = 8; 
const int Treshold = 5;
const int dark = 1;
const int Int_flash_LED = 50;
unsigned long t9 = 0;
unsigned long t10= 0;
boolean LED = false;
int f = 0;
int ff = 0;

int script = 0;
int script1 = 0;
int script2 = 0;
int script3 = 0;
int script4 = 0;
int script5 = 0;

void setup() 
{
 Serial.begin(9600);
 pixels.begin();
 pixels1.begin();
 strip.begin();
 strip.show();
 strip1.begin();
 strip1.show();
 pinMode(I1, INPUT); pinMode(O1, OUTPUT);
 pinMode(I2, INPUT); pinMode(O2, OUTPUT);
 pinMode(I3, INPUT); pinMode(O3, OUTPUT);
 pinMode(I4, INPUT); pinMode(O4, OUTPUT);  
 delay(1000);
 randomSeed(analogRead(15));
}

void LED_PANIK() {t9 = millis(); if(LED == false) {t10 = millis(); LED = true; f++;} if((t9 - t10) >= Int_flash_LED / 2) LED = false; pixels.setPixelColor(f, pixels.Color(40,0,0)); pixels.show(); 
                if(f >= NUMPIXELS){for(f = 8; f >= 0; f--) {pixels.setPixelColor(f, pixels.Color(0,0,0)); pixels.show();}}}
                
void SLOW_DARK_EYE() 
{
  t9 = millis(); 
  if(LED == false) {t10 = millis(); LED = true; f++; ff++;} if((t9 - t10) >= Int_flash_LED) LED = false; 
  pixels.setPixelColor(f, pixels.Color(0,0,0)); pixels.show(); if(f >= NUMPIXELS) f = 0;
  pixels1.setPixelColor(ff, pixels.Color(0,0,0)); pixels1.show(); if(ff >= NUMPIXELS1) ff = 0;
}

void FAST_DARK_EYE() {for(f = 0; f <= 8; f++){pixels.setPixelColor(f, pixels.Color(0,0,0)); pixels.show();} 
                      for(ff = 0; f <= 22; ff++){pixels1.setPixelColor(ff, pixels1.Color(0,0,0)); pixels1.show();}}
                
void RED_EYE() {t9 = millis(); if(LED == false) {t10 = millis(); LED = true; f++; ff++;} if((t9 - t10) >= Int_flash_LED) LED = false; 
                pixels.setPixelColor(f, pixels.Color(40,0,0)); pixels.show(); 
                pixels1.setPixelColor(ff, pixels1.Color(40,0,0)); pixels1.show();
                if(f >= NUMPIXELS) f = 0; if(ff >= NUMPIXELS1) ff = 0;}
                
void GREEN_EYE() {t9 = millis(); if(LED == false) {t10 = millis(); LED = true; f++; ff++;} if((t9 - t10) >= Int_flash_LED) LED = false; 
                  pixels.setPixelColor(f, pixels.Color(0,40,0)); pixels.show(); 
                  pixels1.setPixelColor(ff, pixels1.Color(0,40,0)); pixels1.show();
                  if(f >= NUMPIXELS) f = 0; if(ff >= NUMPIXELS1) ff = 0;}

void BLUE_EYE() {t9 = millis(); if(LED == false) {t10 = millis(); LED = true; f++; ff++;} if((t9 - t10) >= Int_flash_LED) LED = false; 
                 pixels.setPixelColor(f, pixels.Color(0,0,40)); pixels.show(); 
                 pixels1.setPixelColor(ff, pixels1.Color(0,0,40)); pixels1.show();
                 if(f >= NUMPIXELS) f = 0; if(ff >= NUMPIXELS1) ff = 0;}

void WHITE_EYE() {t9 = millis(); if(LED == false) {t10 = millis(); LED = true; f++;} if((t9 - t10) >= Int_flash_LED) LED = false; pixels.setPixelColor(f, pixels.Color(40,40,40)); pixels.show(); if(f >= NUMPIXELS) f = 0;}

void CLEAR_CASH() 
{
  Time_Sens1_detection = 0; Time_Sens2_detection = 0; Time_Sens3_detection = 0; Time_Sens4_detection = 0; Time_Sens5_detection = 0;
  Time_Sens6_detection = 0; Time_Sens7_detection = 0; Time_Sens8_detection = 0; Time_Sens9_detection = 0; Time_Sens10_detection = 0; 
  Lock_Sens1 = false; Lock_Sens2 = false; Lock_Sens3 = false; Lock_Sens4 = false; Lock_Sens5 = false;
  Lock_Sens6 = false; Lock_Sens7 = false; Lock_Sens8 = false; Lock_Sens9 = false; Lock_Sens10 = false;
}

void YES_NO()
{
   if(Loop79 == false) {t101 = millis(); Loop79 = true;}
   if(((millis() - t101 ) >= time_wait_answer) && ANSWER == 0) {slave = 6; TUPICA = true; BLUE_EYE();}

   
   if(ANSWER == 0)
   {
    if(Loop1 == false) {t8 = millis(); Loop1 = true;} if(Loop1 == true) {if ((t7 - t8) >= TimeReaction) {Loop1 = false;}}; 
    if(Loop1 == false)   
    {D1_F = analogRead(ISens1); D2_F = analogRead(ISens2); D3_F = analogRead(ISens3); D4_F = analogRead(ISens4); D5_F = analogRead(ISens5);
    D6_F = analogRead(ISens6); D7_F = analogRead(ISens7); D8_F = analogRead(ISens8); D9_F = analogRead(ISens9); D10_F = analogRead(ISens10);} if(Loop1 == true)
    {D1_S = analogRead(ISens1); D2_S = analogRead(ISens2); D3_S = analogRead(ISens3); D4_S = analogRead(ISens4); D5_S = analogRead(ISens5);
    D6_S = analogRead(ISens6); D7_S = analogRead(ISens7); D8_S = analogRead(ISens8); D9_S = analogRead(ISens9); D10_S = analogRead(ISens10);}
    Delta1 = abs(D1_S - D1_F); Delta2 = abs(D2_S - D2_F); Delta3 = abs(D3_S - D3_F); Delta4 = abs(D4_S - D4_F); Delta5 = abs(D5_S - D5_F);
    Delta6 = abs(D6_S - D6_F); Delta7 = abs(D7_S - D7_F); Delta8 = abs(D8_S - D8_F); Delta9 = abs(D9_S - D9_F); Delta10 = abs(D10_S - D10_F);
    if(Delta1 <= Treshold) Delta1 = 0; else if(Delta1 >= Sensitivity && Lock_Sens1 == false) {Time_Sens1_detection = millis(); Lock_Sens1 = true;}
    if(Delta2 <= Treshold) Delta2 = 0; else if(Delta2 >= Sensitivity && Lock_Sens2 == false) {Time_Sens2_detection = millis(); Lock_Sens2 = true;} 
    if(Delta3 <= Treshold) Delta3 = 0; else if(Delta3 >= Sensitivity && Lock_Sens3 == false) {Time_Sens3_detection = millis(); Lock_Sens3 = true;} 
    if(Delta4 <= Treshold) Delta4 = 0; else if(Delta4 >= Sensitivity && Lock_Sens4 == false) {Time_Sens4_detection = millis(); Lock_Sens4 = true;} 
    if(Delta5 <= Treshold) Delta5 = 0; else if(Delta5 >= Sensitivity && Lock_Sens5 == false) {Time_Sens5_detection = millis(); Lock_Sens5 = true;} 
    if(Delta6 <= Treshold) Delta6 = 0; else if(Delta6 >= Sensitivity && Lock_Sens6 == false) {Time_Sens6_detection = millis(); Lock_Sens6 = true;} 
    if(Delta7 <= Treshold) Delta7 = 0; else if(Delta7 >= Sensitivity && Lock_Sens7 == false) {Time_Sens7_detection = millis(); Lock_Sens7 = true;} 
    if(Delta8 <= Treshold) Delta8 = 0; else if(Delta8 >= Sensitivity && Lock_Sens8 == false) {Time_Sens8_detection = millis(); Lock_Sens8 = true;} 
    if(Delta9 <= Treshold) Delta9 = 0; else if(Delta9 >= Sensitivity && Lock_Sens9 == false) {Time_Sens9_detection = millis(); Lock_Sens9 = true;} 
    if(Delta10 <= Treshold) Delta10 = 0; else if(Delta10 >= Sensitivity && Lock_Sens10 == false) {Time_Sens10_detection = millis(); Lock_Sens10 = true;}
   
    if(((Time_Sens1_detection && Time_Sens2_detection) || (Time_Sens6_detection && Time_Sens7_detection)) > 0 && LoopAnswerY == false) {ANSWER_YES++; CLEAR_CASH(); LoopAnswerY = true;}  
    if(((Time_Sens9_detection || Time_Sens10_detection) || (Time_Sens4_detection && Time_Sens5_detection)) > 0 && LoopAnswerN == false ) {ANSWER_NO++; CLEAR_CASH(); LoopAnswerN = true;}
    if(Delta1 == 0 && Delta2 == 0 && Delta6 == 0 && Delta7 == 0 && LoopAnswerY == true) LoopAnswerY = false;
    if(Delta9 == 0 && Delta10 == 0 && Delta4 == 0 && Delta5 == 0 && LoopAnswerN == true) LoopAnswerN = false;
    if (ANSWER_YES >= 5) {ANSWER = 1; ANSWER_YES = 0; ANSWER_NO = 0;}
    if (ANSWER_NO >= 5) {ANSWER = 2; ANSWER_YES = 0; ANSWER_NO = 0;}    
   }     
    if(ANSWER == 2) {slave = 16; RED_EYE(); ANSWERTIME = true; Loop79 = false; TUPICA = false;}
    if(ANSWER == 1) {slave = 15; GREEN_EYE(); ANSWERTIME = true; Loop79 = false; TUPICA = false;}
    if(ANSWER == 0 && TUPICA == false) {SLOW_DARK_EYE();}

    if(ANSWERTIME == true && Loop78 == false) {t100 = millis(); Loop78 = true;}
    if(Loop78 == true && ((millis() - t100) >= delta_wait_answer*2)) {ANSWERTIME = false; ANSWER = 0; Loop78 = false;}        
}

void FEAR()
{  
 if(Loop5 == false) {Loop6 = false; for(int i = 0; i <= 8; i++){pixels.setPixelColor(i, pixels.Color(40,0,0)); pixels.show();} 
 for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 0, 0, 0); pixels1.show();}
 if(ServoSuperStart == true){myservo1.attach(s1); myservo2.attach(s2); myservo3.attach(s3); myservo4.attach(s4);} 
 for(int i = 180; i >= 0; i--) {myservo1.write(i); myservo2.write(i); myservo3.write(i); myservo4.write(i); delay(10);} 
 myservo1.detach(); myservo2.detach(); myservo3.detach(); myservo4.detach(); Loop5 = true; CLEAR_CASH();}
}

void RELAX()
{
 if(Loop6 == false) {Loop5 = false; for(int i = 0; i <= 8; i++){pixels.setPixelColor(i, pixels.Color(40,0,0)); pixels.show();} 
 if(ServoSuperStart == true) {myservo1.attach(s1); myservo2.attach(s2); myservo3.attach(s3); myservo4.attach(s4);} 
 for(int s = 0; s <= 180; s++) {myservo1.write(s); myservo2.write(s); myservo3.write(s); myservo4.write(s); delay(10);}  
 myservo1.detach(); myservo2.detach(); myservo3.detach(); myservo4.detach(); 
 for(int i = 0; i <= 8; i++){pixels.setPixelColor(i, pixels.Color(0,0,40)); delay(10); pixels.show();}
 for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 0, 0, 40); delay(10); pixels1.show();}
 Loop6 = true; CLEAR_CASH(); slave = 1;}
}

void DIRECTION()
{
  t5 = millis();
  
  if(Loop12 == false) {t15 = millis(); Loop12 = true;} if(((t5 - t15) >= servo_interval) && ServoSuperStart == false) ServoSuperStart = true;
  
  if(Loop11 == false) 
  {  
   Z_count = analogRead(Z); Y_count = analogRead(Y); Z_deg = map(Z_count, 260, 400, 0, 180); Y_deg = map(Y_count, 260, 400, 0, 180);
   constrain(Z_deg, 0, 180); constrain(Y_deg, 0, 180); t6 = millis();
   if((Z_deg >= 130)||(Z_deg <= 30)) POSITION_Z = false; else POSITION_Z = true; 
   if((Y_deg >= 130)||(Y_deg <= 50)) POSITION_Y = false; else POSITION_Y = true; 
   if(analogRead(0) <= dark && analogRead(1) <= dark && analogRead(2) <= dark && analogRead(3) <= dark && analogRead(4) <= dark
   && analogRead(5) <= dark && analogRead(6) <= dark && analogRead(7) <= dark && analogRead(8) <= dark && analogRead(9) <= dark) {LIGHT = false; slave = 10;}  else LIGHT = true;
   Loop11 = true;
  }
  if(abs(t5 - t6) >= axel_interval) Loop11 = false;
  
  if(POSITION_Z == true && POSITION_Y == true && Loop3 == false) {POSITION = true; Loop3 = true; f = 0; RELAX();}
  if(POSITION_Z == false || POSITION_Y == false) {slave = 9; POSITION = false; Loop3 = false; FEAR(); LED_PANIK();} //slave = 9
  
  //if(LIGHT == false && POSITION_Y == true && POSITION_Z == true) {POSITION = false; Loop3 = false; FEAR(); LED_PANIK();} //slave = 10
  //if((POSITION_Z == false && LIGHT == false) || (POSITION_Y == false && LIGHT == false)) {POSITION = false; Loop3 = false; FULL_FEAR(); LED_PANIK();}  //slave = 11
}

void SHAKING()
{  
   t1 = millis();
   if(SETTINGS == false) 
   {myservo1.attach(s1); myservo2.attach(s2); myservo3.attach(s3); myservo4.attach(s4); MAX_deg = 179; MIN_deg = 160; n = 0; count = random(0, 4); ServoSpeed = random(0, 3); 
   if(ServoSpeed == 0) ServoSpeed = 2; if(ServoSpeed == 1) ServoSpeed = 2; if(ServoSpeed == 2) ServoSpeed = 4; if(ServoSpeed == 3) ServoSpeed = 10; 
   if(count == 0) count = 2; if(count == 1) count = 4; if(count == 2) count = 6;
   SETTINGS = true;}
   if(SETTINGS == true && MOVE == false) 
   {if(ServoLoop == false) {t2 = millis(); if(ServoDirection == false) {pos++; ServoLoop = true;} else {pos--; ServoLoop = true;}} 
   if((t1 - t2) >= ServoSpeed) ServoLoop = false;
   if(pos <= MIN_deg && Loop10 == false) {ServoDirection = false; n++; RGB_servo_show();  
   Loop10 = true;} if(pos >= MAX_deg) {ServoDirection = true; Loop10 = false;} 
   pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); myservo2.write(pos); myservo3.write(pos); myservo4.write(pos);
   if(n >= count*2) {myservo1.detach(); myservo2.detach(); myservo3.detach(); myservo4.detach(); MOVE = true;}}
}

void ROUNDS()
{  
   t1 = millis();  
   if(SETTINGS == false) 
   {myservo1.attach(s1); myservo2.attach(s2); myservo3.attach(s3); myservo4.attach(s4); MAX_deg = 179; MIN_deg = 120; n = 0; rounds_count = 0; count = random(0, 3); ServoSpeed = random(0, 3); script = random(0, 3);
   if(ServoSpeed == 0) ServoSpeed = 2; if(ServoSpeed == 2) ServoSpeed = 4; if(ServoSpeed == 2) ServoSpeed = 8; 
   if(count == 0) count = 1; if(count == 1) count = 2; if(count == 2) count = 3;
   myservo1.write(MAX_deg); myservo2.write(MAX_deg); myservo3.write(MAX_deg); myservo4.write(MAX_deg);
   SETTINGS = true;}
   if(SETTINGS == true && MOVE == false) 
   {if(ServoLoop == false) {t2 = millis(); if(ServoDirection == false) {pos++; ServoLoop = true;} else {pos--; ServoLoop = true;}} if((t1 - t2) >= ServoSpeed) ServoLoop = false;
   if(pos <= MIN_deg) {ServoDirection = false;  Loop10 = false;} if(pos >= MAX_deg && Loop10 == false) {n++; RGB_servo_show(); ServoDirection = true; Loop10 = true;}
                          if(Servo1_move == false) {pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); if(n >= 1) Servo1_move = true;}
   if(Servo2_move == false && Servo1_move == true) {pos = abs(pos); pos = constrain(pos, 1, 179); myservo2.write(pos); if(n >= 2) Servo2_move = true;}
   if(Servo3_move == false && Servo2_move == true) {pos = abs(pos); pos = constrain(pos, 1, 179); myservo3.write(pos); if(n >= 3) Servo3_move = true;} 
   if(Servo4_move == false && Servo3_move == true) {pos = abs(pos); pos = constrain(pos, 1, 179); myservo4.write(pos); if(n >= 4) Servo4_move = true;}

   if(Servo1_move == true && Servo2_move == true && Servo3_move == true && Servo4_move == true) {rounds_count++; n = 0;}
   if(Servo1_move == true && Servo2_move == true && Servo3_move == true && Servo4_move == true && rounds_count <= count) {Servo1_move = false; Servo2_move = false; Servo3_move = false; Servo4_move = false;} 
   if(rounds_count >= count) {myservo1.detach(); myservo2.detach(); myservo3.detach(); myservo4.detach(); MOVE = true;}}
}

void HELLO()
{  
   t1 = millis();
   if(SETTINGS == false) 
   {MAX_deg = 179; MIN_deg = 70; pos = MAX_deg; n = 0; count = random(0, 2); ServoSpeed = 10; SETTINGS = true;}
   if(SETTINGS == true && MOVE == false && count == 0)
   {myservo1.attach(s1); if(pos >= MAX_deg && Loop10 == false) {ServoDirection = false; n++; RGB_servo_show();    
   Loop10 = true;} if(pos <= MIN_deg) {ServoDirection = true; Loop10 = false;} 
   if(ServoLoop == false) {t2 = millis(); if(ServoDirection == false) {pos--; ServoLoop = true;} else {pos++; ServoLoop = true;}} if((t1 - t2) >= ServoSpeed) ServoLoop = false;
   pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); if(n >= 3) {myservo1.detach(); MOVE = true;}}
   if(SETTINGS == true && MOVE == false && count == 1)
   {myservo2.attach(s2); if(pos >= MAX_deg && Loop10 == false) {ServoDirection = false; n++; RGB_servo_show(); Loop10 = true;} if(pos <= MIN_deg) {ServoDirection = true; Loop10 = false;} 
   if(ServoLoop == false) {t2 = millis(); if(ServoDirection == false) {pos--; ServoLoop = true;} else {pos++; ServoLoop = true;}} if((t1 - t2) >= ServoSpeed) ServoLoop = false;
   pos = abs(pos); pos = constrain(pos, 1, 179); myservo2.write(pos); if(n >= 3) {myservo2.detach(); MOVE = true;}}   
}

void HIP_HOP()
{  
   t1 = millis();
   if(SETTINGS == false) 
   {MAX_deg = 179; MIN_deg = 70; pos = MAX_deg; n = 0; count = random(0, 2); ServoSpeed = 5; SETTINGS = true;}
  
   if(SETTINGS == true && MOVE == false && count == 0)
   {myservo1.attach(s1); myservo3.attach(s3); if(pos >= MAX_deg && Loop10 == false) {ServoDirection = false; n++; RGB_servo_show();  
   Loop10 = true;} if(pos <= MIN_deg) {ServoDirection = true; Loop10 = false;} 
    if(ServoLoop == false) {t2 = millis(); if(ServoDirection == false) {pos--; ServoLoop = true;} else {pos++; ServoLoop = true;}} if((t1 - t2) >= ServoSpeed) ServoLoop = false;
    pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); myservo3.write(pos); if(n >= 3) {myservo1.detach(); myservo3.detach(); MOVE = true;}}

   if(SETTINGS == true && MOVE == false && count == 1)
   {myservo2.attach(s2); myservo4.attach(s4); if(pos >= MAX_deg && Loop10 == false) {ServoDirection = false; n++; RGB_servo_show(); Loop10 = true;} if(pos <= MIN_deg) {ServoDirection = true; Loop10 = false;} 
    if(ServoLoop == false) {t2 = millis(); if(ServoDirection == false) {pos--; ServoLoop = true;} else {pos++; ServoLoop = true;}} if((t1 - t2) >= ServoSpeed) ServoLoop = false;
    pos = abs(pos); pos = constrain(pos, 1, 179); myservo2.write(pos); myservo4.write(pos); if(n >= 3) {myservo2.detach(); myservo4.detach(); MOVE = true;}}  
}

void SHELL()
{
   t1 = millis();
   if(SETTINGS == false) 
   {MAX_deg = 179; MIN_deg = 10; pos = MAX_deg; n = 0; ServoSpeed = 5; SETTINGS = true;}
   if(SETTINGS == true && MOVE == false)
   {myservo1.attach(s1); myservo2.attach(s2); myservo3.attach(s3); myservo4.attach(s4); if(pos >= MAX_deg && Loop10 == false) {ServoDirection = false; n++; RGB_servo_show(); Loop10 = true;} 
   if(pos <= MIN_deg) {ServoDirection = true;    
   Loop10 = false;} if(ServoLoop == false) {t2 = millis(); if(ServoDirection == false) {pos--; ServoLoop = true;} else {pos++; ServoLoop = true;}} 
   if((t1 - t2) >= ServoSpeed) ServoLoop = false;
   pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); myservo2.write(pos); myservo3.write(pos); myservo4.write(pos); if(n >= 2) 
   {myservo1.detach(); myservo2.detach(); myservo3.detach(); myservo4.detach(); MOVE = true;}}
}

void SIT_UP()
{  
   t1 = millis();
   if(SETTINGS == false) 
   {MAX_deg = 179; MIN_deg = 10; pos = MAX_deg; n = 0; count = random(0, 2); ServoSpeed = 10; SETTINGS = true;}
  
   if(SETTINGS == true && MOVE == false && count == 0)
   {myservo1.attach(s1); myservo2.attach(s2); if(pos >= MAX_deg && Loop10 == false) {ServoDirection = false; n++; RGB_servo_show(); 
   Loop10 = true;} if(pos <= MIN_deg) {ServoDirection = true; Loop10 = false;} 
   if(ServoLoop == false) {t2 = millis(); if(ServoDirection == false) {pos--; ServoLoop = true;} else {pos++; ServoLoop = true;}} if((t1 - t2) >= ServoSpeed) ServoLoop = false;
   pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); myservo2.write(pos); if(n >= 2) {myservo1.detach(); myservo2.detach(); MOVE = true;}}

   if(SETTINGS == true && MOVE == false && count == 1)
   {myservo3.attach(s3); myservo4.attach(s4); if(pos >= MAX_deg && Loop10 == false) {ServoDirection = false; n++; RGB_servo_show(); Loop10 = true;} if(pos <= MIN_deg) {ServoDirection = true; Loop10 = false;} 
   if(ServoLoop == false) {t2 = millis(); if(ServoDirection == false) {pos--; ServoLoop = true;} else {pos++; ServoLoop = true;}} if((t1 - t2) >= ServoSpeed) ServoLoop = false;
   pos = abs(pos); pos = constrain(pos, 1, 179); myservo3.write(pos); myservo4.write(pos); if(n >= 2) {myservo3.detach(); myservo4.detach(); MOVE = true;}} 
}

void HEARS_Pi()
{  
   t1 = millis();
   if(SETTINGS == false) 
   {MAX_deg = 179; MIN_deg = 10; pos = MAX_deg; n = 0; ServoSpeed = 10; SETTINGS = true;}
  
   if(SETTINGS == true && MOVE == false)
   {myservo1.attach(s1); myservo2.attach(s2); if(pos >= MAX_deg && Loop10 == false) {ServoDirection = false; n++; RGB_servo_show(); 
   Loop10 = true;} if(pos <= MIN_deg) {ServoDirection = true; Loop10 = false;} 
   if(ServoLoop == false) {t2 = millis(); if(ServoDirection == false) {pos--; ServoLoop = true;} else {pos++; ServoLoop = true;}} if((t1 - t2) >= ServoSpeed) ServoLoop = false;
   pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); myservo2.write(pos); if(n >= 2) {myservo1.detach(); myservo2.detach(); MOVE = true;}}
}

void LEGS_Pi()
{  
   t1 = millis();
   if(SETTINGS == false) 
   {MAX_deg = 179; MIN_deg = 10; pos = MAX_deg; n = 0; ServoSpeed = 10; SETTINGS = true;}

   if(SETTINGS == true && MOVE == false)
   {myservo3.attach(s3); myservo4.attach(s4); if(pos >= MAX_deg && Loop10 == false) {ServoDirection = false; n++; RGB_servo_show(); Loop10 = true;} if(pos <= MIN_deg) {ServoDirection = true; Loop10 = false;} 
   if(ServoLoop == false) {t2 = millis(); if(ServoDirection == false) {pos--; ServoLoop = true;} else {pos++; ServoLoop = true;}} if((t1 - t2) >= ServoSpeed) ServoLoop = false;
   pos = abs(pos); pos = constrain(pos, 1, 179); myservo3.write(pos); myservo4.write(pos); if(n >= 2) {myservo3.detach(); myservo4.detach(); MOVE = true;}}  
}

void MUSIC_AUTOMAT()
{
  t3 = millis();
  
  if(START_MACHINE == false){
  for (b=0; b < 128; b++){val = analogRead(AUDIOPIN); data[b] = val; im[b] = 0;} fix_fft(data,im,7,0); for (b=0; b<3; b++) {data[b] = sqrt(data[b] * data[b] + im[b] * im[b]);
  
  if (b == 0) {out = data[b];
  if ((out >= 3 && out <= 5) && BurnLED_R == false) {BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true; 
  red++; R_flash = true; }
  if ((out >= 6 && out <= 10) && BurnLED_O == false) {BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true; 
  orange++; O_flash = true;}}     
  
  
  if (b == 1) {out = data[b];
  if ((out >= 3 && out <= 5) && BurnLED_B == false) {BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true; 
  blue++; G_flash = true;}
  if ((out >= 6 && out <= 10) && BurnLED_V == false) {BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true; 
  violet++; Y_flash = true;}} 
  
  
  if (b == 2) {out = data[b];
  if ((out >= 3 && out <= 5) && BurnLED_G == false) {BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
  green++; B_flash = true;}
  if ((out >= 6 && out <= 10) && BurnLED_Y == false) {BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true; 
  yellow++; V_flash = true;}}}

  if((t3 - t4) >= light_interval){t4 = 0; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 0, 0, 0); pixels.show();} for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 0, 0, 0); pixels1.show();}}
   
  
  if(R_flash == true){t4 = millis(); red++; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 40, 0, 0); pixels.show();}
                                            for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 0, 40, 0); pixels1.show();}
  R_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;}
  
  if(G_flash == true){t4 = millis(); green++; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 0, 40, 0); pixels.show();}
                                              for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 0, 0, 40); pixels1.show();} 
  G_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;}
  
  if(B_flash == true){t4 = millis(); blue++; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 0, 0, 40); pixels.show();}
                                             for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 40, 0, 0); pixels1.show();} 
  B_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;}
  
  if(O_flash == true){t4 = millis(); orange++; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 40, 40, 0); pixels.show();}
                                               for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 0, 40, 40); pixels1.show();}  
  O_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;}
  
  if(Y_flash == true){t4 = millis(); yellow++; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 0, 40, 40); pixels.show();}
                                               for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 40, 40, 0); pixels1.show();}                               
  Y_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;}
  
  if(V_flash == true){t4 = millis(); violet++; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 40, 0, 40); pixels.show();}
                                               for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 0, 26, 40); pixels1.show();} 
  V_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;}                    
} 
 red_action = 50;
 orange_action = 60;
 green_action = 35;
 blue_action = 25;
 yellow_action = 7;
 violet_action = 15;
  
 if(red >= red_action){START_MACHINE = true; SHAKING(); if(n >= count*2) {red = 0; Loop10 = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;}}
 if(green >= green_action){START_MACHINE = true; ROUNDS(); if(rounds_count >= count) {green = 0; Loop10 = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;}}
 if(blue >= blue_action){START_MACHINE = true; HELLO(); if(n >= 3) {Loop10 = false; blue = 0; Loop10 = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;}} 
 if(orange >= orange_action){START_MACHINE = true; HIP_HOP(); if(n >= 3) {orange = 0;  Loop10 = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;}}
 if(yellow >= yellow_action){START_MACHINE = true; SIT_UP(); if(n >= 2) {yellow = 0; Loop10 = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;}}
 if(violet >= violet_action){START_MACHINE = true; SHELL(); if(n >= 2) {violet = 0; Loop10 = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;}}   
}


void RGB_servo_show()
{
    label1: script = random(0, 3); script1 = random(0, 3); script2 = random(0, 3); 
    label2: script3 = random(0, 3); script4 = random(0, 3); script5 = random(0, 3);
    if(script == 0 && script1 == 0 && script2 == 0) goto label1;
    if(script3 == 0 && script4 == 0 && script5 == 0) goto label2; 
   
    switch(script) {
    case 0: {Rp = 0;} break;
    case 1: {Rp = 20;} break;
    case 2: {Rp = 40;} break;
    }
    switch(script1) {
    case 0: {Bp = 0;} break;
    case 1: {Bp = 20;} break;
    case 2: {Bp = 40;} break;
    }   
    switch(script2) {
    case 0: {Gp = 0;} break;
    case 1: {Gp = 20;} break;
    case 2: {Gp = 40;} break;
    }
    switch(script3) {
    case 0: {Rp1 = 0;} break;
    case 1: {Rp1 = 20;} break;
    case 2: {Rp1 = 40;} break;
    }
    switch(script4) {
    case 0: {Bp1 = 0;} break;
    case 1: {Bp1 = 20;} break;
    case 2: {Bp1 = 40;} break;
    }
    switch(script5) {
    case 0: {Gp1 = 0;} break;
    case 1: {Gp1 = 20;} break;
    case 2: {Gp1 = 40;} break;
   }      
   for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, Rp, Bp, Gp); pixels.show();}
   for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, Rp1, Bp1, Gp1); pixels1.show();}
}

void SCANDAL()
{
  t3 = millis();
  if(START_MACHINE == false){
  for (b=0; b < 128; b++){val = analogRead(AUDIOPIN); data[b] = val; im[b] = 0;} fix_fft(data,im,7,0); for (b=0; b<3; b++) {data[b] = sqrt(data[b] * data[b] + im[b] * im[b]);
  
  if (b == 0) {out = data[b];
  if ((out >= 3 && out <= 5) && BurnLED_R == false) {BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true; 
  red++; R_flash = true; }
  if ((out >= 6 && out <= 10) && BurnLED_O == false) {BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true; 
  orange++; O_flash = true;}}     
  
  
  if (b == 1) {out = data[b];
  if ((out >= 3 && out <= 5) && BurnLED_B == false) {BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true; 
  blue++; G_flash = true;}
  if ((out >= 6 && out <= 10) && BurnLED_V == false) {BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true; 
  violet++; Y_flash = true;}} 
  
  
  if (b == 2) {out = data[b];
  if ((out >= 3 && out <= 5) && BurnLED_G == false) {BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
  green++; B_flash = true;}
  if ((out >= 6 && out <= 10) && BurnLED_Y == false) {BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true; 
  yellow++; V_flash = true;}}}

  if((t3 - t4) >= light_interval){t4 = 0; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 0, 0, 0); pixels.show();} for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 0, 0, 0); pixels1.show();}}
   
  
  if(R_flash == true){t4 = millis(); red++; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 40, 0, 0); pixels.show();}
                                            for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 0, 40, 0); pixels1.show();}
  R_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;}
  
  if(G_flash == true){t4 = millis(); green++; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 0, 40, 0); pixels.show();}
                                              for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 0, 0, 40); pixels1.show();} 
  G_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;}
  
  if(B_flash == true){t4 = millis(); blue++; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 0, 0, 40); pixels.show();}
                                             for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 40, 0, 0); pixels1.show();} 
  B_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;}
  
  if(O_flash == true){t4 = millis(); orange++; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 40, 40, 0); pixels.show();}
                                               for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 0, 40, 40); pixels1.show();}  
  O_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;}
  
  if(Y_flash == true){t4 = millis(); yellow++; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 0, 40, 40); pixels.show();}
                                               for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 40, 40, 0); pixels1.show();}                               
  Y_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;}
  
  if(V_flash == true){t4 = millis(); violet++; for(int i = 0; i <= 8; i++) {pixels.setPixelColor(i, 40, 0, 40); pixels.show();}
                                               for(int i = 0; i <= 22; i++) {pixels1.setPixelColor(i, 0, 26, 40); pixels1.show();} 
  V_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;}                    
} 
 red_action = 10;
 orange_action = 5;
 green_action = 2;
 blue_action = 1;
 yellow_action = 2;
 violet_action = 1;
  
 if(red >= red_action){START_MACHINE = true; SHAKING(); if(n >= count*2) {red = 0; Loop10 = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;}}
 if(green >= green_action){START_MACHINE = true; ROUNDS(); if(rounds_count >= count) {green = 0; Loop10 = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;}}
 if(blue >= blue_action){START_MACHINE = true; HELLO(); if(n >= 3) {Loop10 = false; blue = 0; Loop10 = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;}} 
 if(orange >= orange_action){START_MACHINE = true; HIP_HOP(); if(n >= 3) {orange = 0;  Loop10 = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;}}
 if(yellow >= yellow_action){START_MACHINE = true; SIT_UP(); if(n >= 2) {yellow = 0; Loop10 = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;}}
 if(violet >= violet_action){START_MACHINE = true; SHELL(); if(n >= 2) {violet = 0; Loop10 = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;}}   
} 


  
void LOVE(uint8_t wait) 
  {
    ShowTime++;
    uint16_t i, j; for(j=0; j<(Love_Speed +1)*5; j++) 
    {
      for(i=0; i< strip.numPixels(); i++) 
      {strip.setPixelColor(i, Wheel(((i * (Love_Speed + 1)/ strip.numPixels()) + j) & Love_Speed));} 
      strip.show(); delay(wait);

      for(i=0; i< strip1.numPixels(); i++) 
      {strip1.setPixelColor(i, Wheel(((i * (Love_Speed + 1) / strip1.numPixels()) + j) & Love_Speed));} 
      strip1.show(); delay(wait);   
    }   
  }
  uint32_t Wheel(byte WheelPos) {WheelPos = Love_Speed - WheelPos; if(WheelPos < Love_Speed1) 
  {return strip.Color(Love_Speed - WheelPos * 3, 0, WheelPos * 3); return strip1.Color(Love_Speed - WheelPos * 3, 0, WheelPos * 3);}
  if(WheelPos < Love_Speed2) {WheelPos -= Love_Speed1; return strip.Color(0, WheelPos * 3, Love_Speed - WheelPos * 3); 
  return strip1.Color(0, WheelPos * 3, Love_Speed - WheelPos * 3);} WheelPos -= Love_Speed2; return strip.Color(WheelPos * 3, Love_Speed - WheelPos * 3, 0); 
  return strip1.Color(WheelPos * 3, Love_Speed - WheelPos * 3, 0);}



void ZERO_POINT()
{
  Loop14 = false; 
  myservo1.detach(); myservo2.detach(); myservo3.detach(); myservo4.detach(); MOVE = false; 
  SETTINGS = false; Loop10 = false; ShowTime = 0; Command_Status = false; COMPLEX = 0; ANSWERTIME = false; ANSWER = 0; Loop78 = false; slave = 1;
}


void BIG_DIRECTOR()
{
  if(Read_Status == false) {t20 = millis(); bit_1_input = digitalRead(I1); bit_2_input = digitalRead(I2); bit_3_input = digitalRead(I3); bit_4_input = digitalRead(I4); Read_Status = true;} //если сигнал 0000 изменился, засекаем момент читаем пины//
  if(((millis() - t20) >= speed_read) && Read_Status == true) Read_Status = false; //если интервал для выяснения комбинации прошел, то опять читаем пины//
  
  if (Command_Status == false)
  {
   //if(bit_1_input == 0 && bit_2_input == 0 && bit_3_input == 0 && bit_4_input == 0) {director = 1; slave = 1;} //0000//
   if(bit_1_input == 1 && bit_2_input == 1 && bit_3_input == 1 && bit_4_input == 1) {director = 2; RGB_servo_show(); Command_Status = true;} //1111//
   if(bit_1_input == 1 && bit_2_input == 0 && bit_3_input == 0 && bit_4_input == 0) {director = 3; RGB_servo_show(); Command_Status = true;} //1000//
   if(bit_1_input == 1 && bit_2_input == 1 && bit_3_input == 0 && bit_4_input == 0) {director = 4; RGB_servo_show(); Command_Status = true;} //1100//
   if(bit_1_input == 1 && bit_2_input == 1 && bit_3_input == 1 && bit_4_input == 0) {director = 5; RGB_servo_show(); Command_Status = true;} //1110//
   if(bit_1_input == 0 && bit_2_input == 0 && bit_3_input == 0 && bit_4_input == 1) {director = 6; RGB_servo_show(); Command_Status = true;} //0001//
   if(bit_1_input == 0 && bit_2_input == 0 && bit_3_input == 1 && bit_4_input == 1) {director = 7; RGB_servo_show(); Command_Status = true;} //0011//
   if(bit_1_input == 0 && bit_2_input == 1 && bit_3_input == 1 && bit_4_input == 1) {director = 8; RGB_servo_show(); Command_Status = true;} //0111//
   if(bit_1_input == 0 && bit_2_input == 1 && bit_3_input == 0 && bit_4_input == 1) {director = 9; RGB_servo_show(); Command_Status = true;} //0101//
   if(bit_1_input == 1 && bit_2_input == 0 && bit_3_input == 1 && bit_4_input == 0) {director = 10; RGB_servo_show(); Command_Status = true;} //1010//
   if(bit_1_input == 1 && bit_2_input == 0 && bit_3_input == 0 && bit_4_input == 1) {director = 11; Command_Status = true;} //1001//
   if(bit_1_input == 0 && bit_2_input == 1 && bit_3_input == 1 && bit_4_input == 0) {director = 12; Command_Status = true;} //0110//
   if(bit_1_input == 1 && bit_2_input == 0 && bit_3_input == 1 && bit_4_input == 1) {director = 13; Command_Status = true;} //1011//
   //if(bit_1_input == 1 && bit_2_input == 1 && bit_3_input == 0 && bit_4_input == 1) {director = 14; slave = 2; RGB_servo_show(); Command_Status = true;} //1101//
   if(bit_1_input == 0 && bit_2_input == 1 && bit_3_input == 0 && bit_4_input == 0) {director = 15; Command_Status = true;} //0100//
   //if(bit_1_input == 0 && bit_2_input == 0 && bit_3_input == 1 && bit_4_input == 0) {director = 16; slave = 2; RGB_servo_show(); Command_Status = true;} //0010//
  } 
   switch (director) 
 {
  case 2: {if(Command_Status == true) {SHAKING(); if(MOVE == true) ZERO_POINT();}} break; //1111//
  case 3: {if(Command_Status == true) {SHELL(); if(MOVE == true) ZERO_POINT();}} break; //1000//
  case 4: {if(Command_Status == true) {HELLO(); if(MOVE == true) ZERO_POINT();}} break; //1100//       
  case 5: {if(Command_Status == true) {ROUNDS(); if(MOVE == true) ZERO_POINT();}} break; //1110//
  case 6: {if(Command_Status == true) {HIP_HOP(); if(MOVE == true) ZERO_POINT();}} break; //0001//
  case 7: {if(Command_Status == true) {HEARS_Pi(); if(MOVE == true) ZERO_POINT();}} break; //0011//
  case 8: {if(Command_Status == true) {LEGS_Pi(); if(MOVE == true) ZERO_POINT();}} break; //0111//
  case 9: {if(Command_Status == true && ShowTime < 1) {Love_Speed = 255; Love_Speed1 = 85; Love_Speed2 = 170; LOVE(5);} else {SLOW_DARK_EYE(); ZERO_POINT();}} break; //0101//
  case 10: {if(Command_Status == true && ShowTime < 1) {Love_Speed = 40; Love_Speed1 = 20; Love_Speed2 = 120; LOVE(20);} else {SLOW_DARK_EYE(); ZERO_POINT();}} break; //1010//
  case 11: {if(Command_Status == true && COMPLEX <= 2) SCANDAL(); else {SLOW_DARK_EYE(); ZERO_POINT();}} break; //1001//
  case 12: {if(Command_Status == true && COMPLEX <= 2) MUSIC_AUTOMAT(); else {SLOW_DARK_EYE(); ZERO_POINT();}} break; //0110//
  case 13: {Command_Status = false; YES_NO();} break; //1011//
  //case 14: {ZERO_POINT();} break; //1101//
  case 15: {ZERO_POINT();} break; //0100//
  //case 16: {ZERO_POINT();} break; //0010//       
  }     
}

void CallSlave()
{
  switch (slave) 
 {
  case 1: {digitalWrite(O1, LOW); digitalWrite(O2, LOW); digitalWrite(O3, LOW); digitalWrite(O4, LOW);} break; //0000//
  case 2: {digitalWrite(O1, HIGH); digitalWrite(O2, HIGH); digitalWrite(O3, HIGH); digitalWrite(O4, HIGH);} break;  //1111//
  case 3: {digitalWrite(O1, HIGH); digitalWrite(O2, LOW); digitalWrite(O3, LOW); digitalWrite(O4, LOW);} break;  //1000//
  case 4: {digitalWrite(O1, HIGH); digitalWrite(O2, HIGH); digitalWrite(O3, LOW); digitalWrite(O4, LOW);} break;  //1100//
  case 5: {digitalWrite(O1, HIGH); digitalWrite(O2, HIGH); digitalWrite(O3, HIGH); digitalWrite(O4, LOW);} break;  //1110//
  case 6: {digitalWrite(O1, LOW); digitalWrite(O2, LOW); digitalWrite(O3, LOW); digitalWrite(O4, HIGH);} break;  //0001//
  case 7: {digitalWrite(O1, LOW); digitalWrite(O2, LOW); digitalWrite(O3, HIGH); digitalWrite(O4, HIGH);} break;  //0011//
  case 8: {digitalWrite(O1, LOW); digitalWrite(O2, HIGH); digitalWrite(O3, HIGH); digitalWrite(O4, HIGH);} break;  //0111//
  case 9: {digitalWrite(O1, LOW); digitalWrite(O2, HIGH); digitalWrite(O3, LOW); digitalWrite(O4, HIGH);} break;  //0101//
  case 10: {digitalWrite(O1, HIGH); digitalWrite(O2, LOW); digitalWrite(O3, HIGH); digitalWrite(O4, LOW);} break;  //1010//
  case 11: {digitalWrite(O1, HIGH); digitalWrite(O2, LOW); digitalWrite(O3, LOW); digitalWrite(O4, HIGH);} break;  //1001//
  case 12: {digitalWrite(O1, LOW); digitalWrite(O2, HIGH); digitalWrite(O3, HIGH); digitalWrite(O4, LOW);} break;  //0110//
  case 13: {digitalWrite(O1, HIGH); digitalWrite(O2, LOW); digitalWrite(O3, HIGH); digitalWrite(O4, HIGH);} break;  //1011//
  case 14: {digitalWrite(O1, HIGH); digitalWrite(O2, HIGH); digitalWrite(O3, LOW); digitalWrite(O4, HIGH);} break;  //1101//
  case 15: {digitalWrite(O1, LOW); digitalWrite(O2, HIGH); digitalWrite(O3, LOW); digitalWrite(O4, LOW);} break;  //0100// 
  case 16: {digitalWrite(O1, LOW); digitalWrite(O2, LOW); digitalWrite(O3, HIGH); digitalWrite(O4, LOW);} break;  //0010// 
 }  
}


void SerialPrintDirector()
{
 Serial.print(director);
 Serial.print("  "); 
 Serial.println();
}

void SerialPrintSlave()
{
 Serial.print(ANSWER);
 Serial.print("  ");
 Serial.print(slave);
 Serial.print("  ");
 //Serial.print(ff);
 Serial.print("  ");   
 Serial.println();
}

void SerialPrintN()
{
 Serial.print(n); 
 Serial.println();
}

void SerialPrintDIR()
{
  Z_count = analogRead(Z); 
  Y_count = analogRead(Y);
  delay(300);
  Serial.print(Z_count);
  Serial.print("  ");
  Serial.print(Y_count);                   
  Serial.println();
}

void SerialPrintMM()
{
  Serial.print(red);
  Serial.print("  ");
  Serial.print(green);
  Serial.print("  "); 
  Serial.print(blue);
  Serial.print("  "); 
  Serial.print(orange);
  Serial.print("  "); 
  Serial.print(yellow);
  Serial.print("  ");
  Serial.print(violet);
  Serial.print("  ");                    
  Serial.println();
}

void loop() 
{ 
   CallSlave();
   BIG_DIRECTOR(); 
}
