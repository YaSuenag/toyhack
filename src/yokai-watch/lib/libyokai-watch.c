#include <wiringPi.h>

#include <toyhack.h>

#include "libyokai-watch.h"
#include "../yokai-medal.h"


/*
 * GPIO Pin table of Wiring Pi
 * http://wiringpi.com/pins/
 */
#define GPIO_SW6  0 /* GPIO #11 */
#define GPIO_SW5  1 /* GPIO #12 */
#define GPIO_SW4  3 /* GPIO #15 */
#define GPIO_SW3  4 /* GPIO #16 */

#define GET_SWITCH_BIT(val, row, col) \
  (((val >> (12 - (row * 4))) >> (3 - col)) & 0x1) ? HIGH : LOW

static int initialized = 0;

static int current_medal_pattern = -1;

#define INITIALIZE_CHECK \
  if(initialized != 1){   \
    return TOYHACK_ERROR; \
  }


int SetupGPIO(void){

  if(wiringPiSetup() == -1){
    return TOYHACK_ERROR;
  }

  pinMode(GPIO_SW3, OUTPUT);
  pinMode(GPIO_SW4, OUTPUT);
  pinMode(GPIO_SW5, OUTPUT);
  pinMode(GPIO_SW6, OUTPUT);

  digitalWrite(GPIO_SW6, LOW);
  digitalWrite(GPIO_SW5, LOW);
  digitalWrite(GPIO_SW4, LOW);
  digitalWrite(GPIO_SW3, LOW);

  initialized = 1;

  return TOYHACK_SUCCEEDED;
}

static int DigitalOut(int pattern, int is_reverse){
  int row;
  int out_pattern;

  INITIALIZE_CHECK

  if(is_reverse){
    out_pattern = ((pattern & 0xf) << 12)   | ((pattern & 0xf0) << 4) |
                  ((pattern & 0xf00)  >> 4) | ((pattern & 0xf000) >> 12);
  }
  else{
    out_pattern = pattern;
  }

  for(row = 0; row < 4; row++){
    digitalWrite(GPIO_SW6,GET_SWITCH_BIT(out_pattern, row, 0));
    digitalWrite(GPIO_SW5,GET_SWITCH_BIT(out_pattern, row, 1));
    digitalWrite(GPIO_SW4,GET_SWITCH_BIT(out_pattern, row, 2));
    digitalWrite(GPIO_SW3,GET_SWITCH_BIT(out_pattern, row, 3));
    delay(30);

    digitalWrite(GPIO_SW6, LOW);
    digitalWrite(GPIO_SW5, LOW);
    digitalWrite(GPIO_SW4, LOW);
    digitalWrite(GPIO_SW3, LOW);
    delay(30);
  }

  return TOYHACK_SUCCEEDED;
}

int EjectMedal(void){
  int result = TOYHACK_SUCCEEDED;

  if(current_medal_pattern != -1){
    result = DigitalOut(current_medal_pattern, 1);
  }

  current_medal_pattern = -1;

  return result;
}

int SetMedal(int id){
  int result = TOYHACK_SUCCEEDED;

  if(current_medal_pattern != -1){
    if((result = EjectMedal()) != TOYHACK_SUCCEEDED){
      return result;
    }

    delay(500);
  }

  result = DigitalOut(medal_list[id].pattern, 0);
  current_medal_pattern = medal_list[id].pattern;

  return result;
}

