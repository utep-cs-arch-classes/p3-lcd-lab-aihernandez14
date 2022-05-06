	#include <msp430.h>
	#include "led.h"

	.arch msp430g2553
	.p2align 1,0
	.text
	.extern P1DIR
	.extern P1OUT
	.extern LEDS
	.extern LED_RED
	.extern LED_GREEN
	.global led_changed

	.data

//Variables
red_on:
	.byte 0

green_on:
	.byte 0

led_changed:
	.byte 0

ledFlags:
	.byte 0

redVal:
	.byte 0
	.byte LED_RED

greenVal:
	.byte 0
	.byte LED_GREEN



//fucntions
led_init:
	bis LEDS, P1DIR
	mov #1, led_changed
	call led_update()

led_update:
	cmp #1, led_changed
	JNZ out
	mov &redVal, r12
	mov &greenVal, r13
	bis 0(r12), ledFlags
	bis 0(r13), ledFLags
	xor 0xff, LEDS
	or LEDS, r14
	and r14, P1OUT
	or ledFLags, P1OUT
	mov #0, led_changed
out:
	pop r12
