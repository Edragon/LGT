opt subtitle "HI-TECH Software Omniscient Code Generator (PRO mode) build 10920"

opt pagewidth 120

	opt pm

	processor	12F609
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
	FNCALL	_main,_sys_init
	FNCALL	_main,_uart_putc
	FNCALL	_sys_init,_uart_init
	FNCALL	_sys_init,_io_init
	FNCALL	_sys_init,_tmr0_init
	FNROOT	_main
	FNCALL	intlevel1,_hisr
	global	intlevel1
	FNROOT	intlevel1
	global	_ird_flg
	global	_ird_prd
	global	_ird_cnt
	global	_GIE
psect	text158,local,class=CODE,delta=2
global __ptext158
__ptext158:
_GIE	set	95
	global	_GPIE
_GPIE	set	91
	global	_GPIF
_GPIF	set	88
	global	_RA5
_RA5	set	45
	global	_T0IE
_T0IE	set	93
	global	_T0IF
_T0IF	set	90
	global	_ANSEL
_ANSEL	set	159
	global	_IOCA
_IOCA	set	150
	global	_OPTION_REG
_OPTION_REG	set	129
	global	_PR0L
_PR0L	set	146
	global	_T0CON
_T0CON	set	145
	global	_WPUA
_WPUA	set	149
	global	_CWOK
_CWOK	set	1142
	global	_TRISA5
_TRISA5	set	1069
	global	_nGPPU
_nGPPU	set	1039
	global	_RA2
_RA2	set	42
	file	"iocr_ira.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect	bssCOMMON,class=COMMON,space=1
global __pbssCOMMON
__pbssCOMMON:
_ird_cnt:
       ds      1

psect	bssBANK0,class=BANK0,space=1
global __pbssBANK0
__pbssBANK0:
_ird_flg:
       ds      1

_ird_prd:
       ds      1

; Clear objects allocated to COMMON
psect cinit,class=CODE,delta=2
	clrf	((__pbssCOMMON)+0)&07Fh
; Clear objects allocated to BANK0
psect cinit,class=CODE,delta=2
	clrf	((__pbssBANK0)+0)&07Fh
	clrf	((__pbssBANK0)+1)&07Fh
psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_sys_init
?_sys_init:	; 0 bytes @ 0x0
	global	?_uart_putc
?_uart_putc:	; 0 bytes @ 0x0
	global	?_uart_init
?_uart_init:	; 0 bytes @ 0x0
	global	?_io_init
?_io_init:	; 0 bytes @ 0x0
	global	?_tmr0_init
?_tmr0_init:	; 0 bytes @ 0x0
	global	?_hisr
?_hisr:	; 0 bytes @ 0x0
	global	??_hisr
??_hisr:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 2 bytes @ 0x0
	ds	2
	global	??_sys_init
??_sys_init:	; 0 bytes @ 0x2
	global	??_uart_putc
??_uart_putc:	; 0 bytes @ 0x2
	global	??_uart_init
??_uart_init:	; 0 bytes @ 0x2
	global	??_io_init
??_io_init:	; 0 bytes @ 0x2
	global	??_tmr0_init
??_tmr0_init:	; 0 bytes @ 0x2
	ds	1
	global	uart_putc@c
uart_putc@c:	; 1 bytes @ 0x3
	ds	1
	global	uart_putc@i
uart_putc@i:	; 1 bytes @ 0x4
	ds	1
	global	??_main
??_main:	; 0 bytes @ 0x5
psect	cstackBANK0,class=BANK0,space=1
global __pcstackBANK0
__pcstackBANK0:
	global	main@ira_buf
main@ira_buf:	; 5 bytes @ 0x0
	ds	5
	global	main@ira_bit
main@ira_bit:	; 1 bytes @ 0x5
	ds	1
	global	main@edg_flg
main@edg_flg:	; 1 bytes @ 0x6
	ds	1
	global	main@main_st
main@main_st:	; 1 bytes @ 0x7
	ds	1
