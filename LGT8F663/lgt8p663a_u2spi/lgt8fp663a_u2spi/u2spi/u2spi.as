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
	FNCALL	_main,_spi_transfer
	FNCALL	_main,_uart_putc
	FNCALL	_sys_init,_usi_init
	FNCALL	_sys_init,_io_init
	FNCALL	_sys_init,_tmr0_init
	FNROOT	_main
	FNCALL	intlevel1,_hisr
	global	intlevel1
	FNROOT	intlevel1
	global	_t0cnt
	global	_GIE
psect	text92,local,class=CODE,delta=2
global __ptext92
__ptext92:
_GIE	set	95
	global	_RA0
_RA0	set	40
	global	_RA1
_RA1	set	41
	global	_RA2
_RA2	set	42
	global	_RA3
_RA3	set	43
	global	_RA4
_RA4	set	44
	global	_RA5
_RA5	set	45
	global	_T0IE
_T0IE	set	93
	global	_T0IF
_T0IF	set	90
	global	_ANSEL
_ANSEL	set	159
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
	global	_TRISA0
_TRISA0	set	1064
	global	_TRISA2
_TRISA2	set	1066
	global	_TRISA3
_TRISA3	set	1067
	global	_TRISA4
_TRISA4	set	1068
	global	_TRISA5
_TRISA5	set	1069
	global	_nGPPU
_nGPPU	set	1039
	file	"u2spi.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect	bssCOMMON,class=COMMON,space=1
global __pbssCOMMON
__pbssCOMMON:
_t0cnt:
       ds      1

; Clear objects allocated to COMMON
psect cinit,class=CODE,delta=2
	clrf	((__pbssCOMMON)+0)&07Fh
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
	global	?_usi_init
?_usi_init:	; 0 bytes @ 0x0
	global	?_io_init
?_io_init:	; 0 bytes @ 0x0
	global	?_tmr0_init
?_tmr0_init:	; 0 bytes @ 0x0
	global	?_hisr
?_hisr:	; 0 bytes @ 0x0
	global	??_hisr
??_hisr:	; 0 bytes @ 0x0
	global	?_spi_transfer
?_spi_transfer:	; 1 bytes @ 0x0
	global	?_main
?_main:	; 2 bytes @ 0x0
	ds	2
	global	??_sys_init
??_sys_init:	; 0 bytes @ 0x2
	global	??_spi_transfer
??_spi_transfer:	; 0 bytes @ 0x2
	global	??_uart_putc
??_uart_putc:	; 0 bytes @ 0x2
	global	??_usi_init
??_usi_init:	; 0 bytes @ 0x2
	global	??_io_init
??_io_init:	; 0 bytes @ 0x2
	global	??_tmr0_init
??_tmr0_init:	; 0 bytes @ 0x2
	global	spi_transfer@data
spi_transfer@data:	; 1 bytes @ 0x2
	ds	1
	global	uart_putc@c
uart_putc@c:	; 1 bytes @ 0x3
	global	spi_transfer@rev
spi_transfer@rev:	; 1 bytes @ 0x3
	ds	1
	global	uart_putc@i
uart_putc@i:	; 1 bytes @ 0x4
	global	spi_transfer@i
spi_transfer@i:	; 1 bytes @ 0x4
	ds	1
	global	??_main
??_main:	; 0 bytes @ 0x5
	ds	3
	global	main@tmp
main@tmp:	; 1 bytes @ 0x8
	ds	1
