#include <PinChangeInterrupt.h>

#define MIDDLE_POINT 1500

#define OUT1A 3
#define OUT2A 5
#define INA   2

#define OUT1B 6
#define OUT2B 9
#define INB   4

volatile unsigned long prev_timeA = 0;
volatile int pwm_valueA = 1500;

volatile unsigned long prev_timeB = 0;
volatile int pwm_valueB = 1500;

void setup() {
  Serial.begin(9600);

  pinMode(OUT1A, OUTPUT);
  pinMode(OUT2A, OUTPUT);
  pinMode(INA, INPUT);

  pinMode(OUT1B, OUTPUT);
  pinMode(OUT2B, OUTPUT);
  pinMode(INB, INPUT);

  attachPCINT(digitalPinToPCINT(INA), isrA, CHANGE);
  attachPCINT(digitalPinToPCINT(INB), isrB, CHANGE);
}

void loop() {
  // Debug monitor
  Serial.print("CH A: "); Serial.print(pwm_valueA);
  Serial.print("   CH B: "); Serial.println(pwm_valueB);
  delay(200);
}

void isrA() {
  if (digitalRead(INA)) {
    prev_timeA = micros();
  } else {
    pwm_valueA = micros() - prev_timeA;
    PWM_outA(pwm_valueA);
  }
}

void isrB() {
  if (digitalRead(INB)) {
    prev_timeB = micros();
  } else {
    pwm_valueB = micros() - prev_timeB;
    PWM_outB(pwm_valueB);
  }
}

void PWM_outA(int speeds) {
  int tempSpeeds = map(abs(speeds - MIDDLE_POINT), 0, 500, 0, 255);
  tempSpeeds = constrain(tempSpeeds, 0, 255);

  if (speeds > MIDDLE_POINT) {
    analogWrite(OUT1A, tempSpeeds);
    digitalWrite(OUT2A, LOW);
  } else {
    digitalWrite(OUT1A, LOW);
    analogWrite(OUT2A, tempSpeeds);
  }
}

void PWM_outB(int speeds) {
  int tempSpeeds = map(abs(speeds - MIDDLE_POINT), 0, 500, 0, 255);
  tempSpeeds = constrain(tempSpeeds, 0, 255);

  if (speeds > MIDDLE_POINT) {
    analogWrite(OUT1B, tempSpeeds);
    digitalWrite(OUT2B, LOW);
  } else {
    digitalWrite(OUT1B, LOW);
    analogWrite(OUT2B, tempSpeeds);
  }
}
