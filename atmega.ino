#include <PinChangeInterrupt.h>

#define MIDDLE_POINT 1500

// -------- Channel A --------
#define OUT1A 3
#define OUT2A 5
#define INA   2

// -------- Channel B --------
#define OUT1B 6
#define OUT2B 9
#define INB   4

// Channel A variables
volatile int pre_pwm_valueA = 0;
volatile int pwm_valueA = 0;
volatile int prev_timeA = 0;

// Channel B variables
volatile int pre_pwm_valueB = 0;
volatile int pwm_valueB = 0;
volatile int prev_timeB = 0;

void setup() {
  // Channel A setup
  pinMode(OUT1A, OUTPUT);
  pinMode(OUT2A, OUTPUT);
  attachPCINT(INA, risingA, RISING);

  // Channel B setup
  pinMode(OUT1B, OUTPUT);
  pinMode(OUT2B, OUTPUT);
  attachPCINT(INB, risingB, RISING);
}

void loop() {}

// ----------------- Channel A -----------------
void risingA() {
  attachPCINT(INA, fallingA, FALLING);
  prev_timeA = micros();
}

void fallingA() {
  attachPCINT(INA, risingA, RISING);
  pre_pwm_valueA = pwm_valueA;
  pwm_valueA = micros() - prev_timeA;
  if (pwm_valueA < 1000 || pwm_valueA > 1900) {
    pwm_valueA = pre_pwm_valueA;
  }
  PWM_outA(pwm_valueA);
}

void PWM_outA(int speeds) {
  int tempSpeeds = map(abs(speeds - MIDDLE_POINT), 0, 500, 0, 255);
  if (tempSpeeds > 255) tempSpeeds = 255;

  if (speeds > MIDDLE_POINT) {
    analogWrite(OUT1A, tempSpeeds);
    digitalWrite(OUT2A, LOW);
  } else {
    digitalWrite(OUT1A, LOW);
    analogWrite(OUT2A, tempSpeeds);
  }
}

// ----------------- Channel B -----------------
void risingB() {
  attachPCINT(INB, fallingB, FALLING);
  prev_timeB = micros();
}

void fallingB() {
  attachPCINT(INB, risingB, RISING);
  pre_pwm_valueB = pwm_valueB;
  pwm_valueB = micros() - prev_timeB;
  if (pwm_valueB < 1000 || pwm_valueB > 1900) {
    pwm_valueB = pre_pwm_valueB;
  }
  PWM_outB(pwm_valueB);
}

void PWM_outB(int speeds) {
  int tempSpeeds = map(abs(speeds - MIDDLE_POINT), 0, 500, 0, 255);
  if (tempSpeeds > 255) tempSpeeds = 255;

  if (speeds > MIDDLE_POINT) {
    analogWrite(OUT1B, tempSpeeds);
    digitalWrite(OUT2B, LOW);
  } else {
    digitalWrite(OUT1B, LOW);
    analogWrite(OUT2B, tempSpeeds);
  }
}
