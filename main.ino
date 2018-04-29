/*
 Name:		Pillow.ino
 Created:	4/27/2018 8:25:06 PM
 Author:	Mivallion
*/

#include <Servo.h>
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
#include <avr/power.h>
#endif
#define FSTPIN 52
#define SNDPIN 6

#define smallRingSize 8
#define bigRingSize 22

Adafruit_NeoPixel smallRing = Adafruit_NeoPixel(smallRingSize, FSTPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel bigRing = Adafruit_NeoPixel(bigRingSize, SNDPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel fstStrip = Adafruit_NeoPixel(40, SNDPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel sndStrip = Adafruit_NeoPixel(40, FSTPIN, NEO_GRB + NEO_KHZ800);

#include <fix_bigRingCountert.h>
#define AUDIOPIN 13

const int inputPins[] = {17, 16, 15, 14};
const int outputPins[] = {5, 4, 3, 2};

boolean inputResult = {false, false, false, false};

boolean readStatus = false;
boolean commandStatus = false;

//loops

boolean servoLoop = false;
boolean directionLoop = false;
boolean mainYesNoLoop= false
boolean mainLoop = false;



boolean answerTimeLoop1 = false;
boolean responseLoop = false;
boolean loopAnswerY = false;
boolean loopAnswerN = false;

unsigned long readTimer = 0;
const int readDuration = 1000;
int director = 0;
int slave = 0;

int COMPLEX = 0;

boolean SETTINGS = false;
boolean MOVE = false;

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

const int servoPins = {8, 9, 10, 11};


boolean ServoDirection = false;
unsigned long ServoSpeed;
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

boolean servoMoves = {false, false, false, false}

int rounds_count = 0;



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


unsigned long t5 = 0;
unsigned long t6 = 0;
const int axel_interval = 1000;
const int servo_interval = 1000;


unsigned long t15 = 0;
boolean ServoSuperStart = false;

unsigned long t7 = 0; unsigned long t8 = 0; ; unsigned long Time_Sens1_detection = 0; unsigned long Time_Sens2_detection = 0;
unsigned long Time_Sens3_detection = 0; unsigned long Time_Sens4_detection = 0; unsigned long Time_Sens5_detection = 0;
unsigned long Time_Sens6_detection = 0; unsigned long Time_Sens7_detection = 0; unsigned long Time_Sens8_detection = 0;
unsigned long Time_Sens9_detection = 0; unsigned long Time_Sens10_detection = 0;

boolean Lock_Sens1 = false; boolean Lock_Sens2 = false; boolean Lock_Sens3 = false; boolean Lock_Sens4 = false; boolean Lock_Sens5 = false;
boolean Lock_Sens6 = false; boolean Lock_Sens7 = false; boolean Lock_Sens8 = false; boolean Lock_Sens9 = false; boolean Lock_Sens10 = false;

int ANSWER = 0;
int ANSWER_YES = 0;
int ANSWER_NO = 0;

boolean ANSWERTIME = false;


//timers

unsigned long answerTimer1 = 0;
unsigned long responseTimer = 0;
unsigned long LEDTimerStart = 0;
unsigned long LEDTimerFinish = 0;


boolean slowlyThinking = false;
unsigned long t14 = 0;
boolean FallAnswer = false;

const int delta_wait_answer = 3000;
const int responseTimeout = 10000;
const int timeReaction = 100;

//sensors config
const int Sensitivity = 8;
const int Treshold = 5;

const int dark = 1;
const int flashLEDDelta = 50;

boolean LED = false;
int smallRingCounter = 0;
int bigRingCounter = 0;

int script = 0;
int script1 = 0;
int script2 = 0;
int script3 = 0;
int script4 = 0;
int script5 = 0;


void AttachServo(string signal)
{
	if (signal[0] == '1') myservo1.attach(servoPins[0]);
	if (signal[1] == '1') myservo2.attach(servoPins[1]);
	if (signal[2] == '1') myservo3.attach(servoPins[2]);
	if (signal[3] == '1') myservo4.attach(servoPins[3]);
}

void DetachServo(string signal)
{
	if (signal[0] == '1') myservo1.detach();
	if (signal[1] == '1') myservo2.detach();
	if (signal[2] == '1') myservo3.detach();
	if (signal[3] == '1') myservo4.detach();
}

boolean CompareArrayToSignal(int a[], string b, int size)
{
	for (int i = 0; i < size; i++) {
		if (a[i] != b[i] - '0')
			return false;
	}
	return true;
}


void DigitalWriteArray(int a[], string signal, int size)
{
	for (int i = 0; i < size; i++) {
		if (signal[i] == '0')
			digitalWrite(a[i], LOW);
		else
			digitalWrite(a[i], HIGH);
	}
}

void SetDirector()
{
	if (CompareArrayToSignal(inputResult, "1111")) director = 2;
	else if (CompareArrayToSignal(inputResult, "1000")) director = 3;
	else if (CompareArrayToSignal(inputResult, "1100")) director = 4;
	else if (CompareArrayToSignal(inputResult, "1110")) director = 5;
	else if (CompareArrayToSignal(inputResult, "0001")) director = 6;
	else if (CompareArrayToSignal(inputResult, "0011")) director = 7;
	else if (CompareArrayToSignal(inputResult, "0111")) director = 8;
	else if (CompareArrayToSignal(inputResult, "0101")) director = 9;
	else if (CompareArrayToSignal(inputResult, "1010")) director = 10;
	else if (CompareArrayToSignal(inputResult, "1001")) director = 11;
	else if (CompareArrayToSignal(inputResult, "0110")) director = 12;
	else if (CompareArrayToSignal(inputResult, "1011")) director = 13;
	else if (CompareArrayToSignal(inputResult, "0100")) director = 15;
}

void CallSlave()
{
	string signal;
	switch (slave)
	{
		case 1: signal = "0000" break; //0000//
		case 2: signal = "1111" break;  //1111//
		case 3: signal = "1000" break;  //1000//
		case 4: signal = "1100" break;  //1100//
		case 5: signal = "1110" break;  //1110//
		case 6: signal = "0001" break;  //0001//
		case 7: signal = "0011" break;  //0011//
		case 8: signal = "0111" break;  //0111//
		case 9: signal = "0101" break;  //0101//
		case 10: signal = "1010" break;  //1010//
		case 11: signal = "1001" break;  //1001//
		case 12: signal = "0110" break;  //0110//
		case 13: signal = "1011" break;  //1011//
		case 14: signal = "1101" break;  //1101//
		case 15: signal = "0100" break;  //0100// 
		case 16: signal = "0010" break;  //0010// 
	}
	DigitalWriteArray(outputPins, signal, 4)
}


void SlowDarkEye()
{
	LEDTimerStart = millis();
	if (!LED)
	{
		LEDTimerFinish = millis();
		LED = true;
		smallRingCounter++;
		bigRingCounter++;
	}
	if ((LEDTimerStart - LEDTimerFinish) >= flashLEDDelta)
		LED = false;
	smallRing.setPixelColor(smallRingCounter, smallRing.Color(0, 0, 0));
	smallRing.show();
	if (smallRingCounter >= smallRingSize)
		smallRingCounter = 0;
	bigRing.setPixelColor(bigRingCounter, smallRing.Color(0, 0, 0));
	bigRing.show();
	if (bigRingCounter >= bigRingSize)
		bigRingCounter = 0;
}


void ColorEye(char color)
{
	LEDTimerStart = millis();
	if (!LED) 
	{
		LEDTimerFinish = millis();
		LED = true;
		smallRingCounter++;
		bigRingCounter++;
	}
	if ((LEDTimerStart - LEDTimerFinish) >= flashLEDDelta)
		LED = false;
	switch (color) {
		case 'g':
			smallRing.setPixelColor(smallRingCounter, smallRing.Color(0, 40, 0));
			bigRing.setPixelColor(bigRingCounter, bigRing.Color(0, 40, 0));
			break;
		case 'r':
			smallRing.setPixelColor(smallRingCounter, smallRing.Color(40, 0, 0));
			bigRing.setPixelColor(bigRingCounter, bigRing.Color(40, 0, 0));
			break;
		case 'b':
			smallRing.setPixelColor(smallRingCounter, smallRing.Color(0, 0, 40));
			bigRing.setPixelColor(bigRingCounter, bigRing.Color(0, 0, 40));
			break;
		default:
			//white eye
			smallRing.setPixelColor(smallRingCounter, smallRing.Color(40, 40, 40));
			smallRing.show();
			if (smallRingCounter >= smallRingSize)
				smallRingCounter = 0;
			return;
			break;
	}
	smallRing.show();
	bigRing.show();
	if (smallRingCounter >= smallRingSize) 
		smallRingCounter = 0;
	if (bigRingCounter >= bigRingSize)
		bigRingCounter = 0;
}


void ClearSensorsCash()
{
	Time_Sens1_detection = 0; Time_Sens2_detection = 0; Time_Sens3_detection = 0; Time_Sens4_detection = 0; Time_Sens5_detection = 0;
	Time_Sens6_detection = 0; Time_Sens7_detection = 0; Time_Sens8_detection = 0; Time_Sens9_detection = 0; Time_Sens10_detection = 0;
	Lock_Sens1 = false; Lock_Sens2 = false; Lock_Sens3 = false; Lock_Sens4 = false; Lock_Sens5 = false;
	Lock_Sens6 = false; Lock_Sens7 = false; Lock_Sens8 = false; Lock_Sens9 = false; Lock_Sens10 = false;
}


void YesNoMode()
{
	if (!responseLoop)
	{
		responseTimer = millis();
		responseLoop = true;
	}

	if (((millis() - responseTimer) >= responseTimeout) && ANSWER == 0)
	{
		slave = 6;
		slowlyThinking = true;
		ColorEye('b');
	}


	if (ANSWER == 0)
	{
		if (!mainYesNoLoop)
		{
			t8 = millis();
			mainYesNoLoop= true;
		}
		
		if (mainYesNoLoo)
		{
			if ((t7 - t8) >= timeReaction)
				mainYesNoLoop= false;
		}

		if (!mainYesNoLoop)
		{
			D1_F = analogRead(ISens1); D2_F = analogRead(ISens2); D3_F = analogRead(ISens3); D4_F = analogRead(ISens4); D5_F = analogRead(ISens5);
			D6_F = analogRead(ISens6); D7_F = analogRead(ISens7); D8_F = analogRead(ISens8); D9_F = analogRead(ISens9); D10_F = analogRead(ISens10);
		}

		if (mainYesNoLoop)
		{
			D1_S = analogRead(ISens1); D2_S = analogRead(ISens2); D3_S = analogRead(ISens3); D4_S = analogRead(ISens4); D5_S = analogRead(ISens5);
			D6_S = analogRead(ISens6); D7_S = analogRead(ISens7); D8_S = analogRead(ISens8); D9_S = analogRead(ISens9); D10_S = analogRead(ISens10);
		}

		Delta1 = abs(D1_S - D1_F); Delta2 = abs(D2_S - D2_F); Delta3 = abs(D3_S - D3_F); Delta4 = abs(D4_S - D4_F); Delta5 = abs(D5_S - D5_F);
		Delta6 = abs(D6_S - D6_F); Delta7 = abs(D7_S - D7_F); Delta8 = abs(D8_S - D8_F); Delta9 = abs(D9_S - D9_F); Delta10 = abs(D10_S - D10_F);
		if (Delta1 <= Treshold) Delta1 = 0; else if (Delta1 >= Sensitivity && !Lock_Sens1)
		{
			Time_Sens1_detection = millis(); Lock_Sens1 = true;
		}
		if (Delta2 <= Treshold) Delta2 = 0; else if (Delta2 >= Sensitivity && !Lock_Sens2)
		{
			Time_Sens2_detection = millis(); Lock_Sens2 = true;
		}
		if (Delta3 <= Treshold) Delta3 = 0; else if (Delta3 >= Sensitivity && !Lock_Sens3)
		{
			Time_Sens3_detection = millis(); Lock_Sens3 = true;
		}
		if (Delta4 <= Treshold) Delta4 = 0; else if (Delta4 >= Sensitivity && !Lock_Sens4)
		{
			Time_Sens4_detection = millis(); Lock_Sens4 = true;
		}
		if (Delta5 <= Treshold) Delta5 = 0; else if (Delta5 >= Sensitivity && !Lock_Sens5)
		{
			Time_Sens5_detection = millis(); Lock_Sens5 = true;
		}
		if (Delta6 <= Treshold) Delta6 = 0; else if (Delta6 >= Sensitivity && !Lock_Sens6)
		{
			Time_Sens6_detection = millis(); Lock_Sens6 = true;
		}
		if (Delta7 <= Treshold) Delta7 = 0; else if (Delta7 >= Sensitivity && !Lock_Sens7)
		{
			Time_Sens7_detection = millis(); Lock_Sens7 = true;
		}
		if (Delta8 <= Treshold) Delta8 = 0; else if (Delta8 >= Sensitivity && !Lock_Sens8)
		{
			Time_Sens8_detection = millis(); Lock_Sens8 = true;
		}
		if (Delta9 <= Treshold) Delta9 = 0; else if (Delta9 >= Sensitivity && !Lock_Sens9)
		{
			Time_Sens9_detection = millis(); Lock_Sens9 = true;
		}
		if (Delta10 <= Treshold) Delta10 = 0; else if (Delta10 >= Sensitivity && !Lock_Sens10)
		{
			Time_Sens10_detection = millis(); Lock_Sens10 = true;
		}

		if (((Time_Sens1_detection && Time_Sens2_detection) || (Time_Sens6_detection && Time_Sens7_detection)) > 0 && !loopAnswerY)
		{
			ANSWER_YES++; ClearSensorsCash(); loopAnswerY = true;
		}
		if (((Time_Sens9_detection || Time_Sens10_detection) || (Time_Sens4_detection && Time_Sens5_detection)) > 0 && !loopAnswerN)
		{
			ANSWER_NO++; ClearSensorsCash(); loopAnswerN = true;
		}
		if (Delta1 == 0 && Delta2 == 0 && Delta6 == 0 && Delta7 == 0 && loopAnswerY) loopAnswerY = false;
		if (Delta9 == 0 && Delta10 == 0 && Delta4 == 0 && Delta5 == 0 && loopAnswerN) loopAnswerN = false;
		if (ANSWER_YES >= 5)
		{
			ANSWER = 1; ANSWER_YES = 0; ANSWER_NO = 0;
		}
		if (ANSWER_NO >= 5)
		{
			ANSWER = 2; ANSWER_YES = 0; ANSWER_NO = 0;
		}
	}
	if (ANSWER == 2)
	{
		slave = 16; ColorEye('r'); ANSWERTIME = true; responseLoop = false; slowlyThinking = false; ANSWER = 0;
	}
	if (ANSWER == 1)
	{
		slave = 15; ColorEye('g'); ANSWERTIME = true; responseLoop = false; slowlyThinking = false; ANSWER = 0;
	}
	if (ANSWER == 0 && !slowlyThinking)
	{
		SlowDarkEye();
	}

	if (ANSWERTIME && !answerTimeLoop1)
	{
		answerTimer1 = millis(); answerTimeLoop1 = true;
	}
	if (answerTimeLoop1 && ((millis() - answerTimer1) >= delta_wait_answer * 2))
	{
		ANSWERTIME = false; ANSWER = 0; answerTimeLoop1 = false;
	}
}


void Shaking()
{
	t1 = millis();
	if (!SETTINGS)
	{
		AttachServo("1111");
		MAX_deg = 179; MIN_deg = 160; n = 0; count = random(0, 4); ServoSpeed = random(0, 3);
		if (ServoSpeed == 0) ServoSpeed = 2; if (ServoSpeed == 1) ServoSpeed = 2; if (ServoSpeed == 2) ServoSpeed = 4; if (ServoSpeed == 3) ServoSpeed = 10;
		if (count == 0) count = 2; if (count == 1) count = 4; if (count == 2) count = 6;
		SETTINGS = true;
	}
	if (SETTINGS && !MOVE)
	{
		if (!servoLoop)
		{
			t2 = millis(); if (!ServoDirection)
		{
			pos++; servoLoop = true;
		} else
		{
			pos--; servoLoop = true;
		}
		}
		if ((t1 - t2) >= ServoSpeed) servoLoop = false;
		if (pos <= MIN_deg && !mainLoop) {
			ServoDirection = false; n++; RGB_servo_show();
			mainLoop = true;
		} if (pos >= MAX_deg)
		{
			ServoDirection = true; mainLoop = false;
		}
		pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); myservo2.write(pos); myservo3.write(pos); myservo4.write(pos);
		if (n >= count * 2)
		{
			DetachServo("1111"); MOVE = true;
		}
	}
}


void Rounds()
{
	t1 = millis();
	if (!SETTINGS)
	{
		AttachServo("1111"); MAX_deg = 179; MIN_deg = 120; n = 0; rounds_count = 0; count = random(0, 3); ServoSpeed = random(0, 3); script = random(0, 3);
		if (ServoSpeed == 0) ServoSpeed = 2; if (ServoSpeed == 2) ServoSpeed = 4; if (ServoSpeed == 2) ServoSpeed = 8;
		if (count == 0) count = 1; if (count == 1) count = 2; if (count == 2) count = 3;
		myservo1.write(MAX_deg); myservo2.write(MAX_deg); myservo3.write(MAX_deg); myservo4.write(MAX_deg);
		SETTINGS = true;
	}
	if (SETTINGS && !MOVE)
	{
		if (!servoLoop)
		{
			t2 = millis(); if (!ServoDirection)
		{
			pos++; servoLoop = true;
		} else
		{
			pos--; servoLoop = true;
		}
		} if ((t1 - t2) >= ServoSpeed) servoLoop = false;
		if (pos <= MIN_deg)
		{
			ServoDirection = false;  mainLoop = false;
		} if (pos >= MAX_deg && !mainLoop)
		{
			n++; RGB_servo_show(); ServoDirection = true; mainLoop = true;
		}
		if (!Servo1_move)
		{
			pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); if (n >= 1) Servo1_move = true;
		}
		if (!Servo2_move && Servo1_move)
		{
			pos = abs(pos); pos = constrain(pos, 1, 179); myservo2.write(pos); if (n >= 2) Servo2_move = true;
		}
		if (!Servo3_move && Servo2_move)
		{
			pos = abs(pos); pos = constrain(pos, 1, 179); myservo3.write(pos); if (n >= 3) Servo3_move = true;
		}
		if (!Servo4_move && Servo3_move)
		{
			pos = abs(pos); pos = constrain(pos, 1, 179); myservo4.write(pos); if (n >= 4) Servo4_move = true;
		}

		if (Servo1_move && Servo2_move && Servo3_move && Servo4_move)
		{
			rounds_count++; n = 0;
		}
		if (Servo1_move && Servo2_move && Servo3_move && Servo4_move && rounds_count <= count)
		{
			Servo1_move = false; Servo2_move = false; Servo3_move = false; Servo4_move = false;
		}
		if (rounds_count >= count)
		{
			DetachServo("1111"); MOVE = true;
		}
	}
}


void Hello()
{
	t1 = millis();
	if (!SETTINGS)
	{
		MAX_deg = 179; MIN_deg = 70; pos = MAX_deg; n = 0; count = random(0, 2); ServoSpeed = 10; SETTINGS = true;
	}
	if (SETTINGS && !MOVE && count == 0)
	{
		AttachServo("1000");
		if (pos >= MAX_deg && !mainLoop) {
			ServoDirection = false; n++; RGB_servo_show();
			mainLoop = true;
		}
		if (pos <= MIN_deg)
		{
			ServoDirection = true; mainLoop = false;
		}
		if (!servoLoop)
		{
			t2 = millis(); if (!ServoDirection)
		{
			pos--; servoLoop = true;
		} else
		{
			pos++; servoLoop = true;
		}
		} if ((t1 - t2) >= ServoSpeed) servoLoop = false;
		pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); if (n >= 3)
		{
			DetachServo("1000"); MOVE = true;
		}
	}
	if (SETTINGS && !MOVE && count == 1)
	{
		AttachServo("0100");
		if (pos >= MAX_deg && !mainLoop) {
			ServoDirection = false; n++;
			RGB_servo_show();
			mainLoop = true;
		}
		if (pos <= MIN_deg)
		{
			
			ServoDirection = true;
			mainLoop = false;
		}
		if (!servoLoop) {
			t2 = millis();
			if (!ServoDirection)
			{
				
				pos--;
			 	servoLoop = true;
			}
			else
			{
				pos++; servoLoop = true;
			} 
		}
		if ((t1 - t2) >= ServoSpeed)
			servoLoop = false;
		pos = abs(pos);
		pos = constrain(pos, 1, 179);
		myservo2.write(pos);
		if (n >= 3)
		{
			DetachServo("0100"); MOVE = true;
		}
	}
}


