#include "stdafx.h"
#include "lgtglobal.h"

namespace lgt {

std::map <CString, LGTChipConfig> lgt_chipmap;

void lgt_chipmap_init()
{
	LGTChipConfig lgt8f08a = {CString("LGT8F08A"), 5120, 504, 512, 2};
	LGTChipConfig lgt8f88a = {CString("LGT8F88A"), 5120, 504, 512, 4};
	LGTChipConfig lgt8fx8d = {CString("LGT8FX8D"), 29696, 0, 1024, 2};
	lgt_chipmap[CString("LGT8F08A")] = lgt8f08a;
	lgt_chipmap[CString("LGT8F88A")] = lgt8f88a;
	lgt_chipmap[CString("LGT8FX8D")] = lgt8fx8d;
}

void delay()
{
	volatile int i = 0;

	for(; i < 0x1ff; i++);
}

bool map_haskey(const uupDevMap_t& _map, const CString& key)
{
	uupDevMap_t :: const_iterator it;

	it = _map.find(key);

	return it != _map.end();
}

bool vector_haskey(const uupStringArray_t& _vector, const CString& key)
{
	bool ret = false;
	uupStringArray_t :: const_iterator it;

	for(it=_vector.begin(); it < _vector.end(); it++) {
		if(*it == key) {
			ret = true;
			break;
		}
	}

	return ret;
}

uupByteArray_t vector_mid(const uupByteArray_t& vs, int pos, int size)
{
	uupByteArray_t vt;

	if(pos < 0 && size <= 0)
		return vt;

	if((pos + size) > (int)vs.size())
		return vt;

	for(int i = 0; i < size; i++)
		vt.push_back(vs[i+pos]);

	return vt;
}

bool vector_compare(const uupByteArray_t& _v0, const uupByteArray_t& _v1)
{
	if (_v0.size() != _v1.size())
		return false;

	uupByteArray_t :: const_iterator it;

	for(int i = 0; i < (int)_v0.size(); i++) {
		if(_v0[i] != _v1[i])
			return false;
	}

	return true;
}

}