**************   Larduino Support Package Installation   *****************

Step 1: Unzip the file, and move the two Folders (libraries and hardware) to:
MacOSX£º 			/Users/user/Documents/Arduino
Windows: 			C:\Users\<USERNAME>\Documents\Arduino
Linux/Ubuntu: 		/home/<USERNAME>/sketchbook
PS: Before do this, please make sure your Arduino IDE is closed.

Step 2: Connect Larduino board to your computer with a USB cable, and install the driver of CH34X (The chip used for USB to serial) in your OS.
You can find the driver in ¡°driver¡± folder.
Detailed installation methods please refer to the ¡°CH34X Driver Installation Instructions.pdf¡± in ¡°driver¡± folder.

Step 3: After the driver installation is complete, open the Arduino IDE.
Select the board:  Click Tools -> Board -> Larduino-Core w/ LGT8F88A.
Select the COM: 	Click Tools -> Serial Port -> COMX(which connected to Larduino.)

Step 4: Open an example:   
Click File -> Examples -> Click which you want-> Click Upload.
     Enjoy yourself!

PS:	1.When you use SoftSerial Library, please include SoftSerialLGT.H. 
	2.The Flash size of the Larduino is 7KB(The all is 8KB,  bootloader used 1KB), so some of the bigger application may not support at now. 

We will launch bigger Flash size version of Larduino in the near future, please pay attention to us.

Thanks for all!



Author: Joinj
E-mail: joinj@foxmail.com
Sparking Work Space