void HipHop()
{
	t1 = millis();
	if (!SETTINGS)
	{
		MAX_deg = 179; MIN_deg = 70; pos = MAX_deg; n = 0; count = random(0, 2); ServoSpeed = 5; SETTINGS = true;
	}

	if (SETTINGS && !MOVE && count == 0)
	{
		AttachServo("1010");
		if (pos >= MAX_deg && !mainLoop) {
			ServoDirection = false; n++; RGB_servo_show();
			mainLoop = true;
		} if (pos <= MIN_deg)
		{
			ServoDirection = true; mainLoop = false;
		}
		if (!servoLoop)
		{
			t2 = millis(); if (!ServoDirection)
		{
			pos--; servoLoop = true;
		} else
		{
			pos++; servoLoop = true;
		}
		} if ((t1 - t2) >= ServoSpeed) servoLoop = false;
		pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); myservo3.write(pos); if (n >= 3)
		{
			DetachServo("1010"); MOVE = true;
		}
	}

	if (SETTINGS && !MOVE && count == 1)
	{
		AttachServo("0101");
		if (pos >= MAX_deg && !mainLoop)
		{
			ServoDirection = false; n++; RGB_servo_show(); mainLoop = true;
		} if (pos <= MIN_deg)
		{
			ServoDirection = true; mainLoop = false;
		}
		if (!servoLoop)
		{
			t2 = millis(); if (!ServoDirection)
		{
			pos--; servoLoop = true;
		} else
		{
			pos++; servoLoop = true;
		}
		} if ((t1 - t2) >= ServoSpeed) servoLoop = false;
		pos = abs(pos); pos = constrain(pos, 1, 179); myservo2.write(pos); myservo4.write(pos); if (n >= 3)
		{
			DetachServo("0101"); MOVE = true;
		}
	}
}


