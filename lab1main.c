/************** ECE2049 DEMO CODE ******************/
/**************  28 March 2020   ******************/
/*********Redesigned by Hamayel Qureshi********/
/***************************************************/

#include <msp430.h>
#include "peripherals.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void swDelay(int numLoops);
void WELCOME();
void COUNTDOWN();
void playseq();
void BuzzerOn();
void numGenerator();
void display();
void checkplayerinput();
void dispNum();
void LEDOn();
void LEDOff();

//Global Variables
int state = 0;
int min_num = 1;
int max_num = 4;
int num_array[10];
int isCorrect[10];
int j;
int k;
int i;
int Round = 0;
int num;
int c;


void main(void){
    unsigned char currKey=0, dispSz = 3;
    //  unsigned char dispThree[3];

      WDTCTL = WDTPW | WDTHOLD;

      // Useful code starts here
       initLeds();
       configDisplay();
       configKeypad();

       P1SEL = P1SEL & ~BIT0;
       P1DIR |= BIT0;

       // *** Intro Screen ***
        Graphics_clearDisplay(&g_sContext); // Clear the display

        while(1) ///Forever loop
        {
            unsigned char currKey = getKey();

                switch(state){

                                case 0:

                                    WELCOME();
                                    break;
                                case 1:
                                    //state = 1;
                                    COUNTDOWN();
                                    //Graphics_clearDisplay(&g_sContext);
                                    //Graphics_flushBuffer(&g_sContext);
                                    break;
                                case 2:

                                    /*Graphics_clearDisplay(&g_sContext);
                                    Graphics_drawStringCentered(&g_sContext, "Game Starting Now", AUTO_STRING_LENGTH, 64, 25, TRANSPARENT_TEXT);
                                    Graphics_flushBuffer(&g_sContext);
                                    swDelay(5);*/

                               /*     Graphics_clearDisplay(&g_sContext);
                                    for (j = 0; j<10; j++){
                                       num_array[j] = rand() %4+1; //((max_num - min_num + 1) + min_num);
                                    }
                                    for (j = 0; j<10; j++){

                                        dispNum(num_array[j]);

                                    }
*/
                                    playseq();

                                    break;

                                case 3:
                                    Graphics_drawStringCentered(&g_sContext, "Shawty", AUTO_STRING_LENGTH, 64, 25, TRANSPARENT_TEXT);
                                   checkplayerinput();
                                    break;

                                }

           if (currKey == '*')
                state = 1;
            //break;
        } //ends while loop

        //Random Number Generator
        //int state = 0;

        }

void LEDOn(){
    P1OUT |= BIT0;
}

void LEDOff(){
    P1OUT = P1OUT & ~BIT0;
}

void numGenerator() {
    for (j = 0; j<=10; j++){
       num_array[j] = rand() % (max_num - min_num + 1) + min_num;
       j++;
    }
}

void playseq(){
    unsigned char currKey;
    Graphics_clearDisplay(&g_sContext);
     for (j = 0; j < 10; j++){
         num_array[j] = rand() %4+1; //((max_num - min_num + 1) + min_num);
         dispNum(num_array[j]);
         state = 3;
       }}

      //for (j = 0; j<10; j++){

            //dispNum(num_array[j]);
           // checkplayerinput();
            //if (getKey() == num_array[j]){
            //    isCorrect[j] = num_array[j];
        //}
  /*              for (k = 0; k<10; k++){
                    currKey = getKey();
                    num = currKey - '0';
                    if((num_array[k] != num) && (num != '*')){
                        Round = Round +1;
                    for (i = 0; i<Round; i++){
                        dispNum(num_array[i]);
                    }
          }
*/








/*void display(){
    for(x = 0; x<Rounds; x++){
        Graphics_clearDisplay(&g_sContext);
        dispNum(x);
        Graphics_flushBuffer(&g_sContext);
        swDelay(10);
    }
}*/

