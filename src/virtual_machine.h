#include "garbage_collector.h"
#include <stdlib.h>

#define STACK_MAX 256

struct VM {
	struct Object *stack[STACK_MAX];
	size_t size;
};

struct VM *newVM(void);

void push(struct VM *vm, struct Object *value);

struct Object *pop(struct VM *vm);

struct Object *newObject(struct VM *vm, object_e type);

void pushInt(struct VM *vm, int intValue);

struct Object *pushPair(struct VM *vm);
