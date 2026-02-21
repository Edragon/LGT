
#if __AVR_MEGA__
  #define XJMP jmp
  #define XCALL call
#else
  #define XJMP rjmp
  #define XCALL rcall
#endif

.section .vectors,"ax",@progbits
	.weak __vector_26
	XJMP  __vector_26
	.weak __vector_27
	XJMP  __vector_27
	.weak __vector_28
	XJMP  __vector_28
	.weak __vector_29
	XJMP  __vector_29
	.weak __vector_30
	XJMP  __vector_30
	.weak __vector_31
	XJMP  __vector_31
 
