#include "virtual_machine.h"
#include "assert.h"

VM_t *newVM()
{
	VM_t *vm = malloc(sizeof(VM_t));
	vm->size = 0;
	return vm;
}

void push(VM_t *vm, object_t *value)
{
	assert(vm->size < STACK_MAX && "Stack overflow!");
	vm->stack[vm->size++] = value;
}

object_t *pop(VM_t *vm)
{
	assert(vm->size > 0 && "Stack underflow!");
	return vm->stack[--vm->size];
}

object_t *newObject(VM_t *vm, object_e type)
{
	object_t *object = malloc(sizeof(object_t));
	object->type = type;
	return object;
}

void pushInt(VM_t *vm, int intValue)
{
	object_t *object = newObject(vm, OBJ_INT);
	object->value = intValue;
	push(vm, object);
}

object_t *pushPair(VM_t *vm)
{
	object_t *object = newObject(vm, OBJ_PAIR);
	object->tail = pop(vm);
	object->head = pop(vm);

	push(vm, object);
	return object;
}
