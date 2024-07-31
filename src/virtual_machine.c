#include "garbage_collector.h"
#include "assert.h"

struct VM *newVM()
{
	struct VM *vm = malloc(sizeof(struct VM));
	vm->size = 0;
	return vm;
}

void push(struct VM *vm, struct Object *value)
{
	assert(vm->size < STACK_MAX && "Stack overflow!");
	vm->stack[vm->size++] = value;
}

struct Object *pop(struct VM *vm)
{
	assert(vm->size > 0 && "Stack underflow!");
	return vm->stack[--vm->size];
}

struct Object *newObject(struct VM *vm, object_e type)
{
	struct Object *object = malloc(sizeof(struct Object));
	object->type = type;
	return object;
}

void pushInt(struct VM *vm, int value)
{
	struct Object *object = newObject(vm, OBJ_INT);
	object->value = value;
	push(vm, object);
}

struct Object *pushPair(struct VM *vm)
{
	struct Object *object = newObject(vm, OBJ_PAIR);
	object->tail = pop(vm);
	object->head = pop(vm);

	push(vm, object);
	return object;
}
