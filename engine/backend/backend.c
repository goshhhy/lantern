#include <stdbool.h>

#include "backend.h"

#include "null/null.h"
#include "glfw/glfw.h"

backend_t backends[MAX_BACKENDS];
int numBackends = 0;
bool backendListInitialized = false;

backend_t BackendByName( char* name ) {
	int i;
	
	if ( !backendListInitialized )
		BackendInit();

	for( i = 0; i < numBackends; i++ ) {
		if ( !strncmp( backends[i].name, name, MAX_BACKEND_NAME_LEN ) ) {
			return backends[i];
		}
	}
	return backends[0];
}

int BackendAdd( backend_t backend ) {
	if ( numBackends < MAX_BACKENDS ) {
		backends[numBackends++] = backend;
		printf( "Added backend %s\n" )
		return 0;
	} else {
		fprintf( stderr, "backend: hit backend limit while trying to add %s\n", backend.name );
		return 1;
	}
}

int BackendInit( void ) {
	if ( !backendListInitialized ) {
		printf( "Initializing backend list\n" );
		BackendAdd( Backend_Null_GetAPI() );
		BackendAdd( Backend_Glfw_GetAPI() );
	}
}