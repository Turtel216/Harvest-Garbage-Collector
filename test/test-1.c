#include "../src/garbage_collector.h"
#include "assert.h"

int main(void)
{
	struct VM *vm = newVM();
	pushInt(vm, 1);
	pushInt(vm, 2);
	pop(vm);
	pop(vm);

	garbage_collector(vm);
	assert(vm->num_of_obejcts == 0 && "Should have collected objects.");
	free_vm(vm);
}