void Shell()
{
	t1 = millis();
	if (!SETTINGS)
	{
		MAX_deg = 179; MIN_deg = 10; pos = MAX_deg; n = 0; ServoSpeed = 5; SETTINGS = true;
	}
	if (SETTINGS && !MOVE)
	{
		AttachServo("1111"); if (pos >= MAX_deg && !mainLoop)
		{
			ServoDirection = false; n++; RGB_servo_show(); mainLoop = true;
		}
		if (pos <= MIN_deg) {
			ServoDirection = true;
			mainLoop = false;
		} if (!servoLoop)
		{
			t2 = millis(); if (!ServoDirection)
		{
			pos--; servoLoop = true;
		} else
		{
			pos++; servoLoop = true;
		}
		}
		if ((t1 - t2) >= ServoSpeed) servoLoop = false;
		pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); myservo2.write(pos); myservo3.write(pos); myservo4.write(pos); if (n >= 2)
		{
			DetachServo("1111"); MOVE = true;
		}
	}
}


void SitUp()
{
	t1 = millis();
	if (!SETTINGS)
	{
		MAX_deg = 179; MIN_deg = 10; pos = MAX_deg; n = 0; count = random(0, 2); ServoSpeed = 10; SETTINGS = true;
	}

	if (SETTINGS && !MOVE && count == 0)
	{
		AttachServo("1100");
		if (pos >= MAX_deg && !mainLoop) {
			ServoDirection = false; n++; RGB_servo_show();
			mainLoop = true;
		}
		if (pos <= MIN_deg)
		{
			ServoDirection = true; mainLoop = false;
		}
		if (!servoLoop)
		{
			t2 = millis(); if (!ServoDirection)
		{
			pos--; servoLoop = true;
		} else
		{
			pos++; servoLoop = true;
		}
		} if ((t1 - t2) >= ServoSpeed) servoLoop = false;
		pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); myservo2.write(pos); if (n >= 2)
		{
			DetachServo("1100"); MOVE = true;
		}
	}

	if (SETTINGS && !MOVE && count == 1)
	{
		AttachServo("0011");
		if (pos >= MAX_deg && !mainLoop)
		{
			ServoDirection = false; n++; RGB_servo_show(); mainLoop = true;
		} if (pos <= MIN_deg)
		{
			ServoDirection = true; mainLoop = false;
		}
		if (!servoLoop)
		{
			t2 = millis(); if (!ServoDirection)
		{
			pos--; servoLoop = true;
		} else
		{
			pos++; servoLoop = true;
		}
		} if ((t1 - t2) >= ServoSpeed) servoLoop = false;
		pos = abs(pos); pos = constrain(pos, 1, 179); myservo3.write(pos); myservo4.write(pos); if (n >= 2)
		{
			DetachServo("0011"); MOVE = true;
		}
	}
}


