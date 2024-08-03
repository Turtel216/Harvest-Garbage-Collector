#include "../src/harvest.h"
#include "assert.h"

int main(void)
{
	struct VM *vm = newVM();
	pushInt(vm, 1);
	pushInt(vm, 2);
	pushPair(vm);
	pushInt(vm, 3);
	pushInt(vm, 4);
	pushPair(vm);
	pushPair(vm);

	harvest(vm);
	assert(vm->num_of_obejcts == 7 && "Should have reached objects.");
	free_vm(vm);
}
