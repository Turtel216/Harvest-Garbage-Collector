#include "../src/harvest.h"
#include "assert.h"

int main(void)
{
	struct VM *vm = newVM();
	pushInt(vm, 1);
	pushInt(vm, 2);
	struct Object *a = pushPair(vm);
	pushInt(vm, 3);
	pushInt(vm, 4);
	struct Object *b = pushPair(vm);

	/* Set up a cycle, and also make 2 and 4 unreachable and collectible. */
	a->tail = b;
	b->tail = a;

	harvest(vm);
	assert(vm->num_of_obejcts == 4 && "Should have collected objects.");
	free_vm(vm);
}
