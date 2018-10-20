typedef struct event_s {
	int eventClass;
} event_t;

typedef struct eventQueue_s {
	int readPos;
	int writePos;
	event_t* events[256];
} eventQueue_t;