void HearsPI()
{
	t1 = millis();
	if (!SETTINGS)
	{
		MAX_deg = 179; MIN_deg = 10; pos = MAX_deg; n = 0; ServoSpeed = 10; SETTINGS = true;
	}

	if (SETTINGS && !MOVE)
	{
		AttachServo("1100");
		if (pos >= MAX_deg && !mainLoop) {
			ServoDirection = false; n++; RGB_servo_show();
			mainLoop = true;
		} if (pos <= MIN_deg)
		{
			ServoDirection = true; mainLoop = false;
		}
		if (!servoLoop)
		{
			t2 = millis(); if (!ServoDirection)
		{
			pos--; servoLoop = true;
		} else
		{
			pos++; servoLoop = true;
		}
		} if ((t1 - t2) >= ServoSpeed) servoLoop = false;
		pos = abs(pos); pos = constrain(pos, 1, 179); myservo1.write(pos); myservo2.write(pos); if (n >= 2)
		{
			DetachServo("1100"); MOVE = true;
		}
	}
}


void LegsPI()
{
	t1 = millis();
	if (!SETTINGS)
	{
		MAX_deg = 179; MIN_deg = 10; pos = MAX_deg; n = 0; ServoSpeed = 10; SETTINGS = true;
	}

	if (SETTINGS && !MOVE)
	{
		AttachServo("0011");
		if (pos >= MAX_deg && !mainLoop)
		{
			ServoDirection = false; n++; RGB_servo_show(); mainLoop = true;
		} if (pos <= MIN_deg)
		{
			ServoDirection = true; mainLoop = false;
		}
		if (!servoLoop)
		{
			t2 = millis(); if (!ServoDirection)
		{
			pos--; servoLoop = true;
		} else
		{
			pos++; servoLoop = true;
		}
		} if ((t1 - t2) >= ServoSpeed) servoLoop = false;
		pos = abs(pos); pos = constrain(pos, 1, 179); myservo3.write(pos); myservo4.write(pos); if (n >= 2)
		{
			DetachServo("0011"); MOVE = true;
		}
	}
}


