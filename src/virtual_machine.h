#include "garbage_collector.h"
#include <stdlib.h>

#define STACK_MAX 256

typedef struct {
	object_t *stack[STACK_MAX];
	size_t size;
} VM_t;

VM_t *newVM();

void push(VM_t *vm, object_t *value);

object_t *pop(VM_t *vm);

object_t *newObject(VM_t *vm, object_e type);
