int sensorPins[] = { A1, A2, A3, A4 };
int sensorValuesEven[] = { 0, 0, 0, 0 };
int sensorValuesOdd[] = { 0, 0, 0, 0 };
int sensorValues[] = { 0, 0, 0, 0 };
boolean sensorBlock[] = { false, false, false, false }; // DOWN, UP, LEFT, RIGHT
int timer = 0;
int detectionTime = 1000;
boolean evenLoop = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void clear() {
  for (int i = 0; i < 4; i++) {
    sensorBlock[i] = false;
  }
}

int checkSensors() {
  for (int i = 0; i < 4; i++) {
    if (sensorValues[i] < 50)
      return 0;
  }
  if (sensorValues[0] + sensorValues[1] > sensorValues[0] + sensorValues[3] && sensorValues[0] + sensorValues[1] > sensorValues[1] + sensorValues[2])
    return 1; // NO-DOWN 
  if (sensorValues[3] + sensorValues[2] > sensorValues[0] + sensorValues[3] && sensorValues[2] + sensorValues[3] > sensorValues[1] + sensorValues[2])
    return 2; // NO-UP
  if (sensorValues[0] + sensorValues[3] > sensorValues[0] + sensorValues[1] && sensorValues[0] + sensorValues[3] > sensorValues[3] + sensorValues[2])
    return 3; // YES-LEFT 
  if (sensorValues[1] + sensorValues[2] > sensorValues[0] + sensorValues[1] && sensorValues[1] + sensorValues[2] > sensorValues[3] + sensorValues[2])
    return 4; // YES-RIGHT
  return 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (evenLoop) {
    for (int i = 0; i < 4; i++) {
      sensorValuesEven[i] = analogRead(sensorPins[i]);
    }
    evenLoop = false;
  } else {
    for (int i = 0; i < 4; i++) {
      sensorValuesOdd[i] = analogRead(sensorPins[i]);
    }

    for (int i = 0; i < 4; i++) {
      sensorValues[i] = abs(sensorValuesOdd[i] - sensorValuesEven[i]);
      if (!timer)
        timer = millis();
    }
    
    int rc = checkSensors();
    sensorBlock[rc - 1] = true;
    if (rc == 1 || rc == 2) {
      sensorBlock[2] = false;
      sensorBlock[3] = false;
    } else if (rc == 3 || rc ==  4) {
      sensorBlock[0] = false;
      sensorBlock[1] = false;
    }
    if (sensorBlock[0] && sensorBlock[1]) {
      Serial.print("NO\n");
      timer = 0;
      clear();
    } else if (sensorBlock[2] && sensorBlock[3]) {
      Serial.print("YES\n");
      timer = 0;
      clear();
    }
    int curTime = millis();
    if ( curTime - timer >= detectionTime) {
      clear();
      timer = 0;
    }
    evenLoop = true;
    for (int i = 0; i < 4; i++) {
      sensorValuesOdd[i] = 0;
      sensorValuesEven[i] = 0;
    }
  }
  delay(75);
}
