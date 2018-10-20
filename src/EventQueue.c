/***************************************************************************\
EventQueue.c

	Provides an implementation of a fifo event queue usable for tracking
	inputs, actions, etc. Currently this is implemented as a ring buffer.
\***************************************************************************/

#include <stdlib.h>

#include "shared.h"

#define MAX_EVENTS 256

/***************************************************************************\
EventQueueCreate

	Allocates an empty event queue and returns it.
\***************************************************************************/
eventQueue_t* EventQueueCreate( void ) {
	return calloc( 1, sizeof( eventQueue_t ) );
}

/***************************************************************************\
EventQueueDestroy

	Empties an event queue and then
	deallocates it from memory.
\***************************************************************************/
void EventQueueDestroy( eventQueue_t* q ) {
	int i;

	if ( !q )
		return;

	for ( i = 0; i < MAX_EVENTS; i++ ) {
		if ( q->events[i] != NULL ) {
			free( q->events[i] );
			q->events[i] = NULL;
		}
	}
	free( q );
}


/**************************************\
EventPush

	Pushes the given event onto the end
	of the given queue, unless the queue
	is full in which case an error is
	returned.
\**************************************/
lsuccess_t EventPush( eventQueue_t* q, event_t* e ) {
	return false;
}

/***************************************************************************\
FunctionName

	Description of the function goes here.
\***************************************************************************/
event_t* EventPoll( eventQueue_t* q ) {
	return false;
}