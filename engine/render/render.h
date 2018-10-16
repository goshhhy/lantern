
typedef struct renderer_s {
	int (*Init)( void );
	struct info {
		bool backendShouldCreateGlContext;
	}
} renderer_t;