// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include <FastLED.h>
#define LED_PIN     9
#define NUM_LEDS    8
CRGB leds[NUM_LEDS];
AF_DCMotor LF(4);
AF_DCMotor RF(3);
AF_DCMotor LB(1);
AF_DCMotor RB(2);
char command;
int Speed = 255;
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("HELLO! Welcome to OmniRobot");
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  // turn on motor
  motor_break(255);

}
void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    motor_break(255); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.
    //Serial.println(command);

    switch (command) {
      case 'F':
        motor_forward(Speed);
        break;
      case 'B':
        motor_backward(Speed);
        break;
      case 'L':
        motor_left(Speed);
        break;
      case 'R':
        motor_right(Speed);
        break;
      case 'G':
        motor_left_ch(Speed);
        break;
      case 'I':
        motor_right_ch(Speed);
        break;
      case 'S':
        motor_break(255);
//        for (int i = 0; i < 8; i++) {
//          leds[i] = CRGB ( 0, 0, 0);
//          FastLED.show();
//        }
        break;
      case 'U':
        for (int i = 0; i < 8; i++) {
          leds[i] = CRGB ( 0, 255, 0);
          FastLED.show();
        }
        break;
      case 'u':
        for (int i = 0; i < 8; i++) {
          leds[i] = CRGB ( 0, 0, 0);
          FastLED.show();
        }
        break;
      case 'W':
        for (int i = 0; i < 8; i++) {
          leds[i] = CRGB ( 0, 0, 255);
          FastLED.show();
        }
        break;
      case 'w':
        for (int i = 0; i < 8; i++) {
          leds[i] = CRGB ( 0, 0, 0);
          FastLED.show();
        }
        break;
      case 'V':
        for (int i = 0; i < 8; i++) {
          leds[i] = CRGB ( 255, 0, 0);
          FastLED.show();
        }
        break;
      case 'v':
        for (int i = 0; i < 8; i++) {
          leds[i] = CRGB ( 0, 0, 0);
          FastLED.show();
        }
        break;

    }

  }




}
void led() {
  for (int i = 0; i < 8; i++) {
    leds[i] = CRGB ( 0, 0, 255);
    FastLED.show();
    delay(40);
  }
  for (int i = 8; i > 0; i--) {
    leds[i] = CRGB ( 255, 0, 0);
    FastLED.show();
    delay(40);
  }
  for (int i = 0; i < 8; i++) {
    leds[i] = CRGB ( 0, 255, 0);
    FastLED.show();
    delay(40);
  }
  for (int i = 8; i > 0; i--) {
    leds[i] = CRGB ( 255, 255, 255);
    FastLED.show();
    delay(40);
  }
}
void motor_break(int sp) {
  LF.setSpeed(sp);
  RF.setSpeed(sp);
  LB.setSpeed(sp);
  RB.setSpeed(sp);

  LF.run(RELEASE);
  RF.run(RELEASE);
  LB.run(RELEASE);
  RB.run(RELEASE);
}
void motor_forward(int sp) {
  LF.setSpeed(sp);
  RF.setSpeed(sp);
  LB.setSpeed(sp);
  RB.setSpeed(sp);
  LF.run(FORWARD);
  RF.run(FORWARD);
  LB.run(FORWARD);
  RB.run(FORWARD);
}
void motor_backward(int sp) {
  LF.setSpeed(sp);
  RF.setSpeed(sp);
  LB.setSpeed(sp);
  RB.setSpeed(sp);
  LF.run(BACKWARD);
  RF.run(BACKWARD);
  LB.run(BACKWARD);
  RB.run(BACKWARD);
}
void motor_right(int sp) {
  LF.setSpeed(sp);
  RF.setSpeed(sp);
  LB.setSpeed(sp);
  RB.setSpeed(sp);
  LF.run(FORWARD); RF.run(BACKWARD);
  LB.run(BACKWARD); RB.run(FORWARD);

}
void motor_right_ch(int sp) {
  LF.setSpeed(sp);
  RF.setSpeed(sp);
  LB.setSpeed(sp);
  RB.setSpeed(sp);
  LF.run(FORWARD); RF.run(BACKWARD);
  LB.run(FORWARD); RB.run(BACKWARD);

}
void motor_left(int sp) {
  LF.setSpeed(sp);
  RF.setSpeed(sp);
  LB.setSpeed(sp);
  RB.setSpeed(sp);
  LF.run(BACKWARD); RF.run(FORWARD);
  LB.run(FORWARD); RB.run(BACKWARD);
}
void motor_left_ch(int sp) {
  LF.setSpeed(sp);
  RF.setSpeed(sp);
  LB.setSpeed(sp);
  RB.setSpeed(sp);
  LF.run(BACKWARD); RF.run(FORWARD);
  LB.run(BACKWARD); RB.run(FORWARD);
}

