
#define MAX_BACKENDS 32
#define MAX_BACKEND_NAME_LEN 32

typedef struct backend_s {
	char name[MAX_BACKEND_NAME_LEN];
	int (*Init)( void );
	int (*Poll)( void );
	int (*Shutdown)( void );
	/* video functions the backend will likely handle */
	int (*SwapBuffers)( void );
} backend_t;

int BackendInit( void );
int BackendAdd( backend_t backend );
backend_t BackendByName( char* name );