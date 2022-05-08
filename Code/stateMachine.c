#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"

char interruptTime;
char button_four;
u_int backgroundColor = COLOR_WHITE;

void state_advance(){

  const u_char text_row = 100;
  const u_char text_col = 40;
  my_shape(COLOR_RED);

  switch(state){

  default: state++;
  case 1:
    my_color=COLOR_BLUE;
    move_shape_Left(10);
    buzzer_set_period(0);
    drawString5x7(text_col, text_row, "Blue", COLOR_BLUE, backgroundColor);
    break;
  case 2:
    my_color=COLOR_RED;
    move_shape_Up(10);
    buzzer_set_period(200);
    drawString5x7(text_col, text_row, "Red", COLOR_RED, backgroundColor);
    break;
  case 3:
    my_color=COLOR_YELLOW;
    move_shape_Down(10);
    buzzer_set_period(300);
    drawString5x7(text_col, text_row, "Yellow", COLOR_YELLOW, backgroundColor);
    break;
  case 4:
    my_color=COLOR_MAGENTA;
    move_shape_Right(10);
    buzzer_set_period(400);
    drawString5x7(text_col, text_row, "Magenta", COLOR_MAGENTA, backgroundColor);
    break;
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