;;Data sizes: Strings 0, constant 0, data 0, bss 1, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      9      10
;; BANK0           48      0       0

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   _main->_spi_transfer
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
;;Main: autosize = 0, tempsize = 3, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 4     4      0     120
;;                                              5 COMMON     4     4      0
;;                           _sys_init
;;                       _spi_transfer
;;                          _uart_putc
;; ---------------------------------------------------------------------------------
;; (1) _uart_putc                                            3     3      0      45
;;                                              2 COMMON     3     3      0
;; ---------------------------------------------------------------------------------
;; (1) _sys_init                                             0     0      0       0
;;                           _usi_init
;;                            _io_init
;;                          _tmr0_init
;; ---------------------------------------------------------------------------------
;; (2) _tmr0_init                                            0     0      0       0
;; ---------------------------------------------------------------------------------
;; (2) _io_init                                              0     0      0       0
;; ---------------------------------------------------------------------------------
;; (2) _usi_init                                             0     0      0       0
;; ---------------------------------------------------------------------------------
;; (1) _spi_transfer                                         3     3      0      60
;;                                              2 COMMON     3     3      0
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
;;     _usi_init
;;     _io_init
;;     _tmr0_init
;;   _spi_transfer
;;   _uart_putc
;;
;; _hisr (ROOT)
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            E      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;COMMON               E      9       A       1       71.4%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       2       2        0.0%
;;BITBANK0            30      0       0       3        0.0%
;;BANK0               30      0       0       4        0.0%
;;ABS                  0      0       A       5        0.0%
;;DATA                 0      0       C       6        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 44 in file "E:\Projects\PDN0907\test\lgt8fp663a_u2spi\u2spi.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  tmp             1    8[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  2  791[COMMON] int 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         1       0
;;      Temps:          3       0
;;      Totals:         4       0
;;Total ram usage:        4 bytes
;; Hardware stack levels required when called:    3
;; This function calls:
;;		_sys_init
;;		_spi_transfer
;;		_uart_putc
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"E:\Projects\PDN0907\test\lgt8fp663a_u2spi\u2spi.c"
	line	44
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 5
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	47
	
l2039:	
;u2spi.c: 45: u8 tmp;
;u2spi.c: 47: CWOK = 1;
	bsf	status, 5	;RP0=1, select bank1
	bsf	(1142/8)^080h,(1142)&7
	line	48
;u2spi.c: 48: _nop();
	nop
	line	49
;u2spi.c: 49: _nop();
	nop
	line	51
	
l2041:	
;u2spi.c: 51: sys_init();
	fcall	_sys_init
	line	53
;u2spi.c: 53: while(1)
	
l792:	
	line	55
