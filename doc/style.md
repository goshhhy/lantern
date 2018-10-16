General
=======

Use real tabs equal to 4 spaces.

Use C style comments, not C++. Do this,

	/* this is a good comment */

never this:

	// this is a bad comment



Use typically trailing braces everywhere.

    if ( x ) {
    }

Else statements begin on the same line as the closing brace.

	if ( x ) {
	} else {
	}

Pad parenthesized expressions with spaces. Do this,

	if ( x ) {
	}

not this:

	if (x) {
	}

Do this,

	x = ( y * 0.5f );

not this:

	x = (y * 0.5f);

Use precision specification for floating point values unless there is an explicit need for a double. Do this,

	float f = 0.5f;

not this:

	float f = 0.5;

Do this,

	float f = 1.0f;

not this:

	float f = 1.f;

Function names start with upper case:

	void Function( void );

Function names are CamelCase:

	void ThisFunctionDoesSomething( void );

Function headers should look like this:

	/*===============================*\
	FunctionName

		Description of the function
	\*===============================*/
	void FunctionName( void ) { ...

Variable names begin with a lowercase character.

	float x;

Multi-word variable names are camelCase.

	float maxDistance;

Typedef names use the same naming convention as variables, but end with "_t":

	typedef int fileHandle_t;

Struct names use the same convention as variables, but end with "_s":

	struct treeNode_s;

This means that a struct type definition should look like this:

	typedef struct treeNode_s {
		...
	} treeNode_t;

Enum names use the sane naming convention as variables, but always end with _t.
Enum constants are in UPPERCASE, and are UNDERSCORE_SEPARATED.

	enum color_t {
		COLOR_RED = 1
		COLOR_GREEN = 2,
		COLOR_BLUE = 4
	}

Names of recursive functions end with "_r":

	void CalculatePi_r( int numDigits );

Definition names use all UPPERCASE and are UNDERSCORE_SEPARATED.

	#define MAX_CONNECTIONS		24

Use 'const' whenever possible.

	const int *p;			/* pointer to const int */
	int * const p;			/* const pointer to int */
	const int * const p;		/* const pointer to const int */

Never do this:

	int const *p;


