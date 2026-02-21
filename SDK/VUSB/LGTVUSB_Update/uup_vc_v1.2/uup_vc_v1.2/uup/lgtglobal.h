//#pragma once

#ifndef LGTGLOBAL_H
#define LGTGLOBAL_H

#include <map>
#include <vector>

//#define FPAGE_SIZE 512

typedef std::map <CString, struct usb_device *> uupDevMap_t;
typedef std::vector <char> uupByteArray_t;
typedef std::vector <CString> uupStringArray_t;

namespace lgt {

	typedef struct {
		CString chipName;
		int	progamLength;	// OTP or FLASH
		int dataLength;		// E2PROM or Data FLASH
		int psize;			// page size
		int bsize;			// bus size (byte based)
	} LGTChipConfig, *PLGTChipConfig;

	typedef struct {
		int pid;
		struct usb_device *dev;
		LPVOID pParam;
		PLGTChipConfig chip;
	} LGTPARAM, *PLGTPARAM;

	extern std::map <CString, LGTChipConfig> lgt_chipmap;
	void lgt_chipmap_init();
	void delay();
	bool map_haskey(const uupDevMap_t& _map, const CString& key);
	bool vector_haskey(const uupStringArray_t& _vector, const CString& key);
	uupByteArray_t vector_mid(const uupByteArray_t& vs, int pos, int size);
	bool vector_compare(const uupByteArray_t& _v0, const uupByteArray_t& _v1);

}

#endif