

#include "../inc/allinone.h"

int main(void)
{
	OSCCAL = 0xb0;

	while(1) {
		pci_pb_test();
		pci_pc_test();
		pci_pd_test();
		pci_pe_test();
		pci_pf_test();
	}
}
