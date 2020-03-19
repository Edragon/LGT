/**
 * Project: AVR ATtiny USB Tutorial at http://codeandlife.com/
 * Author: Joonas Pihlajamaa, joonas.pihlajamaa@iki.fi
 * Based on V-USB example code by Christian Starkjohann
 * Copyright: (C) 2012 by Joonas Pihlajamaa
 * License: GNU GPL v3 (see License.txt)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this is libusb, see http://libusb.sourceforge.net/ 
#include <usb.h>

// same as in main.c
#define USB_LED_OFF 0
#define USB_LED_ON  1
#define USB_DATA_OUT 2
#define USB_DATA_WRITE 4
#define USB_DATA_IN 5

// used to get descriptor strings for device identification 
static int usbGetDescriptorString(usb_dev_handle *dev, int index, int langid, 
                                  char *buf, int buflen) {
    char buffer[256];
    int rval, i;

	// make standard request GET_DESCRIPTOR, type string and given index 
    // (e.g. dev->iProduct)
	rval = usb_control_msg(dev, 
        USB_TYPE_STANDARD | USB_RECIP_DEVICE | USB_ENDPOINT_IN, 
        USB_REQ_GET_DESCRIPTOR, (USB_DT_STRING << 8) + index, langid, 
        buffer, sizeof(buffer), 1000);
        
    if(rval < 0) // error
		return rval;
	
    // rval should be bytes read, but buffer[0] contains the actual response size
	if((unsigned char)buffer[0] < rval)
		rval = (unsigned char)buffer[0]; // string is shorter than bytes read
	
	if(buffer[1] != USB_DT_STRING) // second byte is the data type
		return 0; // invalid return type
		
	// we're dealing with UTF-16LE here so actual chars is half of rval,
	// and index 0 doesn't count
	rval /= 2;
	
	// lossy conversion to ISO Latin1 
	for(i = 1; i < rval && i < buflen; i++) {
		if(buffer[2 * i + 1] == 0)
			buf[i-1] = buffer[2 * i];
		else
			buf[i-1] = '?'; // outside of ISO Latin1 range
	}
	buf[i-1] = 0;
	
	return i-1;
}

static usb_dev_handle * usbOpenDevice(int vendor, char *vendorName, 
                                      int product, char *productName) {
	struct usb_bus *bus;
	struct usb_device *dev;
	char devVendor[256], devProduct[256];
    
	usb_dev_handle * handle = NULL;
	
	usb_init();
	usb_find_busses();
	usb_find_devices();
	
	for(bus=usb_get_busses(); bus; bus=bus->next) {
		for(dev=bus->devices; dev; dev=dev->next) {			
			if(dev->descriptor.idVendor != vendor ||
               dev->descriptor.idProduct != product)
                continue;
                
            // we need to open the device in order to query strings 
            if(!(handle = usb_open(dev))) {
                fprintf(stderr, "Warning: cannot open USB device: %s\n",
                    usb_strerror());
                continue;
            }
            
            // get vendor name 
            if(usbGetDescriptorString(handle, dev->descriptor.iManufacturer, 0x0409, devVendor, sizeof(devVendor)) < 0) {
                fprintf(stderr, 
                    "Warning: cannot query manufacturer for device: %s\n", 
                    usb_strerror());
                usb_close(handle);
                continue;
            }
            
            // get product name 
            if(usbGetDescriptorString(handle, dev->descriptor.iProduct, 
               0x0409, devProduct, sizeof(devVendor)) < 0) {
                fprintf(stderr, 
                    "Warning: cannot query product for device: %s\n", 
                    usb_strerror());
                usb_close(handle);
                continue;
            }
            
            if(strcmp(devVendor, vendorName) == 0 && 
               strcmp(devProduct, productName) == 0)
                return handle;
            else
                usb_close(handle);
		}
	}
	
	return NULL;
}



int main(int argc, char **argv) {
	usb_dev_handle *handle = NULL;
    int nBytes = 0;
	int i, j;
    unsigned char buffer[256];
unsigned char dataBuf[512] = {
	0x0C, 0x94, 0x00, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 
	0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 
	0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 
	0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 
	0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 
	0x0C, 0x94, 0x2A, 0x0C, 0x0C, 0x94, 0xF7, 0x0B, 0x0C, 0x94, 0xC4, 0x0B, 0x0C, 0x94, 0x1D, 0x07, 
	0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 
	0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x0C, 0x94, 0x1D, 0x07, 0x2D, 0x2D, 0x2D, 0x2D, 

	0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 
	0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 
	0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x0A, 0x00, 0x4D, 0x69, 0x73, 0x73, 0x69, 0x6F, 0x6E, 0x20, 0x00, 
	0xCF, 0x00, 0x67, 0x00, 0x33, 0x00, 0x22, 0x00, 0x19, 0x00, 0x10, 0x00, 0x0C, 0x00, 0x08, 0x00, 
	0x06, 0x00, 0x03, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x01, 0xCF, 0x00, 
	0x67, 0x00, 0x44, 0x00, 0x33, 0x00, 0x22, 0x00, 0x19, 0x00, 0x10, 0x00, 0x0C, 0x00, 0x08, 0x00, 
	0x03, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

	0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x81, 0x00, 0x40, 0x00, 0x2A, 0x00, 0x20, 0x00, 0x15, 0x00, 
	0x0F, 0x00, 0x0A, 0x00, 0x07, 0x00, 0x04, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x08, 0x02, 0x03, 0x01, 0x81, 0x00, 0x56, 0x00, 0x40, 0x00, 0x2A, 0x00, 0x20, 0x00, 0x15, 0x00, 
	0x0F, 0x00, 0x0A, 0x00, 0x04, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00, 0x00, 0x22, 0x08, 0x11, 0x04, 
	0x08, 0x02, 0x5A, 0x01, 0x03, 0x01, 0xAD, 0x00, 0x81, 0x00, 0x56, 0x00, 0x40, 0x00, 0x2A, 0x00, 
	0x15, 0x00, 0x13, 0x00, 0x09, 0x00, 0x04, 0x00, 0x1F, 0x01, 0x8F, 0x00, 0x47, 0x00, 0x2F, 0x00, 
	0x23, 0x00, 0x17, 0x00, 0x11, 0x00, 0x0B, 0x00, 0x08, 0x00, 0x05, 0x00, 0x02, 0x00, 0x02, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x3F, 0x02, 0x1F, 0x01, 0x8F, 0x00, 0x5F, 0x00, 0x47, 0x00, 0x2F, 0x00, 

	0x23, 0x00, 0x17, 0x00, 0x11, 0x00, 0x0B, 0x00, 0x05, 0x00, 0x05, 0x00, 0x02, 0x00, 0x00, 0x00, 
	0xFF, 0x08, 0x7F, 0x04, 0x3F, 0x02, 0x80, 0x01, 0x1F, 0x01, 0xBF, 0x00, 0x8F, 0x00, 0x5F, 0x00, 
	0x47, 0x00, 0x2F, 0x00, 0x17, 0x00, 0x15, 0x00, 0x0A, 0x00, 0x05, 0x00, 0xA0, 0x01, 0xCF, 0x00, 
	0x67, 0x00, 0x44, 0x00, 0x33, 0x00, 0x22, 0x00, 0x19, 0x00, 0x10, 0x00, 0x0C, 0x00, 0x08, 0x00, 
	0x03, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x40, 0x03, 0xA0, 0x01, 0xCF, 0x00, 0x8A, 0x00, 
	0x67, 0x00, 0x44, 0x00, 0x33, 0x00, 0x22, 0x00, 0x19, 0x00, 0x10, 0x00, 0x08, 0x00, 0x07, 0x00, 
	0x03, 0x00, 0x01, 0x00, 0x04, 0x0D, 0x82, 0x06, 0x40, 0x03, 0x2B, 0x02, 0xA0, 0x01, 0x15, 0x01, 
	0xCF, 0x00, 0x8A, 0x00, 0x67, 0x00, 0x45, 0x00, 0x22, 0x00, 0x1F, 0x00, 0x0F, 0x00, 0x07, 0x00,

};
	for(i = 0; i < 64; i++)
		buffer[i] = i + 64;

	if(argc < 2) {
		printf("Usage:\n");
		printf("usbtext.exe on\n");
		printf("usbtext.exe off\n");
		printf("usbtext.exe out\n");
		printf("usbtext.exe write\n");
		printf("usbtext.exe in <string>\n");
		exit(1);
	}
	
	handle = usbOpenDevice(0x17C0, "Elppa   ", 0x15DC, "Apple   ");
	
	usb_set_configuration(handle, 1);
	usb_claim_interface(handle, 0);

	if(handle == NULL) {
		fprintf(stderr, "Could not find USB device!\n");
		exit(1);
	}

	if(strcmp(argv[1], "on") == 0) {
		nBytes = usb_control_msg(handle, 
            USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, 
			USB_LED_ON, 0, 0, (char *)buffer, sizeof(buffer), 5000);
	} else if(strcmp(argv[1], "off") == 0) {
		nBytes = usb_control_msg(handle, 
            USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, 
			USB_LED_OFF, 0, 0, (char *)buffer, sizeof(buffer), 5000);
	} else if(strcmp(argv[1], "out") == 0) {
		nBytes = usb_control_msg(handle, 
            USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, 
			USB_DATA_OUT, 0, 0, (char *)buffer, sizeof(buffer), 5000);
        printf("Got %d bytes: %s\n", nBytes, buffer);
	} else if(strcmp(argv[1], "write") == 0) {
		nBytes = usb_control_msg(handle, 
            USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, 
			USB_DATA_WRITE, 'T' + ('E' << 8), 'S' + ('T' << 8), 
            (char *)buffer, sizeof(buffer), 5000);
	} else if(strcmp(argv[1], "in") == 0 && argc > 2) {
		nBytes = usb_control_msg(handle, 
            USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_OUT, 
			USB_DATA_IN, 0, 0, argv[2], strlen(argv[2])+1, 5000);
	} else if(strcmp(argv[1], "rdrom") == 0) {
		//nBytes = usb_control_msg(handle, 
          //  USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, 
			//5, 0x0c00, 0, 
            //(char *)buffer, 16, 5000);
		for(i = 0; i < 512; i+= 4)
		{
			nBytes = usb_control_msg(handle, 
			    USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, 
				5, 0x1c00 + i, 0, 
				(char *)buffer, 4, 5000);
			if(nBytes < 0)
			{
				break;
			}
			else
			{
				printf("Data: " ,0);
				for(j = 0; j < nBytes; j++)
				{
					printf("0x%hx " ,buffer[j]);
				}
				printf("\n" ,0);
			}
		}
	} else if(strcmp(argv[1], "wrrom") == 0) {
		for(i = 0; i < 512; i+=4)
		{
			buffer[0] = dataBuf[i];
			buffer[1] = dataBuf[i+1];
			buffer[2] = dataBuf[i+2];
			buffer[3] = dataBuf[i+3];
			nBytes = usb_control_msg(handle, 
				USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_OUT, 
				4, 0x1c00 + i, 0, 
				(char *)buffer, 4, 5000);
			for(j = 0; j < 0xffffff; j++)
				;
		}
	
	} else if(strcmp(argv[1], "wrrom_0") == 0) {
		
		buffer[0] = 0x12;
		buffer[1] = 0x34;
		buffer[2] = 0x56;
		buffer[3] = 0x78;
		nBytes = usb_control_msg(handle, 
			USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_OUT, 
			4, 0xc00, 0, 
			(char *)buffer, 4, 5000);
		for(j = 0; j < 0xffffff; j++)
			;
	
	} else if(strcmp(argv[1], "wrrom_1") == 0) {
		buffer[0] = 0x9a;
		buffer[1] = 0xbc;
		buffer[2] = 0xee;
		buffer[3] = 0xf0;
		nBytes = usb_control_msg(handle, 
			USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_OUT, 
			4, 0x1c04, 0, 
			(char *)buffer, 4, 5000);
		for(j = 0; j < 0xffffff; j++)
			;
	}
	else if(strcmp(argv[1], "rdrom_0") == 0) {
		for(i = 0; i < 8; i+= 4)
		{
			nBytes = usb_control_msg(handle, 
			    USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, 
				5, 0xc00 + i, 0, 
				(char *)buffer, 4, 5000);
			if(nBytes < 0)
			{
				break;
			}
			else
			{
				printf("Data: " ,0);
				for(j = 0; j < nBytes; j++)
				{
					printf("0x%hx " ,buffer[j]);
				}
				printf("\n" ,0);
			}
		}
		goto exit;
	} else if(strcmp(argv[1], "epage") == 0) {
		nBytes = usb_control_msg(handle, 
            USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_OUT, 
			3, 0x0c00, 0, 
			(char *)buffer, 0, 5000);
	} else if(strcmp(argv[1], "erase") == 0) {
		nBytes = usb_control_msg(handle, 
            USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, 
			2, 0x0c00, 0, 
			(char *)buffer, 1, 5000);
	} else if(strcmp(argv[1], "rdid") == 0) {
		nBytes = usb_control_msg(handle, 
            USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, 
			6, 0x0c00, 0, 
			(char *)buffer, 4, 5000);
	} else if(strcmp(argv[1], "wrone") == 0) {
		buffer[0] = dataBuf[0];
		buffer[1] = dataBuf[1];
		nBytes = usb_control_msg(handle, 
			USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_OUT, 
			4, 0x1c00, 0, 
			(char *)buffer, 2, 5000);
	} 

	if(nBytes < 0)
	{
		fprintf(stderr, "USB error: %s\n", usb_strerror());
		fprintf(stderr, "USB error: 0x%2x\n", nBytes);
	}
	else
	{
		printf("Data: " ,0);
		for(i = 0; i < nBytes; i++)
		{
			printf("0x%2x " ,buffer[i]);
		}
		printf("\n" ,0);
	}
exit:
	usb_close(handle);
	
	return 0;
}
