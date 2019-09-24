opt subtitle "HI-TECH Software Omniscient Code Generator (PRO mode) build 10920"

opt pagewidth 120

	opt pm

	processor	16F690
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
indf	equ	0
indf0	equ	0
pc	equ	2
pcl	equ	2
status	equ	3
fsr	equ	4
fsr0	equ	4
c	equ	1
z	equ	0
pclath	equ	10
	FNCALL	_main,_OSC_init
	FNROOT	_main
	global	_OSCCON
psect	text30,local,class=CODE,delta=2
global __ptext30
__ptext30:
_OSCCON	set	143
	global	_TRISA
_TRISA	set	133
	global	_TRISB
_TRISB	set	134
	global	_TRISC
_TRISC	set	135
	global	_ANSEL
_ANSEL	set	286
	global	_LATA
_LATA	set	261
	global	_LATB
_LATB	set	262
	global	_LATC
_LATC	set	263
	global	_MCUCR
_MCUCR	set	415
	file	"demo.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_OSC_init
?_OSC_init:	; 0 bytes @ 0x0
	global	??_OSC_init
??_OSC_init:	; 0 bytes @ 0x0
	global	??_main
??_main:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 2 bytes @ 0x0
;;Data sizes: Strings 0, constant 0, data 0, bss 0, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      0       0
;; BANK0           80      0       0
;; BANK1           80      0       0
;; BANK2           80      0       0

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   None.
;;
;; Critical Paths under _main in BANK0
;;
;;   None.
;;
;; Critical Paths under _main in BANK1
;;
;;   None.
;;
;; Critical Paths under _main in BANK2
;;
;;   None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 0     0      0       0
;;                           _OSC_init
;; ---------------------------------------------------------------------------------
;; (1) _OSC_init                                             0     0      0       0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 1
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;   _OSC_init
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            E      0       0       0        0.0%
;;EEDATA             100      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;COMMON               E      0       0       1        0.0%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       1       2        0.0%
;;BANK0               50      0       0       3        0.0%
;;BITBANK1            50      0       0       4        0.0%
;;BITSFR3              0      0       0       4        0.0%
;;SFR3                 0      0       0       4        0.0%
;;BANK1               50      0       0       5        0.0%
;;BITSFR2              0      0       0       5        0.0%
;;SFR2                 0      0       0       5        0.0%
;;BITBANK2            50      0       0       6        0.0%
;;BANK2               50      0       0       7        0.0%
;;ABS                  0      0       0       8        0.0%
;;BITBANK0            50      0       0       9        0.0%
;;DATA                 0      0       0      10        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 24 in file "E:\demo\demo.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  2  1861[COMMON] int 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    1
;; This function calls:
;;		_OSC_init
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"E:\demo\demo.c"
	line	24
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 7
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	25
	
l3092:	
;demo.c: 25: OSC_init();
	fcall	_OSC_init
	line	28
	
l3094:	
;demo.c: 28: TRISA = 0x80;
	movlw	(080h)
	bcf	status, 6	;RP1=0, select bank1
	movwf	(133)^080h	;volatile
	line	31
	
l3096:	
;demo.c: 31: TRISB = 0x86;
	movlw	(086h)
	movwf	(134)^080h	;volatile
	line	33
	
l3098:	
;demo.c: 33: TRISC = 0x00;
	clrf	(135)^080h	;volatile
	line	35
	
l3100:	
;demo.c: 35: ANSEL = 0x00;
	bcf	status, 5	;RP0=0, select bank2
	bsf	status, 6	;RP1=1, select bank2
	clrf	(286)^0100h	;volatile
	line	39
	
l3102:	
;demo.c: 37: {
;demo.c: 39: LATA = 0x80;
	movlw	(080h)
	bcf	status, 5	;RP0=0, select bank2
	bsf	status, 6	;RP1=1, select bank2
	movwf	(261)^0100h	;volatile
	line	40
	
l3104:	
;demo.c: 40: LATB = 0x86;
	movlw	(086h)
	movwf	(262)^0100h	;volatile
	line	41
	
l3106:	
;demo.c: 41: LATC = 0x00;
	clrf	(263)^0100h	;volatile
	line	42
	
l3108:	
;demo.c: 42: _nop();
	nop
	line	45
	
l3110:	
;demo.c: 45: LATA = 0xff;
	movlw	(0FFh)
	bcf	status, 5	;RP0=0, select bank2
	bsf	status, 6	;RP1=1, select bank2
	movwf	(261)^0100h	;volatile
	line	46
	
l3112:	
;demo.c: 46: LATB = 0xff;
	movlw	(0FFh)
	movwf	(262)^0100h	;volatile
	line	47
	
l3114:	
;demo.c: 47: LATC = 0xff;
	movlw	(0FFh)
	movwf	(263)^0100h	;volatile
	line	48
	
l3116:	
;demo.c: 48: _nop();
	nop
	goto	l3102
	global	start
	ljmp	start
	opt stack 0
psect	maintext
	line	51
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,90
	global	_OSC_init
psect	text31,local,class=CODE,delta=2
global __ptext31
__ptext31:

;; *************** function _OSC_init *****************
;; Defined at:
;;		line 15 in file "E:\demo\demo.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 17F/60
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text31
	file	"E:\demo\demo.c"
	line	15
	global	__size_of_OSC_init
	__size_of_OSC_init	equ	__end_of_OSC_init-_OSC_init
	
_OSC_init:	
	opt	stack 7
; Regs used in _OSC_init: [wreg+status,2+status,0]
	line	17
	
l3088:	
;demo.c: 17: OSCCON = 0x60;
	movlw	(060h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(143)^080h	;volatile
	line	19
;demo.c: 19: MCUCR = 0x55;
	movlw	(055h)
	bsf	status, 6	;RP1=1, select bank3
	movwf	(415)^0180h	;volatile
	line	20
	
l3090:	
;demo.c: 20: MCUCR = MCUCR & 0xf9;
	movlw	(0F9h)
	andwf	(415)^0180h,f	;volatile
	line	21
	
l1859:	
	return
	opt stack 0
GLOBAL	__end_of_OSC_init
	__end_of_OSC_init:
;; =============== function _OSC_init ends ============

	signat	_OSC_init,88
psect	text32,local,class=CODE,delta=2
global __ptext32
__ptext32:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
