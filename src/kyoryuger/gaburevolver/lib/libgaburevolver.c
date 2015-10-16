#include <wiringPi.h>
#include <mcp23017.h>

#include "../libgaburevolver.h"
#include "../../judenchi.h"
#include "../../../toyhack.h"


/*
 * GPIO Pin table of Wiring Pi
 * https://projects.drogon.net/raspberry-pi/wiringpi/pins/
 */
#define GPIO_ROTATE        1 /* GPIO #18 */
#define GPIO_TRIGGER       6 /* GPIO #25 */
#define GPIO_SETTER        3 /* GPIO #22 */
#define GPIO_MINITYRA      4 /* GPIO #23 */
#define GPIO_GABURICALIBUR 5 /* GPIO #24 */

/* For MCP 23017 GPIO Expander */
#define I2C_ADDR  0x20
#define PIN_BASE  100
#define START_GPA 100
#define START_GPB 108


#define GET_SWITCH_BIT(location, bit) \
  (((judenchi_list[location].pattern) >> (5 - bit)) & 1) == 1 ? HIGH : LOW

static int initialized = 0;

#define INITIALIZE_CHECK \
  if(initialized != 1){   \
    return TOYHACK_ERROR; \
  }


int SetupGPIO(void){
  int Cnt;

  if(wiringPiSetup() == -1){
    return TOYHACK_ERROR;
  }

  if(mcp23017Setup(PIN_BASE, I2C_ADDR) == -1){
    return TOYHACK_ERROR;
  }

  pinMode(GPIO_ROTATE, OUTPUT);
  pinMode(GPIO_TRIGGER, OUTPUT);
  pinMode(GPIO_SETTER, OUTPUT);
  pinMode(GPIO_MINITYRA, OUTPUT);
  pinMode(GPIO_GABURICALIBUR, OUTPUT);

  /* Initialize all port on MCP 23017 */
  for(Cnt = 0; Cnt < 6; Cnt++){
    pinMode(START_GPA + Cnt, OUTPUT);
    digitalWrite(START_GPA + Cnt, LOW);
    pinMode(START_GPB + Cnt, OUTPUT);
    digitalWrite(START_GPB + Cnt, LOW);
  }

  initialized = 1;

  return TOYHACK_SUCCEEDED;
}

int OpenSetter(void){
  INITIALIZE_CHECK

  digitalWrite(GPIO_SETTER, HIGH);

  return TOYHACK_SUCCEEDED;
}

static void SetJudenchiInternal(int base, int sw){

  if(sw == -1){
    digitalWrite(base, LOW);
    digitalWrite(base + 1, LOW);
    digitalWrite(base + 2, LOW);
    digitalWrite(base + 3, LOW);
    digitalWrite(base + 4, LOW);
    digitalWrite(base + 5, LOW);
  }
  else{
    digitalWrite(base, GET_SWITCH_BIT(sw, 0));
    digitalWrite(base + 1, GET_SWITCH_BIT(sw, 1));
    digitalWrite(base + 2, GET_SWITCH_BIT(sw, 2));
    digitalWrite(base + 3, GET_SWITCH_BIT(sw, 3));
    digitalWrite(base + 4, GET_SWITCH_BIT(sw, 4));
    digitalWrite(base + 5, GET_SWITCH_BIT(sw, 5));
  }

}

int SetJudenchi(int lower_sw, int upper_sw){
  SetJudenchiInternal(START_GPA, lower_sw);
  SetJudenchiInternal(START_GPB, upper_sw);

  return TOYHACK_SUCCEEDED;
}

int CloseSetter(void){
  INITIALIZE_CHECK

  digitalWrite(GPIO_SETTER, LOW);

  return TOYHACK_SUCCEEDED;
}

int Rotate(void){
  int Cnt;

  INITIALIZE_CHECK

  for(Cnt = 0; Cnt < 10; Cnt++){
    digitalWrite(GPIO_ROTATE, HIGH);
    delay(50);
    digitalWrite(GPIO_ROTATE, LOW);
    delay(50);
  }

  return TOYHACK_SUCCEEDED;
}

int Trigger(void){
  INITIALIZE_CHECK

  digitalWrite(GPIO_TRIGGER, HIGH);
  delay(200);
  digitalWrite(GPIO_TRIGGER, LOW);

  return TOYHACK_SUCCEEDED;
}

int DockMinityra(void){
  INITIALIZE_CHECK

  digitalWrite(GPIO_MINITYRA, HIGH);

  return TOYHACK_SUCCEEDED;
}

int UndockMinityra(void){
  INITIALIZE_CHECK

  digitalWrite(GPIO_MINITYRA, LOW);

  return TOYHACK_SUCCEEDED;
}

int DockGaburicalibur(void){
  INITIALIZE_CHECK

  digitalWrite(GPIO_GABURICALIBUR, HIGH);

  return TOYHACK_SUCCEEDED;
}

int UndockGaburicalibur(void){
  INITIALIZE_CHECK

  digitalWrite(GPIO_GABURICALIBUR, LOW);

  return TOYHACK_SUCCEEDED;
}

