#include "garbage_collector.h"

void mark(struct Object *object)
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

void mark_all(struct VM *vm)
{
	// iterate over the vm stack and mark all objects
	for (int i = 0; i < vm->size; ++i) {
		mark(vm->stack[i]);
	}
}

void sweep(struct VM *vm)
{
	struct Object **object = &vm->object_head;
	// Itetate over linked list
	while (*object) {
		// Free unmarked objects and remove from linked list
		if (!(*object)->marked) {
			struct Object *unreached = *object;

			*object = unreached->next;
			free(unreached);
		} else { // Unmark marked objects
			(*object)->marked = 0;
			object = &(*object)->next;
		}
	}
}