void MusicAutomat()
{
	t3 = millis();

	if (!START_MACHINE) {
		for (b = 0; b < 128; b++)
		{
			val = analogRead(AUDIOPIN); data[b] = val; im[b] = 0;
		} fix_bigRingCountert(data, im, 7, 0); for (b = 0; b<3; b++) {
			data[b] = sqrt(data[b] * data[b] + im[b] * im[b]);

			if (b == 0) {
				out = data[b];
				if ((out >= 3 && out <= 5) && !BurnLED_R) {
					BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
					red++; R_flash = true;
				}
				if ((out >= 6 && out <= 10) && !BurnLED_O) {
					BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
					orange++; O_flash = true;
				}
			}


			if (b == 1) {
				out = data[b];
				if ((out >= 3 && out <= 5) && !BurnLED_B) {
					BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
					blue++; G_flash = true;
				}
				if ((out >= 6 && out <= 10) && !BurnLED_V) {
					BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
					violet++; Y_flash = true;
				}
			}


			if (b == 2) {
				out = data[b];
				if ((out >= 3 && out <= 5) && !BurnLED_G) {
					BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
					green++; B_flash = true;
				}
				if ((out >= 6 && out <= 10) && !BurnLED_Y) {
					BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
					yellow++; V_flash = true;
				}
			}
		}

		if ((t3 - t4) >= light_interval)
		{
			t4 = 0; for (int i = 0; i <= 8; i++)
		{
			smallRing.setPixelColor(i, 0, 0, 0); smallRing.show();
		} for (int i = 0; i <= 22; i++)
		{
			bigRing.setPixelColor(i, 0, 0, 0); bigRing.show();
		}
		}


		if (R_flash) {
			t4 = millis(); red++; for (int i = 0; i <= 8; i++)
			{
				smallRing.setPixelColor(i, 40, 0, 0); smallRing.show();
			}
			for (int i = 0; i <= 22; i++)
			{
				bigRing.setPixelColor(i, 0, 40, 0); bigRing.show();
			}
			R_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;
		}

		if (G_flash) {
			t4 = millis(); green++; for (int i = 0; i <= 8; i++)
			{
				smallRing.setPixelColor(i, 0, 40, 0); smallRing.show();
			}
			for (int i = 0; i <= 22; i++)
			{
				bigRing.setPixelColor(i, 0, 0, 40); bigRing.show();
			}
			G_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;
		}

		if (B_flash) {
			t4 = millis(); blue++; for (int i = 0; i <= 8; i++)
			{
				smallRing.setPixelColor(i, 0, 0, 40); smallRing.show();
			}
			for (int i = 0; i <= 22; i++)
			{
				bigRing.setPixelColor(i, 40, 0, 0); bigRing.show();
			}
			B_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;
		}

		if (O_flash) {
			t4 = millis(); orange++; for (int i = 0; i <= 8; i++)
			{
				smallRing.setPixelColor(i, 40, 40, 0); smallRing.show();
			}
			for (int i = 0; i <= 22; i++)
			{
				bigRing.setPixelColor(i, 0, 40, 40); bigRing.show();
			}
			O_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;
		}

		if (Y_flash) {
			t4 = millis(); yellow++; for (int i = 0; i <= 8; i++)
			{
				smallRing.setPixelColor(i, 0, 40, 40); smallRing.show();
			}
			for (int i = 0; i <= 22; i++)
			{
				bigRing.setPixelColor(i, 40, 40, 0); bigRing.show();
			}
			Y_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;
		}

		if (V_flash) {
			t4 = millis(); violet++; for (int i = 0; i <= 8; i++)
			{
				smallRing.setPixelColor(i, 40, 0, 40); smallRing.show();
			}
			for (int i = 0; i <= 22; i++)
			{
				bigRing.setPixelColor(i, 0, 26, 40); bigRing.show();
			}
			V_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;
		}
	}
	red_action = 50;
	orange_action = 60;
	green_action = 35;
	blue_action = 25;
	yellow_action = 7;
	violet_action = 15;

	if (red >= red_action)
	{
		START_MACHINE = true; Shaking(); if (n >= count * 2)
	{
		red = 0; mainLoop = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;
	}
	}
	if (green >= green_action)
	{
		START_MACHINE = true; Rounds(); if (rounds_count >= count)
	{
		green = 0; mainLoop = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;
	}
	}
	if (blue >= blue_action)
	{
		START_MACHINE = true; Hello(); if (n >= 3)
	{
		mainLoop = false; blue = 0; mainLoop = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;
	}
	}
	if (orange >= orange_action)
	{
		START_MACHINE = true; HipHop(); if (n >= 3)
	{
		orange = 0;  mainLoop = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;
	}
	}
	if (yellow >= yellow_action)
	{
		START_MACHINE = true; SitUp(); if (n >= 2)
	{
		yellow = 0; mainLoop = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;
	}
	}
	if (violet >= violet_action)
	{
		START_MACHINE = true; Shell(); if (n >= 2)
	{
		violet = 0; mainLoop = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;
	}
	}
}