;;Data sizes: Strings 0, constant 0, data 0, bss 3, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      5       6
;; BANK0           48      8      10

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   _main->_uart_putc
;;
;; Critical Paths under _hisr in COMMON
;;
;;   None.
;;
;; Critical Paths under _main in BANK0
;;
;;   None.
;;
;; Critical Paths under _hisr in BANK0
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
;; (0) _main                                                 8     8      0     441
;;                                              0 BANK0      8     8      0
;;                           _sys_init
;;                          _uart_putc
;; ---------------------------------------------------------------------------------
;; (1) _uart_putc                                            3     3      0      69
;;                                              2 COMMON     3     3      0
;; ---------------------------------------------------------------------------------
;; (1) _sys_init                                             0     0      0       0
;;                          _uart_init
;;                            _io_init
;;                          _tmr0_init
;; ---------------------------------------------------------------------------------
;; (2) _tmr0_init                                            0     0      0       0
;; ---------------------------------------------------------------------------------
;; (2) _io_init                                              0     0      0       0
;; ---------------------------------------------------------------------------------
;; (2) _uart_init                                            0     0      0       0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 2
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (3) _hisr                                                 2     2      0       0
;;                                              0 COMMON     2     2      0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 3
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;   _sys_init
;;     _uart_init
;;     _io_init
;;     _tmr0_init
;;   _uart_putc
;;
;; _hisr (ROOT)
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            E      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;COMMON               E      5       6       1       42.9%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       2       2        0.0%
;;BITBANK0            30      0       0       3        0.0%
;;BANK0               30      8       A       4       20.8%
;;ABS                  0      0      10       5        0.0%
;;DATA                 0      0      12       6        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 52 in file "E:\Projects\PDN0907\test\lgt8p663a_ira\iocr_ira.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  ira_buf         5    0[BANK0 ] unsigned char [5]
;;  main_st         1    7[BANK0 ] volatile unsigned char 
;;  edg_flg         1    6[BANK0 ] volatile unsigned char 
;;  ira_bit         1    5[BANK0 ] volatile unsigned char 
;; Return value:  Size  Location     Type
;;                  2  792[COMMON] int 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 20/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         0       8
;;      Temps:          0       0
;;      Totals:         0       8
;;Total ram usage:        8 bytes
;; Hardware stack levels required when called:    3
;; This function calls:
;;		_sys_init
;;		_uart_putc
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"E:\Projects\PDN0907\test\lgt8p663a_ira\iocr_ira.c"
	line	52
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 5
; Regs used in _main: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	54
	
l2211:	
;iocr_ira.c: 53: u8 ira_buf[5];
;iocr_ira.c: 54: volatile u8 main_st = 0;
	clrf	(main@main_st)	;volatile
	line	55
;iocr_ira.c: 55: volatile u8 ira_bit = 0;
	clrf	(main@ira_bit)	;volatile
	line	58
	
l2213:	
;iocr_ira.c: 56: volatile u8 edg_flg;
;iocr_ira.c: 58: CWOK = 1;
	bsf	status, 5	;RP0=1, select bank1
	bsf	(1142/8)^080h,(1142)&7
	line	59
	
l2215:	
;iocr_ira.c: 59: _nop();
	nop
	line	60
	
l2217:	
;iocr_ira.c: 60: _nop();
	nop
	line	62
	
l2219:	
;iocr_ira.c: 62: sys_init();
	fcall	_sys_init
	line	64
	
l2221:	
;iocr_ira.c: 64: GIE = 0;
	bcf	(95/8),(95)&7
	line	65
	
l2223:	
;iocr_ira.c: 65: uart_putc(0x55);
	movlw	(055h)
	fcall	_uart_putc
	line	66
	
l2225:	
;iocr_ira.c: 66: uart_putc(0xaa);
	movlw	(0AAh)
	fcall	_uart_putc
	line	67
	
l2227:	
;iocr_ira.c: 67: GIE = 1;
	bsf	(95/8),(95)&7
	line	71
	