;u2spi.c: 54: {
;u2spi.c: 55: spi_transfer(0x5a);
	movlw	(05Ah)
	fcall	_spi_transfer
	line	57
;u2spi.c: 57: uart_putc(0x55);
	movlw	(055h)
	fcall	_uart_putc
	line	58
;u2spi.c: 58: uart_putc(0xaa);
	movlw	(0AAh)
	fcall	_uart_putc
	line	60
;u2spi.c: 60: tmp = spi_transfer(0xff);
	movlw	(0FFh)
	fcall	_spi_transfer
	movwf	(main@tmp)
	line	61
;u2spi.c: 61: uart_putc(tmp);
	movf	(main@tmp),w
	fcall	_uart_putc
	line	63
	
l2043:	
;u2spi.c: 63: _delay((unsigned long)((100)*(32000000/4000.0)));
	opt asmopt_off
movlw  5
movwf	((??_main+0)+0+2),f
movlw	15
movwf	((??_main+0)+0+1),f
	movlw	244
movwf	((??_main+0)+0),f
u107:
	decfsz	((??_main+0)+0),f
	goto	u107
	decfsz	((??_main+0)+0+1),f
	goto	u107
	decfsz	((??_main+0)+0+2),f
	goto	u107
opt asmopt_on

	goto	l792
	global	start
	ljmp	start
	opt stack 0
psect	maintext
	line	65
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,90
	global	_uart_putc
psect	text93,local,class=CODE,delta=2
global __ptext93
__ptext93:

;; *************** function _uart_putc *****************
;; Defined at:
;;		line 30 in file "E:\Projects\PDN0907\test\lgt8fp663a_u2spi\usi.c"
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
;;		On entry : 0/0
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
psect	text93
	file	"E:\Projects\PDN0907\test\lgt8fp663a_u2spi\usi.c"
	line	30
	global	__size_of_uart_putc
	__size_of_uart_putc	equ	__end_of_uart_putc-_uart_putc
	
_uart_putc:	
	opt	stack 6
; Regs used in _uart_putc: [wreg+status,2+status,0]
;uart_putc@c stored from wreg
	line	34
	movwf	(uart_putc@c)
	
l2021:	
;usi.c: 31: u8 i;
;usi.c: 34: RA5 = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	(45/8),(45)&7
	line	35
	
l2023:	
;usi.c: 35: _delay((unsigned long)((39)*(32000000/4000000.0)));
	opt asmopt_off
movlw	103
movwf	(??_uart_putc+0)+0,f
u117:
decfsz	(??_uart_putc+0)+0,f
	goto	u117
	nop2	;nop
opt asmopt_on

	line	38
	
l2025:	
;usi.c: 38: for(i = 0; i < 8; i++) {
	clrf	(uart_putc@i)
	
l1578:	
	line	39
;usi.c: 39: RA5 = c & 1;
	btfsc	(uart_putc@c),0
	goto	u71
	goto	u70
	
u71:
	bcf	status, 5	;RP0=0, select bank0
	bsf	(45/8),(45)&7
	goto	u84
u70:
	bcf	status, 5	;RP0=0, select bank0
	bcf	(45/8),(45)&7
u84:
	line	40
;usi.c: 40: c = c >> 1;
	clrc
	rrf	(uart_putc@c),f
	line	41
	
l2031:	
;usi.c: 41: _delay((unsigned long)((39)*(32000000/4000000.0)));
	opt asmopt_off
movlw	103
movwf	(??_uart_putc+0)+0,f
u127:
decfsz	(??_uart_putc+0)+0,f
	goto	u127
	nop2	;nop
opt asmopt_on

	line	38
	
l2033:	
	incf	(uart_putc@i),f
	
l2035:	
	movlw	(08h)
	subwf	(uart_putc@i),w
	skipc
	goto	u91
	goto	u90
u91:
	goto	l1578
u90:
	
l1579:	
	line	45
;usi.c: 42: }
;usi.c: 45: RA5 = 1;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(45/8),(45)&7
	line	46
	
l2037:	
;usi.c: 46: _delay((unsigned long)((39)*(32000000/4000000.0)));
	opt asmopt_off
movlw	103
movwf	(??_uart_putc+0)+0,f
u137:
decfsz	(??_uart_putc+0)+0,f
	goto	u137
	nop2	;nop
opt asmopt_on

	line	47
;usi.c: 47: _delay((unsigned long)((39)*(32000000/4000000.0)));
	opt asmopt_off
movlw	103
movwf	(??_uart_putc+0)+0,f
u147:
decfsz	(??_uart_putc+0)+0,f
	goto	u147
	nop2	;nop
opt asmopt_on

	line	48
	
l1580:	
	return
	opt stack 0
GLOBAL	__end_of_uart_putc
	__end_of_uart_putc:
;; =============== function _uart_putc ends ============

	signat	_uart_putc,4216
	global	_sys_init
psect	text94,local,class=CODE,delta=2
global __ptext94
__ptext94:

;; *************** function _sys_init *****************
;; Defined at:
;;		line 68 in file "E:\Projects\PDN0907\test\lgt8fp663a_u2spi\u2spi.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
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
;;		_usi_init
;;		_io_init
;;		_tmr0_init
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text94
	file	"E:\Projects\PDN0907\test\lgt8fp663a_u2spi\u2spi.c"
	line	68
	global	__size_of_sys_init
	__size_of_sys_init	equ	__end_of_sys_init-_sys_init
	
_sys_init:	
	opt	stack 5
; Regs used in _sys_init: [wreg+status,2+status,0+pclath+cstack]
	line	71
	
l2013:	
;u2spi.c: 71: usi_init();
	fcall	_usi_init
	line	74
	
l2015:	
;u2spi.c: 74: io_init();
	fcall	_io_init
	line	77
	
l2017:	
;u2spi.c: 77: tmr0_init();
	fcall	_tmr0_init
	line	80
	
l2019:	
;u2spi.c: 80: GIE = 1;
	bsf	(95/8),(95)&7
	line	81
	
l798:	
	return
	opt stack 0
GLOBAL	__end_of_sys_init
	__end_of_sys_init:
;; =============== function _sys_init ends ============

	signat	_sys_init,88
	global	_tmr0_init
psect	text95,local,class=CODE,delta=2
global __ptext95
__ptext95:

;; *************** function _tmr0_init *****************
;; Defined at:
;;		line 102 in file "E:\Projects\PDN0907\test\lgt8fp663a_u2spi\u2spi.c"
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
psect	text95
	file	"E:\Projects\PDN0907\test\lgt8fp663a_u2spi\u2spi.c"
	line	102
	global	__size_of_tmr0_init
	__size_of_tmr0_init	equ	__end_of_tmr0_init-_tmr0_init
	
_tmr0_init:	
	opt	stack 5
; Regs used in _tmr0_init: [wreg+status,2+status,0]
	line	107
	
l2005:	
;u2spi.c: 107: OPTION_REG |= 0x7;
	movlw	(07h)
	iorwf	(129)^080h,f	;volatile
	line	113
	
l2007:	
;u2spi.c: 113: T0CON = (T0CON & 0xfc) | 0x1;
	movf	(145)^080h,w
	andlw	0FCh
	iorlw	01h
	movwf	(145)^080h	;volatile
	line	114
	
l2009:	
;u2spi.c: 114: PR0L = 0xD4;
	movlw	(0D4h)
	movwf	(146)^080h	;volatile
	line	117
	
l2011:	
;u2spi.c: 117: T0IE = 1;
	bsf	(93/8),(93)&7
	line	118
	
l804:	
	return
	opt stack 0
GLOBAL	__end_of_tmr0_init
	__end_of_tmr0_init:
;; =============== function _tmr0_init ends ============

	signat	_tmr0_init,88
	global	_io_init
psect	text96,local,class=CODE,delta=2
global __ptext96
__ptext96:

;; *************** function _io_init *****************
;; Defined at:
;;		line 84 in file "E:\Projects\PDN0907\test\lgt8fp663a_u2spi\u2spi.c"
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
psect	text96
	file	"E:\Projects\PDN0907\test\lgt8fp663a_u2spi\u2spi.c"
	line	84
	global	__size_of_io_init
	__size_of_io_init	equ	__end_of_io_init-_io_init
	
_io_init:	
	opt	stack 5
; Regs used in _io_init: [wreg+status,2]
	line	86
	
l1997:	
;u2spi.c: 86: ANSEL = 0;
	clrf	(159)^080h	;volatile
	line	89
	
l1999:	
;u2spi.c: 89: WPUA = 0b00001000;
	movlw	(08h)
	movwf	(149)^080h	;volatile
	line	92
	
l2001:	
;u2spi.c: 92: nGPPU = 0;
	bcf	(1039/8)^080h,(1039)&7
	line	95
	
l2003:	
;u2spi.c: 95: TRISA3 = 0;
	bcf	(1067/8)^080h,(1067)&7
	line	99
	
l801:	
	return
	opt stack 0
GLOBAL	__end_of_io_init
	__end_of_io_init:
;; =============== function _io_init ends ============

	signat	_io_init,88
	global	_usi_init
psect	text97,local,class=CODE,delta=2
global __ptext97
__ptext97:

;; *************** function _usi_init *****************
;; Defined at:
;;		line 14 in file "E:\Projects\PDN0907\test\lgt8fp663a_u2spi\usi.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/0
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
psect	text97
	file	"E:\Projects\PDN0907\test\lgt8fp663a_u2spi\usi.c"
	line	14
	global	__size_of_usi_init
	__size_of_usi_init	equ	__end_of_usi_init-_usi_init
	
_usi_init:	
	opt	stack 5
; Regs used in _usi_init: []
	line	16
	
l1995:	
;usi.c: 16: RA5 = 1;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(45/8),(45)&7
	line	17
;usi.c: 17: TRISA5 = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	(1069/8)^080h,(1069)&7
	line	20
;usi.c: 20: RA4 = 1;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(44/8),(44)&7
	line	21
;usi.c: 21: RA0 = 0;
	bcf	(40/8),(40)&7
	line	22
;usi.c: 22: RA2 = 0;
	bcf	(42/8),(42)&7
	line	24
;usi.c: 24: TRISA4 = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	(1068/8)^080h,(1068)&7
	line	25
;usi.c: 25: TRISA2 = 0;
	bcf	(1066/8)^080h,(1066)&7
	line	26
;usi.c: 26: TRISA0 = 0;
	bcf	(1064/8)^080h,(1064)&7
	line	27
	
l1575:	
	return
	opt stack 0
GLOBAL	__end_of_usi_init
	__end_of_usi_init:
;; =============== function _usi_init ends ============

	signat	_usi_init,88
	global	_spi_transfer
psect	text98,local,class=CODE,delta=2
global __ptext98
__ptext98:

;; *************** function _spi_transfer *****************
;; Defined at:
;;		line 59 in file "E:\Projects\PDN0907\test\lgt8fp663a_u2spi\usi.c"
;; Parameters:    Size  Location     Type
;;  data            1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  data            1    2[COMMON] unsigned char 
;;  i               1    4[COMMON] unsigned char 
;;  rev             1    3[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/20
;;		On exit  : 20/0
;;		Unchanged: FFFDF/0
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         3       0
;;      Temps:          0       0
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
psect	text98
	file	"E:\Projects\PDN0907\test\lgt8fp663a_u2spi\usi.c"
	line	59
	global	__size_of_spi_transfer
	__size_of_spi_transfer	equ	__end_of_spi_transfer-_spi_transfer
	
_spi_transfer:	
	opt	stack 6
; Regs used in _spi_transfer: [wreg+status,2+status,0]
;spi_transfer@data stored from wreg
	line	62
	movwf	(spi_transfer@data)
	
l1975:	
;usi.c: 60: u8 i, rev;
;usi.c: 62: RA2 = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	(42/8),(42)&7
	line	63
	
l1977:	
;usi.c: 63: rev = 0;
	clrf	(spi_transfer@rev)
	line	65
;usi.c: 65: for(i = 0; i < 8; i++) {
	clrf	(spi_transfer@i)
	
l1589:	
	line	66
;usi.c: 66: if(data & 0x80) RA0 = 1;
	btfss	(spi_transfer@data),(7)&7
	goto	u41
	goto	u40
u41:
	goto	l1591
u40:
	
l1983:	
	bsf	(40/8),(40)&7
	goto	l1592
	line	67
	
l1591:	
;usi.c: 67: else RA0 = 0;
	bcf	(40/8),(40)&7
	
l1592:	
	line	68
;usi.c: 68: rev <<= 1;
	clrc
	rlf	(spi_transfer@rev),f
	line	70
;usi.c: 70: RA2 = 1;
	bsf	(42/8),(42)&7
	line	72
;usi.c: 72: if(RA1) rev |= 1;
	btfss	(41/8),(41)&7
	goto	u51
	goto	u50
u51:
	goto	l1593
u50:
	
l1985:	
	bsf	(spi_transfer@rev)+(0/8),(0)&7
	
l1593:	
	line	73
;usi.c: 73: data <<= 1;
	clrc
	rlf	(spi_transfer@data),f
	line	75
;usi.c: 75: RA2 = 0;
	bcf	(42/8),(42)&7
	line	65
	
l1987:	
	incf	(spi_transfer@i),f
	
l1989:	
	movlw	(08h)
	subwf	(spi_transfer@i),w
	skipc
	goto	u61
	goto	u60
u61:
	goto	l1589
u60:
	line	78
	
l1991:	
;usi.c: 76: }
;usi.c: 78: return rev;
	movf	(spi_transfer@rev),w
	line	79
	
l1594:	
	return
	opt stack 0
GLOBAL	__end_of_spi_transfer
	__end_of_spi_transfer:
;; =============== function _spi_transfer ends ============

	signat	_spi_transfer,4217
	global	_hisr
psect	text99,local,class=CODE,delta=2
global __ptext99
__ptext99:

;; *************** function _hisr *****************
;; Defined at:
;;		line 31 in file "E:\Projects\PDN0907\test\lgt8fp663a_u2spi\u2spi.c"
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
psect	text99
	file	"E:\Projects\PDN0907\test\lgt8fp663a_u2spi\u2spi.c"
	line	31
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
psect	text99
	line	33
	
i1l1963:	
;u2spi.c: 33: if(T0IE && T0IF)
	btfss	(93/8),(93)&7
	goto	u1_21
	goto	u1_20
u1_21:
	goto	i1l789
u1_20:
	
i1l1965:	
	btfss	(90/8),(90)&7
	goto	u2_21
	goto	u2_20
u2_21:
	goto	i1l789
u2_20:
	line	35
	
i1l1967:	
;u2spi.c: 34: {
;u2spi.c: 35: T0IF = 0;
	bcf	(90/8),(90)&7
	line	36
	
i1l1969:	
;u2spi.c: 36: if(++t0cnt == 20) {
	incf	(_t0cnt),f
	movf	((_t0cnt)),w
	xorlw	014h
	skipz
	goto	u3_21
	goto	u3_20
u3_21:
	goto	i1l789
u3_20:
	line	37
	
i1l1971:	
;u2spi.c: 37: RA3 = ~RA3;
	movlw	1<<((43)&7)
	bcf	status, 5	;RP0=0, select bank0
	xorwf	((43)/8),f
	line	38
	
i1l1973:	
;u2spi.c: 38: t0cnt = 0;
	clrf	(_t0cnt)
	line	41
	
i1l789:	
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
psect	text100,local,class=CODE,delta=2
global __ptext100
__ptext100:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