void RGB_servo_show()
{
label1: script = random(0, 3); script1 = random(0, 3); script2 = random(0, 3);
label2: script3 = random(0, 3); script4 = random(0, 3); script5 = random(0, 3);
	if (script == 0 && script1 == 0 && script2 == 0) goto label1;
	if (script3 == 0 && script4 == 0 && script5 == 0) goto label2;

	switch (script) {
	case 0: {Rp = 0;
	} break;
	case 1: {Rp = 20;
	} break;
	case 2: {Rp = 40;
	} break;
	}
	switch (script1) {
	case 0: {Bp = 0;
	} break;
	case 1: {Bp = 20;
	} break;
	case 2: {Bp = 40;
	} break;
	}
	switch (script2) {
	case 0: {Gp = 0;
	} break;
	case 1: {Gp = 20;
	} break;
	case 2: {Gp = 40;
	} break;
	}
	switch (script3) {
	case 0: {Rp1 = 0;
	} break;
	case 1: {Rp1 = 20;
	} break;
	case 2: {Rp1 = 40;
	} break;
	}
	switch (script4) {
	case 0: {Bp1 = 0;
	} break;
	case 1: {Bp1 = 20;
	} break;
	case 2: {Bp1 = 40;
	} break;
	}
	switch (script5) {
	case 0: {Gp1 = 0;
	} break;
	case 1: {Gp1 = 20;
	} break;
	case 2: {Gp1 = 40;
	} break;
	}
	for (int i = 0; i <= 8; i++)
	{
		smallRing.setPixelColor(i, Rp, Bp, Gp); smallRing.show();
	}
	for (int i = 0; i <= 22; i++)
	{
		bigRing.setPixelColor(i, Rp1, Bp1, Gp1); bigRing.show();
	}
}


