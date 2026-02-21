/*
  							  	****************
*******************************  C SOURCE FILE  **********************************
** 								**************** 						        **
** 																		        **
** project  : LGT8F88ABSPPrj											    	**
** filename : mprintf.c		  													**
** version  : 1.0 													   			**
** date     : April 01, 2013 										   			**
** 			  		 	 												   		**
**********************************************************************************
** 																		   		**
** Copyright (c) 2013, 	Logic Green Technologies								**
** All rights reserved.                                                    		**
**                                                                         		**
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: April 01, 2013
Revised by 	: LGT Software Group
Description : Original version.
*/

#define _PRINTF_C_SRC_

/**********************************************************************************
**  				            		MODULES USED		  		     		***													  	
**********************************************************************************/ 
#include "common.h"
#include "mprintf.h"
#include "stdarg.h"
#include "DrvUSART0.h"
#include "pgmspace.h"

/**********************************************************************************
**  				     			EXPORTED VARIABLES		            		***													  	
**********************************************************************************/
u8 scanbuf[10];
u8 command_line[COMMAND_LINE_LEN];

/**********************************************************************************
**					         PROTOTYPE OF LOCAL FUNCTIONS      					***													  	
**********************************************************************************/
static void SerialWriteByte(u8 c);
static void SerialWriteBuffer(char *str);
static u8   SerialReadByte(void);
static void itoa(u32 val , u8 *buf, u8 radix);

/**********************************************************************************
**					             	EXPORTED FUNCTIONS  		  	          	***													  	
**********************************************************************************/

/**
 * @fn void mprintf(char *fmt, ...)
 * 
 */
void mprintf(char *fmt, ...)
{
    	u8 *s;
    	u32 d;
    	u8 buf[16];

    	va_list ap;             		// pointer that point to parameter list
    	va_start(ap, fmt);  			// initialize ap

    	while(*fmt)
    	{
        	if(*fmt != '%')
        	{
        		if((*fmt == '\r') || (*fmt == '\n'))
					SerialWriteBuffer("\r\n");
				else
           			SerialWriteByte(*fmt); 
        	}
        	else
        	{
      			switch(*++fmt)
            	{

                case 'c':
                    s = va_arg(ap, u8 *); 
                    SerialWriteByte(*s);
                    break;

                case 's':
           			s = va_arg(ap, u8 *);
                    for(; *s; s++)
                    	SerialWriteByte(*s);
              		break;

                case 'd':
            		d = va_arg(ap, int);
                  	itoa(d, buf, 10);       //Converts an int to a character string.
                   	for(s = buf; *s; s++)
                   		SerialWriteByte(*s);
					break;
					
      			case 'x':
                  	d = va_arg(ap, int);
                 	itoa(d, buf, 16);       //Converts an int to a character string.
                 	for(s = buf; *s; s++)
                   		SerialWriteByte(*s);	
					break;
           		default:
                	SerialWriteByte(*fmt);
        		}
        	}
            fmt++;
    	}
	//SerialWriteBuffer("\n");
    	va_end(ap);
}

/**
 * @fn void mprintf_flash(const prog_char *str)
 *	display data from FLASH
 */
void mprintf_flash(const prog_char *str)
{
	u8 c;

	c = pgm_read_byte(str);
	str++;

	while(c != '\0')
	{
		if((c == '\r') || (c == '\n'))
			SerialWriteBuffer("\r\n");
		else
			SerialWriteByte(c);
		c = pgm_read_byte(str);
		str++;
	}
}

/**
 * @fn void mscanf(char *fmt, ...)
 *	
 */
void mscanf(char *fmt, ...)
{
	u8 readchar;
	u8 i = 0, argsread=0;        

	do
	{
		argsread = SerialReadByte();

		if(argsread != -1)		
		{
			readchar = (char)argsread;	        
			if ((readchar == 0x16) || (readchar == 0x8)) 
			{	            
				if (i > 0)  
				{
					i--;
					SerialWriteByte(readchar);	
				}	        
			} 
			else 
			{	            
				scanbuf[i++] = readchar;	            
				SerialWriteByte(readchar);						        
				if ((readchar == '\r') || (readchar == '\n')) 		
				{
					SerialWriteByte('\r');	
					SerialWriteByte('\n');
				}
			}		
		}		
		else
			break;		    
	} 
	while ((readchar != '\n') && (readchar != '\r') && (i < SCANBUF_LEN));    
	scanbuf[i] = '\0';    
}

/**
 * @fn void mscanf_command(void)
 *	receive string untile \n , \r 
 */
void mscanf_command(void)
 {
 	u8 readchar;
	u8 i = 0, argsread=0;        

	do
	{
		argsread = SerialReadByte();

		if(argsread != -1)		
		{
			readchar = (char)argsread;	        
			if ((readchar == 0x16) || (readchar == 0x8)) 
			{	            
				if (i > 0)  
				{
					i--;
					SerialWriteByte(readchar);	
				}	        
			} 
			else 
			{	  
								        
				if ((readchar == '\r') || (readchar == '\n')) 		
				{
					SerialWriteByte('\r');	
					SerialWriteByte('\n');
				}
				else
				{
					command_line[i++] = readchar;	            
					SerialWriteByte(readchar);	
				}
			}		
		}		
		else
			break;		    
	} 
	while ((readchar != '\n') && (readchar != '\r') && (i < COMMAND_LINE_LEN));    
	command_line[i] = '\0';    

}

/**********************************************************************************
**					           		LOCAL FUNCTIONS   		                	***													  	
**********************************************************************************/

/**
 * @fn static void SerialWriteByte(u8 c)
 *	
 */
static void SerialWriteByte(u8 c)
{
    	DrvUSART_SendChar(c, 0);
}


/**
 * @fn static void SerialWriteBuffer(char *str)
 *	
 */
static void SerialWriteBuffer(char *str)
{
	while(*str)
        	SerialWriteByte(*(str++));
}

/**
 * @fn static u8 SerialReadByte(void)
 *	
 */
static u8 SerialReadByte(void)
{
	u8 revChar;

	DrvUSART_RecvChar(&revChar, 0);
	return(revChar);
}

/**
 * @fn static void itoa(u32 val , u8 *buf, u8 radix)
 *	integer to ascii
 */
static void itoa(u32 val , u8 *buf, u8 radix)
{
	u8 *p;							// pointer to traverse string         
	u8 *firstdig;					// pointer to first digit         
	u8 temp;						// temp char         
	u16  digval;					// value of digit        
     
	p = buf;       
	firstdig = p;      				// save pointer to first digit 
     
	do 
	{            
		digval = (val % radix);				
    	val /= radix;	            

		// convert to ascii and store
    	if (digval > 9)                
        	*p++ = (char) (digval - 10 + 'A');  	// a letter          
     	else                
			*p++ = (char) (digval + '0');      		// a digit        
	} 
	while (val > 0);        

	// We now have the digit of the number in the buffer, but in reverse order.  Thus we reverse them now.         

	*p-- = '\0';            	// terminate string; p points to last digit        
	do
	{            
        	temp = *p;            
        	*p = *firstdig;            
        	*firstdig = temp;   // swap *p and *firstdig          
        	--p;           
        	++firstdig;         	// advance to next two digits       
       }
	while (firstdig < p); 	// repeat until halfway
	
}

/**********************************************************************************
***					                  EOF		        				        ***													  	
**********************************************************************************/