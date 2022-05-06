#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"

char interruptTime;
char button_four;

void state_advance(){
  
  my_shape(COLOR_RED);

  switch(state){

  default: state++;
  case 1: my_color=COLOR_BLUE; move_shape_Left(10); break;
  case 2: my_color=COLOR_RED; move_shape_Up(10); break;
  case 3: my_color=COLOR_YELLOW; move_shape_Down(10); break;
  case 4: my_color=COLOR_MAGENTA; move_shape_Right(10); break;
  }
}

// Helper functions
void turn_on_red(){
  red_on=1;
  led_changed = 1;
  led_update();
}
void turn_on_green(){
  green_on=1;
  led_changed = 1;
  led_update();
}
void turn_off_red(){
  red_on=0;
  led_changed=1;
  led_update();
}
void turn_off_green(){
  green_on=0;
  led_changed=1;
  led_update();
}