void Scandal()
{
	t3 = millis();
	if (!START_MACHINE) {
		for (b = 0; b < 128; b++)
		{
			val = analogRead(AUDIOPIN); data[b] = val; im[b] = 0;
		} fix_bigRingCountert(data, im, 7, 0); for (b = 0; b<3; b++) {
			data[b] = sqrt(data[b] * data[b] + im[b] * im[b]);

			if (b == 0) {
				out = data[b];
				if ((out >= 3 && out <= 5) && !BurnLED_R) {
					BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
					red++; R_flash = true;
				}
				if ((out >= 6 && out <= 10) && !BurnLED_O) {
					BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
					orange++; O_flash = true;
				}
			}


			if (b == 1) {
				out = data[b];
				if ((out >= 3 && out <= 5) && !BurnLED_B) {
					BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
					blue++; G_flash = true;
				}
				if ((out >= 6 && out <= 10) && !BurnLED_V) {
					BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
					violet++; Y_flash = true;
				}
			}


			if (b == 2) {
				out = data[b];
				if ((out >= 3 && out <= 5) && !BurnLED_G) {
					BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
					green++; B_flash = true;
				}
				if ((out >= 6 && out <= 10) && !BurnLED_Y) {
					BurnLED_R = true; BurnLED_G = true; BurnLED_B = true; BurnLED_Y = true; BurnLED_O = true; BurnLED_V = true;
					yellow++; V_flash = true;
				}
			}
		}

		if ((t3 - t4) >= light_interval)
		{
			t4 = 0; for (int i = 0; i <= 8; i++)
		{
			smallRing.setPixelColor(i, 0, 0, 0); smallRing.show();
		} for (int i = 0; i <= 22; i++)
		{
			bigRing.setPixelColor(i, 0, 0, 0); bigRing.show();
		}
		}


		if (R_flash) {
			t4 = millis(); red++; for (int i = 0; i <= 8; i++)
			{
				smallRing.setPixelColor(i, 40, 0, 0); smallRing.show();
			}
			for (int i = 0; i <= 22; i++)
			{
				bigRing.setPixelColor(i, 0, 40, 0); bigRing.show();
			}
			R_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;
		}

		if (G_flash) {
			t4 = millis(); green++; for (int i = 0; i <= 8; i++)
			{
				smallRing.setPixelColor(i, 0, 40, 0); smallRing.show();
			}
			for (int i = 0; i <= 22; i++)
			{
				bigRing.setPixelColor(i, 0, 0, 40); bigRing.show();
			}
			G_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;
		}

		if (B_flash) {
			t4 = millis(); blue++; for (int i = 0; i <= 8; i++)
			{
				smallRing.setPixelColor(i, 0, 0, 40); smallRing.show();
			}
			for (int i = 0; i <= 22; i++)
			{
				bigRing.setPixelColor(i, 40, 0, 0); bigRing.show();
			}
			B_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;
		}

		if (O_flash) {
			t4 = millis(); orange++; for (int i = 0; i <= 8; i++)
			{
				smallRing.setPixelColor(i, 40, 40, 0); smallRing.show();
			}
			for (int i = 0; i <= 22; i++)
			{
				bigRing.setPixelColor(i, 0, 40, 40); bigRing.show();
			}
			O_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;
		}

		if (Y_flash) {
			t4 = millis(); yellow++; for (int i = 0; i <= 8; i++)
			{
				smallRing.setPixelColor(i, 0, 40, 40); smallRing.show();
			}
			for (int i = 0; i <= 22; i++)
			{
				bigRing.setPixelColor(i, 40, 40, 0); bigRing.show();
			}
			Y_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;
		}

		if (V_flash) {
			t4 = millis(); violet++; for (int i = 0; i <= 8; i++)
			{
				smallRing.setPixelColor(i, 40, 0, 40); smallRing.show();
			}
			for (int i = 0; i <= 22; i++)
			{
				bigRing.setPixelColor(i, 0, 26, 40); bigRing.show();
			}
			V_flash = false; BurnLED_R = false; BurnLED_G = false; BurnLED_B = false; BurnLED_Y = false; BurnLED_O = false; BurnLED_V = false;
		}
	}
	red_action = 10;
	orange_action = 5;
	green_action = 2;
	blue_action = 1;
	yellow_action = 2;
	violet_action = 1;

	if (red >= red_action)
	{
		START_MACHINE = true; Shaking(); if (n >= count * 2)
	{
		red = 0; mainLoop = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;
	}
	}
	if (green >= green_action)
	{
		START_MACHINE = true; Rounds(); if (rounds_count >= count)
	{
		green = 0; mainLoop = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;
	}
	}
	if (blue >= blue_action)
	{
		START_MACHINE = true; Hello(); if (n >= 3)
	{
		mainLoop = false; blue = 0; mainLoop = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;
	}
	}
	if (orange >= orange_action)
	{
		START_MACHINE = true; HipHop(); if (n >= 3)
	{
		orange = 0;  mainLoop = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;
	}
	}
	if (yellow >= yellow_action)
	{
		START_MACHINE = true; SitUp(); if (n >= 2)
	{
		yellow = 0; mainLoop = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;
	}
	}
	if (violet >= violet_action)
	{
		START_MACHINE = true; Shell(); if (n >= 2)
	{
		violet = 0; mainLoop = false; SETTINGS = false; MOVE = false; START_MACHINE = false; COMPLEX++;
	}
	}
}


