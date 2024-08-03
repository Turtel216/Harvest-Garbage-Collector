#include "../src/harvest.h"

int main(void)
{
	struct VM *vm = newVM();

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 20; j++) {
			pushInt(vm, i);
		}

		for (int k = 0; k < 20; k++) {
			pop(vm);
		}
	}
	free_vm(vm);
}
