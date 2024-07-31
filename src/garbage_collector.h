typedef enum { OBJ_INT, OBJ_PAIR } object_e;

typedef struct sObject {
	object_e type;

	union {
		/* OBJ_INT */
		int value;

		/* OBJ_PAIR */
		struct {
			struct sObject *head;
			struct sObject *tail;
		};
	};
} object_t;