void Love(uint32_t wait)
{
	ShowTime++;
	uint16_t i, j; for (j = 0; j<(Love_Speed + 1) * 5; j++)
	{
		for (i = 0; i< fstStrip.numPixels(); i++)
		{
			fstStrip.setPixelColor(i, Wheel(((i * (Love_Speed + 1) / fstStrip.numPixels()) + j) & Love_Speed));
		}
		fstStrip.show();
		delay(wait);

		for (i = 0; i< sndStrip.numPixels(); i++)
		{
			sndStrip.setPixelColor(i, Wheel(((i * (Love_Speed + 1) / sndStrip.numPixels()) + j) & Love_Speed));
		}
		sndStrip.show();
		delay(wait);
	}
}


uint32_t Wheel(byte WheelPos) {
	WheelPos = Love_Speed - WheelPos; if (WheelPos < Love_Speed1)
	{
		return fstStrip.Color(Love_Speed - WheelPos * 3, 0, WheelPos * 3); return sndStrip.Color(Love_Speed - WheelPos * 3, 0, WheelPos * 3);
	}
	if (WheelPos < Love_Speed2) {
		WheelPos -= Love_Speed1; return fstStrip.Color(0, WheelPos * 3, Love_Speed - WheelPos * 3);
		return sndStrip.Color(0, WheelPos * 3, Love_Speed - WheelPos * 3);
	}
    WheelPos -= Love_Speed2; return fstStrip.Color(WheelPos * 3, Love_Speed - WheelPos * 3, 0);
	return sndStrip.Color(WheelPos * 3, Love_Speed - WheelPos * 3, 0);
}


void ZeroPoint()
{
	DetachServo("1111");
	MOVE = false;
	SETTINGS = false;
	mainLoop = false;
	ShowTime = 0;
	commandStatus = false;
	COMPLEX = 0;
	ANSWERTIME = false;
	ANSWER = 0;
	answerTimeLoop1 = false;
	slave = 1;
}


void BigDirector()
{
	if (!readStatus) {
		readTimer = millis();
		for (int i = 0; i < 4; i++) {
			inputResult[i] = digitalRead(inputPins[i]);
		}
		readStatus = true;
	}

	if (((millis() - readTimer) >= readDuration) && readStatus)
		readStatus = false;
	if (!commandStatus)
	{
		SetDirector();
		RGB_servo_show();
		commandStatus = true;
	}
	switch (director)
	{
		case 2: 
		{
			if (commandStatus)
            {
                Shaking(); if (MOVE) ZeroPoint();
            }
        } break; //1111//
		case 3: 
		{
			if (commandStatus)
            {
                Shell(); if (MOVE) ZeroPoint();
            }
        } break; //1000//
		case 4: 
		{
			if (commandStatus)
            {
                Hello(); if (MOVE) ZeroPoint();
            }
        } break; //1100//       
		case 5: 
		{
			if (commandStatus)
            {
                Rounds(); if (MOVE) ZeroPoint();
            }
        } break; //1110//
		case 6: 
		{
			if (commandStatus)
            {
                HipHop(); if (MOVE) ZeroPoint();
            }
        } break; //0001//
		case 7: 
		{
			if (commandStatus)
            {
                HearsPI(); if (MOVE) ZeroPoint();
            }
        } break; //0011//
		case 8: 
		{
			if (commandStatus)
            {
                LegsPI(); if (MOVE) ZeroPoint();
            }
        } break; //0111//
		case 9: 
		{
			if (commandStatus && ShowTime < 1)
            {
                Love_Speed = 255; Love_Speed1 = 85; Love_Speed2 = 170; Love(5);
            }
            else
            {
                SlowDarkEye(); ZeroPoint();
            }
        } break; //0101//
		case 10:
		{
			if (commandStatus && ShowTime < 1)
            {
                Love_Speed = 40; Love_Speed1 = 20; Love_Speed2 = 120; Love(20);
            }
            else
            {
                SlowDarkEye(); ZeroPoint();
            }
        } break; //1010//
		case 11:
		{
			if (commandStatus && COMPLEX <= 2) Scandal();
            else
            {
                SlowDarkEye(); ZeroPoint();
            }
        } break; //1001//
		case 12:
		{
			if (commandStatus && COMPLEX <= 2) MusicAutomat();
            else
            {
                SlowDarkEye(); ZeroPoint();
            }
        } break; //0110//
		case 13:
		{
			commandStatus = false; YesNoMode();
		} break; //1011//
		case 15:
		{
			ZeroPoint();
		} break; //0100//  
	}
}


void setup()
{
	smallRing.begin();
	bigRing.begin();
	fstStrip.begin();
	fstStrip.show();
	sndStrip.begin();
	sndStrip.show();

	for (int i = 0; i < 4; i++) {
		pinMode(inputPins[i], INPUT);
		pinMode(outputPins[i], OUTPUT);
	}
	
	delay(1000);
	randomSeed(analogRead(15));
}

void loop()
{
	CallSlave();
	BigDirector();
}