l2229:	
;iocr_ira.c: 70: {
;iocr_ira.c: 71: if(main_st == 6) {
	bcf	status, 5	;RP0=0, select bank0
	movf	(main@main_st),w	;volatile
	xorlw	06h
	skipz
	goto	u261
	goto	u260
u261:
	goto	l2239
u260:
	line	72
	
l2231:	
;iocr_ira.c: 72: GIE = 0;
	bcf	(95/8),(95)&7
	line	73
	
l2233:	
;iocr_ira.c: 73: uart_putc(ira_buf[0]);
	movf	(main@ira_buf),w
	fcall	_uart_putc
	line	74
;iocr_ira.c: 74: uart_putc(ira_buf[1]);
	bcf	status, 5	;RP0=0, select bank0
	movf	0+(main@ira_buf)+01h,w
	fcall	_uart_putc
	line	75
;iocr_ira.c: 75: uart_putc(ira_buf[2]);
	bcf	status, 5	;RP0=0, select bank0
	movf	0+(main@ira_buf)+02h,w
	fcall	_uart_putc
	line	76
;iocr_ira.c: 76: uart_putc(ira_buf[3]);
	bcf	status, 5	;RP0=0, select bank0
	movf	0+(main@ira_buf)+03h,w
	fcall	_uart_putc
	line	77
	
l2235:	
;iocr_ira.c: 77: GIE = 1;
	bsf	(95/8),(95)&7
	line	79
	
l2237:	
;iocr_ira.c: 79: main_st = 0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(main@main_st)	;volatile
	line	88
	
l2239:	
;iocr_ira.c: 80: }
;iocr_ira.c: 88: if(ird_flg == 0)
	movf	(_ird_flg),f
	skipz	;volatile
	goto	u271
	goto	u270
u271:
	goto	l2243
u270:
	goto	l2229
	line	91
	
l2243:	
;iocr_ira.c: 91: edg_flg = ird_flg & 1;
	movf	(_ird_flg),w
	movwf	(main@edg_flg)	;volatile
	
l2245:	
	movlw	(01h)
	andwf	(main@edg_flg),f	;volatile
	line	92
	
l2247:	
;iocr_ira.c: 92: ird_flg = 0;
	clrf	(_ird_flg)	;volatile
	line	94
;iocr_ira.c: 94: switch(main_st)
	goto	l2285
	line	97
	
l2249:	
;iocr_ira.c: 97: if(ird_prd > 0x9a && edg_flg == 1)
	movlw	(09Bh)
	subwf	(_ird_prd),w	;volatile
	skipc
	goto	u281
	goto	u280
u281:
	goto	l2229
u280:
	
l2251:	
	decf	(main@edg_flg),w	;volatile
	skipz
	goto	u291
	goto	u290
u291:
	goto	l2229
u290:
	line	99
	
l2253:	
;iocr_ira.c: 98: {
;iocr_ira.c: 99: main_st = 1;
	clrf	(main@main_st)	;volatile
	incf	(main@main_st),f	;volatile
	goto	l2229
	line	104
	
l2255:	
;iocr_ira.c: 104: if(ird_prd > 0x4a && edg_flg == 0)
	movlw	(04Bh)
	subwf	(_ird_prd),w	;volatile
	skipc
	goto	u301
	goto	u300
u301:
	goto	l2263
u300:
	
l2257:	
	movf	(main@edg_flg),f
	skipz	;volatile
	goto	u311
	goto	u310
u311:
	goto	l2263
u310:
	line	106
	
l2259:	
;iocr_ira.c: 105: {
;iocr_ira.c: 106: ira_buf[0] = 0;
	clrf	(main@ira_buf)
	line	107
	
l2261:	
;iocr_ira.c: 107: main_st = 2;
	movlw	(02h)
	movwf	(main@main_st)	;volatile
	line	108
;iocr_ira.c: 108: }
	goto	l2229
	line	111
	
l2263:	
;iocr_ira.c: 109: else
;iocr_ira.c: 110: {
;iocr_ira.c: 111: main_st = 0;
	clrf	(main@main_st)	;volatile
	goto	l2229
	line	116
	
l806:	
	line	118
	
l2265:	
;iocr_ira.c: 115: case 3:
;iocr_ira.c: 116: case 4:
;iocr_ira.c: 117: case 5:
;iocr_ira.c: 118: if(edg_flg == 1)
	decf	(main@edg_flg),w	;volatile
	skipz
	goto	u321
	goto	u320
u321:
	goto	l2269
u320:
	goto	l2229
	line	121
	
l2269:	
;iocr_ira.c: 121: if(ird_prd > 0x18)
	movlw	(019h)
	subwf	(_ird_prd),w	;volatile
	skipc
	goto	u331
	goto	u330
u331:
	goto	l2273
u330:
	line	122
	
l2271:	
;iocr_ira.c: 122: ira_buf[main_st - 2] |= 1;
	movf	(main@main_st),w
	addlw	0FEh
	addlw	main@ira_buf&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank0
	bsf	indf+(0/8),(0)&7
	line	123
	
l2273:	
;iocr_ira.c: 123: if(++ira_bit > 7)
	movlw	(08h)
	incf	(main@ira_bit),f	;volatile
	subwf	((main@ira_bit)),w	;volatile
	skipc
	goto	u341
	goto	u340
u341:
	goto	l2281
u340:
	line	125
	
l2275:	
;iocr_ira.c: 124: {
;iocr_ira.c: 125: ira_bit = 0;
	clrf	(main@ira_bit)	;volatile
	line	126
	
l2277:	
;iocr_ira.c: 126: ira_buf[main_st - 1] = 0;
	movf	(main@main_st),w
	addlw	0FFh
	addlw	main@ira_buf&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank0
	clrf	indf
	line	127
	
l2279:	
;iocr_ira.c: 127: main_st++;
	incf	(main@main_st),f	;volatile
	line	128
;iocr_ira.c: 128: break;
	goto	l2229
	line	130
	
l2281:	
;iocr_ira.c: 129: }
;iocr_ira.c: 130: ira_buf[main_st - 2] <<= 1;
	movf	(main@main_st),w
	addlw	0FEh
	addlw	main@ira_buf&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank0
	clrc
	rlf	indf,f
	line	131
;iocr_ira.c: 131: break;
	goto	l2229
	line	94
	
l2285:	
	movf	(main@main_st),w	;volatile
	; Switch size 1, requested type "space"
; Number of cases is 6, Range of values is 0 to 5
; switch strategies available:
; Name         Instructions Cycles
; direct_byte           12     6 (fixed)
; simple_byte           19    10 (average)
; jumptable            260     6 (fixed)
; rangetable            10     6 (fixed)
; spacedrange           18     9 (fixed)
; locatedrange           6     3 (fixed)
;	Chosen strategy is direct_byte

	movwf fsr
	movlw	6
	subwf	fsr,w
skipnc
goto l2229
movlw high(S2323)
movwf pclath
	movlw low(S2323)
	addwf fsr,w
	movwf pc
psect	swtext1,local,class=CONST,delta=2
global __pswtext1
__pswtext1:
S2323:
	ljmp	l2249
	ljmp	l2255
	ljmp	l806
	ljmp	l2265
	ljmp	l2265
	ljmp	l2265
psect	maintext

	global	start
	ljmp	start
	opt stack 0
psect	maintext
	line	135
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,90
	global	_uart_putc
psect	text159,local,class=CODE,delta=2
global __ptext159
__ptext159:

;; *************** function _uart_putc *****************
;; Defined at:
;;		line 21 in file "E:\Projects\PDN0907\test\lgt8p663a_ira\uart.c"
;; Parameters:    Size  Location     Type
;;  c               1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  c               1    3[COMMON] unsigned char 
;;  i               1    4[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/20
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         2       0
;;      Temps:          1       0
;;      Totals:         3       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text159
	file	"E:\Projects\PDN0907\test\lgt8p663a_ira\uart.c"
	line	21
	global	__size_of_uart_putc
	__size_of_uart_putc	equ	__end_of_uart_putc-_uart_putc
	
_uart_putc:	
	opt	stack 6
; Regs used in _uart_putc: [wreg+status,2+status,0]
;uart_putc@c stored from wreg
	line	25
	movwf	(uart_putc@c)
	
l2193:	
;uart.c: 22: u8 i;
;uart.c: 25: RA5 = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	(45/8),(45)&7
	line	26
	
l2195:	
;uart.c: 26: _delay((unsigned long)((39)*(32000000/4000000.0)));
	opt asmopt_off
movlw	103
movwf	(??_uart_putc+0)+0,f
u357:
decfsz	(??_uart_putc+0)+0,f
	goto	u357
	nop2	;nop
opt asmopt_on

	line	29
	
l2197:	
;uart.c: 29: for(i = 0; i < 8; i++) {
	clrf	(uart_putc@i)
	
l1596:	
	line	30
;uart.c: 30: RA5 = c & 1;
	btfsc	(uart_putc@c),0
	goto	u231
	goto	u230
	
u231:
	bcf	status, 5	;RP0=0, select bank0
	bsf	(45/8),(45)&7
	goto	u244
u230:
	bcf	status, 5	;RP0=0, select bank0
	bcf	(45/8),(45)&7
u244:
	line	31
;uart.c: 31: c = c >> 1;
	clrc
	rrf	(uart_putc@c),f
	line	32
	
l2203:	
;uart.c: 32: _delay((unsigned long)((39)*(32000000/4000000.0)));
	opt asmopt_off
movlw	103
movwf	(??_uart_putc+0)+0,f
u367:
decfsz	(??_uart_putc+0)+0,f
	goto	u367
	nop2	;nop
opt asmopt_on

	line	29
	
l2205:	
	incf	(uart_putc@i),f
	
l2207:	
	movlw	(08h)
	subwf	(uart_putc@i),w
	skipc
	goto	u251
	goto	u250
u251:
	goto	l1596
u250:
	
l1597:	
	line	36
;uart.c: 33: }
;uart.c: 36: RA5 = 1;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(45/8),(45)&7
	line	37
	
l2209:	
;uart.c: 37: _delay((unsigned long)((39)*(32000000/4000000.0)));
	opt asmopt_off
movlw	103
movwf	(??_uart_putc+0)+0,f
u377:
decfsz	(??_uart_putc+0)+0,f
	goto	u377
	nop2	;nop
opt asmopt_on

	line	38
;uart.c: 38: _delay((unsigned long)((39)*(32000000/4000000.0)));
	opt asmopt_off
movlw	103
movwf	(??_uart_putc+0)+0,f
u387:
decfsz	(??_uart_putc+0)+0,f
	goto	u387
	nop2	;nop
opt asmopt_on

	line	39
	
l1598:	
	return
	opt stack 0
GLOBAL	__end_of_uart_putc
	__end_of_uart_putc:
;; =============== function _uart_putc ends ============

	signat	_uart_putc,4216
	global	_sys_init
psect	text160,local,class=CODE,delta=2
global __ptext160
__ptext160:

;; *************** function _sys_init *****************
;; Defined at:
;;		line 138 in file "E:\Projects\PDN0907\test\lgt8p663a_ira\iocr_ira.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/20
;;		On exit  : 20/20
;;		Unchanged: FFFDF/0
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         0       0
;;      Temps:          0       0
;;      Totals:         0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		_uart_init
;;		_io_init
;;		_tmr0_init
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text160
	file	"E:\Projects\PDN0907\test\lgt8p663a_ira\iocr_ira.c"
	line	138
	global	__size_of_sys_init
	__size_of_sys_init	equ	__end_of_sys_init-_sys_init
	
_sys_init:	
	opt	stack 5
; Regs used in _sys_init: [wreg+status,2+status,0+pclath+cstack]
	line	141
	
l2185:	
;iocr_ira.c: 141: uart_init();
	fcall	_uart_init
	line	144
	
l2187:	
;iocr_ira.c: 144: io_init();
	fcall	_io_init
	line	147
	
l2189:	
;iocr_ira.c: 147: tmr0_init();
	fcall	_tmr0_init
	line	150
	
l2191:	
;iocr_ira.c: 150: GIE = 1;
	bsf	(95/8),(95)&7
	line	151
	
l816:	
	return
	opt stack 0
GLOBAL	__end_of_sys_init
	__end_of_sys_init:
;; =============== function _sys_init ends ============

	signat	_sys_init,88
	global	_tmr0_init
psect	text161,local,class=CODE,delta=2
global __ptext161
__ptext161:

;; *************** function _tmr0_init *****************
;; Defined at:
;;		line 172 in file "E:\Projects\PDN0907\test\lgt8p663a_ira\iocr_ira.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 20/20
;;		On exit  : 20/20
;;		Unchanged: FFFDF/0
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         0       0
;;      Temps:          0       0
;;      Totals:         0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_sys_init
;; This function uses a non-reentrant model
;;
psect	text161
	file	"E:\Projects\PDN0907\test\lgt8p663a_ira\iocr_ira.c"
	line	172
	global	__size_of_tmr0_init
	__size_of_tmr0_init	equ	__end_of_tmr0_init-_tmr0_init
	
_tmr0_init:	
	opt	stack 5
; Regs used in _tmr0_init: [wreg+status,2+status,0]
	line	177
	
l2179:	
;iocr_ira.c: 177: OPTION_REG &= 0xC0;
	movlw	(0C0h)
	andwf	(129)^080h,f	;volatile
	line	182
;iocr_ira.c: 182: T0CON &= 0xfc;
	movlw	(0FCh)
	andwf	(145)^080h,f	;volatile
	line	183
	
l2181:	
;iocr_ira.c: 183: PR0L = 200;
	movlw	(0C8h)
	movwf	(146)^080h	;volatile
	line	186
	
l2183:	
;iocr_ira.c: 186: T0IE = 1;
	bsf	(93/8),(93)&7
	line	187
	
l822:	
	return
	opt stack 0
GLOBAL	__end_of_tmr0_init
	__end_of_tmr0_init:
;; =============== function _tmr0_init ends ============

	signat	_tmr0_init,88
	global	_io_init
psect	text162,local,class=CODE,delta=2
global __ptext162
__ptext162:

;; *************** function _io_init *****************
;; Defined at:
;;		line 154 in file "E:\Projects\PDN0907\test\lgt8p663a_ira\iocr_ira.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 20/20
;;		On exit  : 20/20
;;		Unchanged: FFFDF/0
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         0       0
;;      Temps:          0       0
;;      Totals:         0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_sys_init
;; This function uses a non-reentrant model
;;
psect	text162
	file	"E:\Projects\PDN0907\test\lgt8p663a_ira\iocr_ira.c"
	line	154
	global	__size_of_io_init
	__size_of_io_init	equ	__end_of_io_init-_io_init
	
_io_init:	
	opt	stack 5
; Regs used in _io_init: [wreg+status,2]
	line	156
	
l2169:	
;iocr_ira.c: 156: ANSEL = 0;
	clrf	(159)^080h	;volatile
	line	159
	
l2171:	
;iocr_ira.c: 159: WPUA = 0b00000100;
	movlw	(04h)
	movwf	(149)^080h	;volatile
	line	162
	
l2173:	
;iocr_ira.c: 162: nGPPU = 0;
	bcf	(1039/8)^080h,(1039)&7
	line	165
	
l2175:	
;iocr_ira.c: 165: IOCA = 0b00000100;
	movlw	(04h)
	movwf	(150)^080h	;volatile
	line	168
	
l2177:	
;iocr_ira.c: 168: GPIE = 1;
	bsf	(91/8),(91)&7
	line	169
	
l819:	
	return
	opt stack 0
GLOBAL	__end_of_io_init
	__end_of_io_init:
;; =============== function _io_init ends ============

	signat	_io_init,88
	global	_uart_init
psect	text163,local,class=CODE,delta=2
global __ptext163
__ptext163:

;; *************** function _uart_init *****************
;; Defined at:
;;		line 14 in file "E:\Projects\PDN0907\test\lgt8p663a_ira\uart.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/20
;;		On exit  : 20/20
;;		Unchanged: FFFDF/0
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         0       0
;;      Temps:          0       0
;;      Totals:         0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_sys_init
;; This function uses a non-reentrant model
;;
psect	text163
	file	"E:\Projects\PDN0907\test\lgt8p663a_ira\uart.c"
	line	14
	global	__size_of_uart_init
	__size_of_uart_init	equ	__end_of_uart_init-_uart_init
	
_uart_init:	
	opt	stack 5
; Regs used in _uart_init: []
	line	16
	
l2167:	
;uart.c: 16: RA5 = 1;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(45/8),(45)&7
	line	17
;uart.c: 17: TRISA5 = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	(1069/8)^080h,(1069)&7
	line	18
	
l1593:	
	return
	opt stack 0
GLOBAL	__end_of_uart_init
	__end_of_uart_init:
;; =============== function _uart_init ends ============

	signat	_uart_init,88
	global	_hisr
psect	text164,local,class=CODE,delta=2
global __ptext164
__ptext164:

;; *************** function _hisr *****************
;; Defined at:
;;		line 32 in file "E:\Projects\PDN0907\test\lgt8p663a_ira\iocr_ira.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: FFFDF/0
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         0       0
;;      Temps:          2       0
;;      Totals:         2       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text164
	file	"E:\Projects\PDN0907\test\lgt8p663a_ira\iocr_ira.c"
	line	32
	global	__size_of_hisr
	__size_of_hisr	equ	__end_of_hisr-_hisr
	
_hisr:	
	opt	stack 5
; Regs used in _hisr: [wreg+status,2+status,0]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_hisr+0)
	movf	pclath,w
	movwf	(??_hisr+1)
	ljmp	_hisr
psect	text164
	line	34
	
i1l2147:	
;iocr_ira.c: 34: if(T0IE && T0IF)
	btfss	(93/8),(93)&7
	goto	u18_21
	goto	u18_20
u18_21:
	goto	i1l2157
u18_20:
	
i1l2149:	
	btfss	(90/8),(90)&7
	goto	u19_21
	goto	u19_20
u19_21:
	goto	i1l2157
u19_20:
	line	36
	
i1l2151:	
;iocr_ira.c: 35: {
;iocr_ira.c: 36: if(ird_cnt < 0xff)
	movf	(_ird_cnt),w	;volatile
	xorlw	0FFh
	skipnz
	goto	u20_21
	goto	u20_20
u20_21:
	goto	i1l2155
u20_20:
	line	37
	
i1l2153:	
;iocr_ira.c: 37: ird_cnt++;
	incf	(_ird_cnt),f	;volatile
	line	38
	
i1l2155:	
;iocr_ira.c: 38: T0IF = 0;
	bcf	(90/8),(90)&7
	line	42
	
i1l2157:	
;iocr_ira.c: 39: }
;iocr_ira.c: 42: if(GPIE && GPIF)
	btfss	(91/8),(91)&7
	goto	u21_21
	goto	u21_20
u21_21:
	goto	i1l790
u21_20:
	
i1l2159:	
	btfss	(88/8),(88)&7
	goto	u22_21
	goto	u22_20
u22_21:
	goto	i1l790
u22_20:
	line	44
	
i1l2161:	
;iocr_ira.c: 43: {
;iocr_ira.c: 44: ird_prd = ird_cnt;
	movf	(_ird_cnt),w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	(_ird_prd)	;volatile
	line	45
	
i1l2163:	
;iocr_ira.c: 45: ird_cnt = 0;
	clrf	(_ird_cnt)	;volatile
	line	46
;iocr_ira.c: 46: ird_flg = (0x80 | RA2);
	movlw	0
	btfsc	(42/8),(42)&7
	movlw	1
	iorlw	080h
	movwf	(_ird_flg)	;volatile
	line	47
	
i1l2165:	
;iocr_ira.c: 47: GPIF = 0;
	bcf	(88/8),(88)&7
	line	49
	
i1l790:	
	movf	(??_hisr+1),w
	movwf	pclath
	swapf	(??_hisr+0)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_hisr
	__end_of_hisr:
;; =============== function _hisr ends ============

	signat	_hisr,88
psect	text165,local,class=CODE,delta=2
global __ptext165
__ptext165:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
