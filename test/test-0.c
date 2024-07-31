#include "../src/garbage_collector.h"
#include "assert.h"

int main(void)
{
	struct VM *vm = newVM();
	pushInt(vm, 1);
	pushInt(vm, 2);

	garbage_collector(vm);
	assert(vm->num_of_obejcts == 2 && "Should have preserved objects.");
	free_vm(vm);
}
