
	#include "lcddraw.h"
	#include "switches.h"
	#include "lcdutils.h"
	#include "stateMachine.h"
	#include "buzzer.h"


	.arch msp430g2553
	.p2align 1,0

	.text
	.global state_advance
	.global state
	.extern move_shape_Left
	.extern move_shape_Right
	.extern move_shape_Up
	.extern move_shape_Down
	.extern clearScreen
	.extern COLOR_RED
	.extern COLOR_YELLOW
	.extern COLOR_MAGENTA
	.extern COLOR_BLUE

	.data
	.extern my_color

state:
	.word 0

jt:
	.word default
	.word case_1
	.word case_2
	.word case_3
	.word case_4


state_advance:
	mov &state, r12		;MOVES STATE INTO REGISTER 12
	add r12, r12
	mov jt(r12), r0		;INDEXES JT TABLE IN REGISTER 0

default:
	mov #1, &state

case_1:
	mov #10, r12
	mov &COLOR_BLUE, &my_color
	call #move_shape_Left
	jmp end

case_2:
	mov #10, r12
	mov &COLOR_RED, &my_color
	call #move_shape_Right
	jmp end

case_3:
	mov 0x001f, r12
	mov &COLOR_YELLOW, &my_color
	call #move_shape_Up
	jmp end

case_4:
	mov &COLOR_MAGENTA, r12
	mov &COLOR_MAGENTA, &my_color
	call #move_shape_Left
	jmp end
end:
	pop r0
