typedef enum { OBJ_INT, OBJ_PAIR } object_e;

struct Object {
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