void dispNum(int x){
    if (x == 1){
        Graphics_clearDisplay(&g_sContext);
        BuzzerOn();
        LEDOn();
        Graphics_drawStringCentered(&g_sContext, "1", AUTO_STRING_LENGTH, 24, 25, TRANSPARENT_TEXT);
        swDelay(2);
        BuzzerOff();
        LEDOff();
        Graphics_flushBuffer(&g_sContext);
        swDelay(5);
    }
    else if (x ==2){
        Graphics_clearDisplay(&g_sContext);
        BuzzerOn();
        LEDOn();
        Graphics_drawStringCentered(&g_sContext, "2", AUTO_STRING_LENGTH, 44, 25, TRANSPARENT_TEXT);
        swDelay(2);
        BuzzerOff();
        LEDOff();
        Graphics_flushBuffer(&g_sContext);
        swDelay(5);
    }
    else if (x ==3){
        Graphics_clearDisplay(&g_sContext);
        BuzzerOn();
        LEDOn();
        Graphics_drawStringCentered(&g_sContext, "3", AUTO_STRING_LENGTH, 64, 25, TRANSPARENT_TEXT);
        swDelay(2);
        BuzzerOff();
        LEDOff();
        Graphics_flushBuffer(&g_sContext);
        swDelay(5);
    }
    else if (x ==4){
        Graphics_clearDisplay(&g_sContext);
        BuzzerOn();
        LEDOn();
        Graphics_drawStringCentered(&g_sContext, "4", AUTO_STRING_LENGTH, 84, 25, TRANSPARENT_TEXT);
        swDelay(2);
        BuzzerOff();
        LEDOff();
        Graphics_flushBuffer(&g_sContext);
        swDelay(5);
    }
}


void checkplayerinput(){
    unsigned char currKey = getKey();
    for(c = 0; c<10; c++){
        currKey = getKey();
        num = currKey - '0';
        //dispNum(num);
        //Round = Round + 1;
        if (getKey() != num_array[c]){
                  Graphics_drawStringCentered(&g_sContext, "Incorrect. End Game.", AUTO_STRING_LENGTH, 64, 25, TRANSPARENT_TEXT);
                  state = 0;
              }
        state = 2;
    }


}


void WELCOME() {

           Graphics_drawStringCentered(&g_sContext, "ECE2049 SIMON Game", AUTO_STRING_LENGTH, 64, 25, TRANSPARENT_TEXT);
           Graphics_drawStringCentered(&g_sContext, "Press * to start", AUTO_STRING_LENGTH, 64, 45, TRANSPARENT_TEXT);
           Graphics_flushBuffer(&g_sContext);
       }

void COUNTDOWN() {
       Graphics_clearDisplay(&g_sContext);
       Graphics_drawStringCentered(&g_sContext, "Count down to Game:", AUTO_STRING_LENGTH, 64, 25, TRANSPARENT_TEXT);
       Graphics_flushBuffer(&g_sContext);
       swDelay(5);

       Graphics_clearDisplay(&g_sContext);
       Graphics_drawStringCentered(&g_sContext, "3", AUTO_STRING_LENGTH, 40, 25, TRANSPARENT_TEXT);
       Graphics_flushBuffer(&g_sContext);
       swDelay(5);

       Graphics_clearDisplay(&g_sContext);
       Graphics_drawStringCentered(&g_sContext, "2", AUTO_STRING_LENGTH, 40, 25, TRANSPARENT_TEXT);
       Graphics_flushBuffer(&g_sContext);
       swDelay(5);

       Graphics_clearDisplay(&g_sContext);
       Graphics_drawStringCentered(&g_sContext, "1", AUTO_STRING_LENGTH, 40, 25, TRANSPARENT_TEXT);
       Graphics_flushBuffer(&g_sContext);
       swDelay(5);

       state = 2;

   }

void swDelay(int numLoops)
    {

        volatile unsigned int i,j;  // volatile to prevent removal in optimization
                                    // by compiler. Functionally this is useless code

        for (j=0; j<numLoops; j++)
        {
            i = 50000 ;                 // SW Delay
            while (i > 0)               // could also have used while (i)
               i--;
        }
    }
