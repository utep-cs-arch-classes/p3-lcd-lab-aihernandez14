	.text
	.balign 2		;align to an even address
	.global	WDT
;;;  WDT uses interrupt #11
;;;  flags: "a"=allocatable, "x"=executable
	.section	__interrupt_vector_11,"ax"
	.word	WDT		;entry for vector table
	.text


	.extern redrawScreen
	.extern wdt_c_handler
WDT:
	;;  start of function
	;;  attributes: interrupt
	;;  framesize_regs:     24
	;;  framesize_locals:   0
	;;  framesize_outgoing: 0
	;;  framesize:          24
	;;  elim ap -> fp       26
	;;  elim fp -> sp       0
	;;  saved regs: R4 R5 R6 R7 R8 R9 R10 R11 R12 R13 R14 R15
	;;  start of prologue
	PUSH	R15
	PUSH	R14
	PUSH	R13
	PUSH	R12
	PUSH	R11
	PUSH	R10
	PUSH	R9
	PUSH	R8
	PUSH	R7
	PUSH	R6
	PUSH	R5
	PUSH	R4
	;;  end of prologue
	CALL	#wdt_c_handler
	;;  start of epilogue
	POP	R4
	POP	R5
	POP	R6
	POP	R7
	POP	R8
	POP	R9
	POP	R10
	POP	R11
	POP	R12
	POP	R13
	POP	R14
	POP	R15
	cmp	#0, &redrawScreen
	jz	dont_wake
	and	#0xffef, 0(r1)	; clear CPU off in saved SR
dont_wake:
	RETI
