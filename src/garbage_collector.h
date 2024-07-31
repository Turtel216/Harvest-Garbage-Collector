#include <stdlib.h>

//
// Virtual Machine
//
typedef enum { OBJ_INT, OBJ_PAIR } object_e;

#define STACK_MAX 256

struct VM {
	struct Object *stack[STACK_MAX];
	size_t size;
};

struct VM *newVM(void);

void push(struct VM *vm, struct Object *value);

struct Object *pop(struct VM *vm);

struct Object *newObject(struct VM *vm, object_e type);

void pushInt(struct VM *vm, int value);

struct Object *pushPair(struct VM *vm);

//
// Garbage Collector
//
struct Object {
	unsigned char marked;
	object_e type;

	union {
		/* OBJ_INT */
		int value;

		/* OBJ_PAIR */
		struct {
			struct Object *head;
			struct Object *tail;
		};
	};
};

void mark_all(struct VM *vm);
