#include "garbage_collector.h"

void mark(struct Object *object)
{
	// Check if object has already been processed
	if (object->marked)
		return;

	// Mark as marked
	object->marked = 1;

	// Recursevly mark the objects refrences
	if (object->type == OBJ_PAIR) {
		mark(object->head);
		mark(object->tail);
	}
}

void mark_all(struct VM *vm)
{
	for (int i = 0; i < vm->size; ++i) {
		mark(vm->stack[i]);
	}
}
