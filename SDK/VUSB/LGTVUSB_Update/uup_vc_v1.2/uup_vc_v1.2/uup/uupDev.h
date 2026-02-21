#pragma once

#include "lusb0_usb.h"
#include "lgtglobal.h"

#define F_CHUNKSIZE 512

class CuupDev
{
public:
	CuupDev(bool init=true, int bsize = 2, int psize = 512, WORD pid=0x15dc, WORD vid=0x17c0);
	~CuupDev(void);

	bool open(struct usb_device *dev);
	bool setDevHandle(usb_dev_handle *dev);
	bool isDevOpen() { return isOpen; }
	void refresh();
	uupDevMap_t &getDevList() { return devMap; }
	struct usb_device *devFromFileName(CString& fileName);

	bool spiPortInit(int);
	bool ispSync();
	bool ispProgDisable();
	bool ispReset();
	bool ispReadGUID(uupByteArray_t &ba);
	bool ispReadFLASHPage(uupByteArray_t &ba, int address, int length=512);
	bool ispWriteFlashPage(uupByteArray_t &ba, int address);
	bool ispEraseFlashPage(int paddress);
	bool ispReadE2PROM(uupByteArray_t &ba, int address, int length=128);
	bool ispWriteE2PROM(uupByteArray_t &ba, int address);
	bool ispEraseE2PROM();
	void close();

private:
	WORD curPID;
	WORD curVID;
	bool isOpen;
	int bWidth;
	int pSize;
	uupDevMap_t devMap;
	usb_dev_handle *udev;
};

