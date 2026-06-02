#include <LPC21xx.H>
#include "led.h"
#include "timer_interrupts.h"
#include "servo.h"

#define mDETEKTOR (1 << 10)


void Servo::DetectorInit(void) {
   IO0DIR = IO0DIR & (~mDETEKTOR);
}



enum DetectorState Servo::eReadDetector(void) {
   if (0 == (IO0PIN & mDETEKTOR)) {
      return ACTIVE;
   } else {
      return INACTIVE;
   }
}

void Servo::Automate() {

   switch (eState) {
   case SERVO_CALLIB:
      if (eReadDetector() == ACTIVE) {
         eState = IDDLE;
      } else {
         Led_Step(LEFT);
         eState = SERVO_CALLIB;
      }
      break;

   case IDDLE:
      if (uiCurrentPosition == uiDesiredPosition) {
         eState = IDDLE;
      } else {
         eState = IN_PROGRESS;
      }
      break;

   case IN_PROGRESS:
      if (uiCurrentPosition < uiDesiredPosition) {
         Led_Step(RIGHT);
         eState = IN_PROGRESS;
         uiCurrentPosition++;
      } else if (uiCurrentPosition > uiDesiredPosition) {
         Led_Step(LEFT);
         eState = IN_PROGRESS;
					uiCurrentPosition--;
      } else {
         eState = IDDLE;
      }
      break;
   }
}

void Servo::Callib(void) {
   uiCurrentPosition = 0;
   uiDesiredPosition = 0;
   eState = SERVO_CALLIB;
};

void Servo::GoTo(unsigned int uiPosition) {
   uiDesiredPosition = uiPosition;
};

void Servo::Init() {
   eState = SERVO_CALLIB;
   DetectorInit();
   Led_Init();
}

