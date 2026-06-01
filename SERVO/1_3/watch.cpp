#include "timer_interrupts.h"
#include "watch.h"



extern Watch MyWatch;

void Watch::Update() {
   MyWatch.ucSeconds++;
   MyWatch.fSecondsChanged = 1;
   if (6 == MyWatch.ucSeconds) {
      MyWatch.ucSeconds = 0;
      MyWatch.ucMinutes++;
      MyWatch.fMinutesChanged = 1;
   }
}


