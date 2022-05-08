#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachine.h"

char state =0;
char switch_state_down_1, switch_state_changed;  /* effectively boolean */
char switch_state_down_2; /* effectively boolean */
char switch_state_down_3; /* effectively boolean */
char switch_state_down_4; /* effectively boolean */

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */
  return p2val;
}

void switch_init()/* setup switch */
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE |= SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down_1 = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_down_2 = (p2val & SW2) ? 0 : 1; /* 0 when SW2 is up */
  switch_state_down_3 = (p2val & SW3) ? 0 : 1; /* 0 when SW3 is up */
  switch_state_down_4 = (p2val & SW4) ? 0 : 1; /* 0 when SW4 is up */
  switch_state_changed = 1;

  if(switch_state_down_1){
    state=1;
    state_advance();
  }
  if(switch_state_down_2){
    state=2;
    state_advance();
  }
  if(switch_state_down_3){
    state=3;
    state_advance();
  }
  if(switch_state_down_4){
    state=4;
    state_advance();
  }
}

