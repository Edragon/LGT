opt subtitle "HI-TECH Software Omniscient Code Generator (PRO mode) build 10920"

opt pagewidth 120

	opt pm

	processor	16F684
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
# 14 "E:\Projects\LGT8F684A\test\Tests\Cases\Start\lgt8f684a_get_start\src\ex02\ex02.c"
	psect eeprom_data,class=EEDATA,delta=2,space=2 ;#
# 14 "E:\Projects\LGT8F684A\test\Tests\Cases\Start\lgt8f684a_get_start\src\ex02\ex02.c"
	dw	0x7FFF & 0xFDFF & 0xFFDF & 0xFFBF ;#
# 18 "E:\Projects\LGT8F684A\test\Tests\Cases\Start\lgt8f684a_get_start\src\ex02\ex02.c"
	psect eeprom_data,class=EEDATA,delta=2,space=2 ;#
# 18 "E:\Projects\LGT8F684A\test\Tests\Cases\Start\lgt8f684a_get_start\src\ex02\ex02.c"
	dw	0x7FFF & 0xFE7F & 0xFDFF ;#
# 22 "E:\Projects\LGT8F684A\test\Tests\Cases\Start\lgt8f684a_get_start\src\ex02\ex02.c"
	psect config,class=CONFIG,delta=2 ;#
# 22 "E:\Projects\LGT8F684A\test\Tests\Cases\Start\lgt8f684a_get_start\src\ex02\ex02.c"
	dw 0x0000 ;#
	FNROOT	_main
	global	_PORTA
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:
_PORTA	set	5
	global	_PORTC
_PORTC	set	7
	global	_ANSEL
_ANSEL	set	145
	global	_TRISA
_TRISA	set	133
	global	_TRISC
_TRISC	set	135
	file	"ex02.as"
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
	global	??_main
??_main:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 2 bytes @ 0x0
;;Data sizes: Strings 0, constant 0, data 0, bss 0, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      0       0
;; BANK0           80      0       0
;; BANK1           32      0       0

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
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 0     0      0       0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 0
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
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
;;STACK                0      0       0       2        0.0%
;;BITBANK0            50      0       0       3        0.0%
;;BANK0               50      0       0       4        0.0%
;;BANK1               20      0       0       5        0.0%
;;ABS                  0      0       0       6        0.0%
;;BITBANK1            20      0       0       7        0.0%
;;DATA                 0      0       0       8        0.0%

	global	_main
psect	maintext

;; *************** function _main *****************
;; Defined at:
;;		line 25 in file "E:\Projects\LGT8F684A\test\Tests\Cases\Start\lgt8f684a_get_start\src\ex02\ex02.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  2  928[COMMON] int 
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"E:\Projects\LGT8F684A\test\Tests\Cases\Start\lgt8f684a_get_start\src\ex02\ex02.c"
	line	25
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 8
; Regs used in _main: [wreg+status,2]
	line	28
	
l1857:	
;ex02.c: 28: TRISA = 0x03;
	movlw	(03h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	31
	
l1859:	
;ex02.c: 31: TRISC = 0x00;
	clrf	(135)^080h	;volatile
	line	34
	
l1861:	
;ex02.c: 34: ANSEL = 0x00;
	clrf	(145)^080h	;volatile
	line	36
;ex02.c: 36: while(1)
	
l929:	
	line	39
;ex02.c: 37: {
;ex02.c: 39: PORTA = 0x03;
	movlw	(03h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(5)	;volatile
	line	40
	
l1863:	
;ex02.c: 40: PORTC = 0x00;
	clrf	(7)	;volatile
	line	41
	
l1865:	
;ex02.c: 41: _nop();
	nop
	line	43
	
l1867:	
;ex02.c: 43: PORTA = 0xff;
	movlw	(0FFh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(5)	;volatile
	line	44
	
l1869:	
;ex02.c: 44: PORTC = 0xff;
	movlw	(0FFh)
	movwf	(7)	;volatile
	line	45
	
l1871:	
;ex02.c: 45: _nop();
	nop
	goto	l929
	global	start
	ljmp	start
	opt stack 0
psect	maintext
	line	47
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,90
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
