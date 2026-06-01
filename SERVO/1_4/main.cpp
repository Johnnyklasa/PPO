#include "keyboard.h"
#include "servo.h"
#include "uart.h"
#include "strings.h"
#include "decoder.h"
#include "watch.h"
#include "timer_interrupts.h"


Watch MyWatch;
Servo MyServo;
extern struct Token asTokens[];
extern unsigned char ucTokenNr;



void Timer0_Handler(){
	MyWatch.Update();
}

void Timer1_Handler(){
	MyServo.Automate();
}
int main() {

   char fSend_UnknownCommand = 0;
   char fSend_ID = 1;
   char fSend_OK = 1;

  Keyboard_Init();
  UART_Init();
	MyServo.Init();
	Timer0Interrupts_Init(1000000, &Timer0_Handler);
	Timer1Interrupts_Init(100000, &Timer1_Handler);

		
   while (1) {

      switch (eKeyboard_Read()) {

         case BUTTON_1:
            MyServo.Callib();
            break;

         case BUTTON_2:
            MyServo.GoTo(12);
            break;

         case BUTTON_3:
            MyServo.GoTo(24);
            break;

         case BUTTON_4:
            MyServo.GoTo(36);
            break;

         default:
            break;
         }

      if (READY == eUART_Rx_GetStatus()) {
         char acRxString[RX_BUFFER_SIZE];
         UART_Rx_GetStringCopy(acRxString);
         DecodeMsg(acRxString);

         if ((ucTokenNr != 0) && (asTokens[0].eType == KEYWORD)) {
            switch (asTokens[0].uValue.eKeywordCode) {

               case ID:
                  MyServo.Callib();
                  fSend_ID = 1;
                  break;

               case CALLIB:
                  MyServo.Callib();
                  fSend_OK = 1;
                  break;

               case GOTO:
                  MyServo.GoTo(asTokens[1].uValue.uiNumber);
                  fSend_OK = 1;
                  break;

               default:
                  fSend_UnknownCommand = 1;
                  break;
            }
         } else {
            fSend_UnknownCommand = 1;
         }
      }

      if (eUART_Tx_GetStatus() == FREE) {
         char cStringToSend[TX_BUFFER_SIZE];

         if (fSend_ID) {
            fSend_ID = 0;
            UART_Tx_SendString("servo\n");
         } else if (fSend_UnknownCommand) {
            fSend_UnknownCommand = 0;
            UART_Tx_SendString("unknowncommand\n");
         } else if (fSend_OK) {
            fSend_OK = 0;
            UART_Tx_SendString("ok\n");
         } else if (MyWatch.fSecondsChanged) {
            MyWatch.fSecondsChanged = 0;
            CopyString("sec ", cStringToSend);
            AppendUIntToString(MyWatch.ucSeconds, cStringToSend);
            AppendString("\n", cStringToSend);
            UART_Tx_SendString(cStringToSend);
         } else if (MyWatch.fMinutesChanged) {
            MyWatch.fMinutesChanged = 0;
            CopyString("min ", cStringToSend);
            AppendUIntToString(MyWatch.ucMinutes, cStringToSend);
            AppendString("\n", cStringToSend);
            UART_Tx_SendString(cStringToSend);
         }
      }
   }
}
