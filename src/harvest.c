#include "harvest.h"

static void mark(struct Object *object)
{
	// Check if object has already been processed
	if (object->marked)
		return;

	// Mark as marked
	object->marked = MARKED;

	// Recursevly mark the objects refrences
	if (object->type == OBJ_PAIR) {
		mark(object->head);
		mark(object->tail);
	}
}

static void mark_all(struct VM *vm)
{
	// iterate over the vm stack and mark all objects
	for (int i = 0; i < vm->size; ++i) {
		mark(vm->stack[i]);
	}
}

static void sweep(struct VM *vm)
{
	struct Object **object = &vm->object_head;
	// Itetate over linked list
	while (*object) {
		// Free unmarked objects and remove from linked list
		if (!(*object)->marked) {
			struct Object *unreached = *object;

			*object = unreached->next;
			free(unreached);
			vm->num_of_obejcts--;
		} else { // Unmark marked objects
			(*object)->marked = 0;
			object = &(*object)->next;
		}
	}
}

void harvest(struct VM *vm)
{
	int object_num = vm->num_of_obejcts;

	mark_all(vm);
	sweep(vm);

	vm->max_objects = vm->num_of_obejcts == 0 ? INITIAL_GC_THRESHOLD :
						    vm->num_of_obejcts * 2;
}
