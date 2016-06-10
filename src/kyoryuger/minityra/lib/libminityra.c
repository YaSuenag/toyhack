#include <wiringPi.h>
#include <mcp23017.h>

#include <toyhack.h>

#include "libminityra.h"
#include "../../judenchi.h"


/*
 * GPIO Pin table of Wiring Pi
 * https://projects.drogon.net/raspberry-pi/wiringpi/pins/
 */
#define GPIO_GABU         1 /* GPIO #18 */
#define GPIO_KURURINCHO   6 /* GPIO #25 */
#define GPIO_GABUREVOLVER 3 /* GPIO #22 */
#define GPIO_TRIGGER      4 /* GPIO #23 */
#define GPIO_SIDESWITCH   5 /* GPIO #24 */

/* For MCP 23017 GPIO Expander */
#define I2C_ADDR  0x20
#define PIN_BASE  100
#define START_GPA 100


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

  pinMode(GPIO_GABU, OUTPUT);
  pinMode(GPIO_KURURINCHO, OUTPUT);
  pinMode(GPIO_GABUREVOLVER, OUTPUT);
  pinMode(GPIO_TRIGGER, OUTPUT);
  pinMode(GPIO_SIDESWITCH, OUTPUT);

  /* Initialize all port on MCP 23017 */
  for(Cnt = 0; Cnt < 6; Cnt++){
    pinMode(START_GPA + Cnt, OUTPUT);
    digitalWrite(START_GPA + Cnt, LOW);
  }

  initialized = 1;

  return TOYHACK_SUCCEEDED;
}

int SetJudenchi(int id){
  INITIALIZE_CHECK

  if(id == -1){
    digitalWrite(START_GPA, LOW);
    digitalWrite(START_GPA + 1, LOW);
    digitalWrite(START_GPA + 2, LOW);
    digitalWrite(START_GPA + 3, LOW);
    digitalWrite(START_GPA + 4, LOW);
    digitalWrite(START_GPA + 5, LOW);
  }
  else{
    digitalWrite(START_GPA, GET_SWITCH_BIT(id, 0));
    digitalWrite(START_GPA + 1, GET_SWITCH_BIT(id, 1));
    digitalWrite(START_GPA + 2, GET_SWITCH_BIT(id, 2));
    digitalWrite(START_GPA + 3, GET_SWITCH_BIT(id, 3));
    digitalWrite(START_GPA + 4, GET_SWITCH_BIT(id, 4));
    digitalWrite(START_GPA + 5, GET_SWITCH_BIT(id, 5));
  }

  return TOYHACK_SUCCEEDED;
}

int Gabu(void){
  INITIALIZE_CHECK

  digitalWrite(GPIO_GABU, HIGH);
  delay(100);
  digitalWrite(GPIO_GABU, LOW);

  return TOYHACK_SUCCEEDED;
}

int Kururincho(int mode){
  INITIALIZE_CHECK

  if((mode < MODE_OVERCHARGE)  || (mode > MODE_CARNIVAL)){
    return TOYHACK_ERROR;
  }

  digitalWrite(GPIO_KURURINCHO, (mode == MODE_CARNIVAL) ? HIGH : LOW);

  return TOYHACK_SUCCEEDED;
}

int DockGaburevolver(void){
  INITIALIZE_CHECK

  digitalWrite(GPIO_GABUREVOLVER, HIGH);

  return TOYHACK_SUCCEEDED;
}

int UndockGaburevolver(void){
  INITIALIZE_CHECK

  digitalWrite(GPIO_GABUREVOLVER, LOW);

  return TOYHACK_SUCCEEDED;
}

int Trigger(void){
  INITIALIZE_CHECK

  digitalWrite(GPIO_TRIGGER, HIGH);
  delay(200);
  digitalWrite(GPIO_TRIGGER, LOW);

  return TOYHACK_SUCCEEDED;
}

int SideSwitch(void){
  INITIALIZE_CHECK

  digitalWrite(GPIO_SIDESWITCH, HIGH);
  delay(200);
  digitalWrite(GPIO_SIDESWITCH, LOW);


  return TOYHACK_SUCCEEDED;
}

