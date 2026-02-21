#include "StdAfx.h"
#include "uupDev.h"

CuupDev::~CuupDev(void)
{
}

CuupDev::CuupDev(bool init, int bsize, int psize, WORD pid, WORD vid)
{
	struct usb_bus *busIt;
	struct usb_device *devIt;

	isOpen = false;
	curPID = pid;
	curVID = vid;
	bWidth = bsize;
	pSize = psize;

	if(init) {
		usb_init();
		usb_find_busses();
		usb_find_devices();

		devMap.clear();
		for(busIt = usb_get_busses(); busIt; busIt = busIt->next) {
			for( devIt = busIt->devices; devIt; devIt = devIt->next) {
				WORD idVendor = devIt->descriptor.idVendor;
				WORD idProduct = devIt->descriptor.idProduct;
			
				if(idVendor == vid && idProduct == pid) {
					devMap[CString(devIt->filename)] = devIt;
				}
			}
		}		
	}
}

bool CuupDev::open(struct usb_device *dev)
{
	if(isOpen) {
		usb_close(udev);
		isOpen = false;
	} else {
		udev = usb_open(dev);
		if(udev) {
			isOpen = true;
		}
	}

	return isOpen;
}

void CuupDev::refresh()
{
	struct usb_bus *busIt;
	struct usb_device *devIt;

	usb_init();
	usb_find_busses();
	usb_find_devices();

	devMap.clear();
	for(busIt = usb_get_busses(); busIt; busIt = busIt->next) {
		for( devIt = busIt->devices; devIt; devIt = devIt->next) {
			WORD idVendor = devIt->descriptor.idVendor;
			WORD idProduct = devIt->descriptor.idProduct;
			
			if(idVendor == curVID && idProduct == curPID) {
				devMap[CString(devIt->filename)] = devIt;
			}
		}
	}
}

bool CuupDev::setDevHandle(usb_dev_handle *dev)
{
	if(isOpen) {
		usb_close(udev);
		isOpen = false;
	} 

	if(dev) {
		udev = dev;
		isOpen = true;
	} else {
		isOpen = false;
	}

	return isOpen;
}

void CuupDev::close()
{
	if(isOpen) {
		usb_close(udev);
		isOpen = false;
	}
}

struct usb_device *CuupDev::devFromFileName(CString& fileName)
{
	if(lgt::map_haskey(devMap, fileName))
		return devMap[fileName];
	else
		return (struct usb_device*)0;
}

bool CuupDev::spiPortInit(int)
{
	return true;
}

bool CuupDev::ispSync()
{
	char tmp[1];

	if(!udev) return false;

	int retVal = usb_control_msg(udev, 0xc0, 0x02, 0, 0, tmp, 1, 5000);
	
	return (retVal == 1)&&(tmp[0] == 'I');
}

bool CuupDev::ispProgDisable()
{
	return true;
}

bool CuupDev::ispReset()
{
	return true;
}

bool CuupDev::ispReadGUID(uupByteArray_t &ba)
{
	char tmp[4];

	if(!udev) return false;
	
	int retVal = usb_control_msg(udev, 0xc0, 0x06, 0, 0, tmp, 4, 5000);

	if(retVal == 4)
		ba.insert(ba.begin(), tmp, tmp+4);

	return retVal == 4;
}

bool CuupDev::ispReadFLASHPage(uupByteArray_t &ba, int address, int length)
{
	char tmp[F_CHUNKSIZE];
	
	int s = 0;
	int timeout = 0;

	if(!udev) return false;

	int retVal;
	ba.clear();
	int addr = address;
	while (s < length) {
		do {
			timeout++;
			retVal = usb_control_msg(udev, 0xc0, 0x05, addr, 0, tmp, bWidth, 5000);
		} while(retVal < 0 && timeout < 0x1ff);

		if(timeout == 0x1ff)
			break;
		s += retVal;
		addr += retVal;
		ba.insert(ba.end(), tmp, tmp+retVal);
		timeout = 0;
	}
	
	return (retVal >= 0 && timeout < 0x1ff);
}

bool CuupDev::ispWriteFlashPage(uupByteArray_t &ba, int address)
{
	int retVal = 0;
	uupByteArray_t seg;
	int s = 0;
	int addr = address;
	int timeout0 = 0;
	int timeout1 = 0;

	if(!udev) return false;

	while(s < pSize) {
		seg = lgt::vector_mid(ba, s, bWidth);

		if(seg.size() == 0)
			break;

		do {
			retVal = usb_control_msg(udev, 0x40, 0x04, addr, 0, seg.data(), seg.size(), 5000);
			do {
				lgt::delay();
				timeout0++;
			} while(!ispSync() && timeout0 < 0x1ff);
			
			if(timeout0 == 0x1ff) {
				timeout1 = 0x1ff;
				break;
			}
			timeout0 = 0;
			timeout1++;
		} while (retVal < 0 && timeout1 < 0x1ff);

		if(timeout1 == 0x1ff)
			break;
		addr += seg.size();
		s += seg.size();
		timeout1 = 0;
	}
	
	return (retVal >= 0 && timeout1 < 0x1ff);
}

bool CuupDev::ispEraseFlashPage(int paddress)
{
	int ret;
	char tmp[1];
	
	if(!udev) return false;

	ret = usb_control_msg(udev, 0xc0, 0x03, paddress, 0, tmp, 0, 5000);
	
	return (ret >= 0);
}

bool CuupDev::ispReadE2PROM(uupByteArray_t &, int, int)
{
	return true;
}

bool CuupDev::ispWriteE2PROM(uupByteArray_t &, int)
{
	return true;
}

bool CuupDev::ispEraseE2PROM()
{
	return true;
}