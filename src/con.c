/***************************************************************************\
con.c

	Implementation of console stuff - commands, vars, etc
\***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "shared.h"

#define MAX_CMD_ARGS 8
#define MAX_VAR_LENGTH 32

typedef struct conCmd_s {
	char* name;
	void (*func)( int argc, char** argv );
	struct conCmd_s* next;
} conCmd_t;

typedef enum {
	VAR_TYPE_STRING,
	VAR_TYPE_INTEGER
} varType_t;

typedef struct conVar_s {
	char* name;

	varType_t type;
	union {
		char* asChar;
		int asInt;
	};
	
	struct conVar_s* next;
} conVar_t;

conCmd_t* firstConCmd = NULL;
conCmd_t* lastConCmd = NULL;
conVar_t* firstConVar = NULL;
conVar_t* lastConVar = NULL;

bool IsInteger( char* str ) {
	for ( int i = 0; i < strlen( str ); i++ )
		if ( ( str[i] < '0' ) || ( str[i] > '9' ) )
			return false;

	return true;
}

conVar_t* ConVar( char* name ) {
	conVar_t* var;

	for ( var = firstConVar; ( var != NULL ); var = var->next ) {

		if ( !strncmp( var->name, name, 32 ) ) {
			return var;
		}
	}
	return NULL;
}

conCmd_t* ConCmd( char* name ) {
	conCmd_t* cmd;

	for ( cmd = firstConCmd; ( cmd != NULL ); cmd = cmd->next ) {

		if ( !strncmp( cmd->name, name, 32 ) ) {
			return cmd;
		}
	}
	return NULL;
}

void ConCmd_Set( int argc, char** argv ) {
	conVar_t* var;
	
	if ( argc != 2 ) {
		printf( "set: wrong number of arguments\n" );
		return;
	}
	
	var = ConVar( argv[1] );

	if ( var == NULL ) {
		var = malloc( sizeof( conVar_t ) );
		if ( lastConVar )
			lastConVar->next = var;
		else
			firstConVar = var;
		lastConVar = var;
		var->name = malloc( MAX_VAR_LENGTH );
		strncpy( var->name, argv[1], MAX_VAR_LENGTH );
	}

	if ( IsInteger( argv[2]) ) {
		var->type = VAR_TYPE_INTEGER;
		var->asInt = atoi( argv[2] );
	} else {
		var->type = VAR_TYPE_STRING;
		var->asChar = malloc( strlen( argv[2] ) );
		strcpy( var->asChar, argv[2] );
	}
}

/***************************************************************************\
ConEval

	Takes a line, parses	for ( var = firstConVar; ( var != NULL ); var = var->next ) { it into a command and arguments, and tries to find
	and run that command. If the command does not exist, tries to find a 
	variable by that nam		if ( !strncmp( var->name, argv[1], 32 ) ) {e. If it does, and there are no arguments, prints
	that variable. If th			break;ere is exactly one argument, sets that variable.
		}
	Succeeds for all the	} above cases, for any other case returns failure.

	Caller is expected to free char* line.
\***************************************************************************/
lsuccess_t ConEval( char* line ) {
	int i, cmd_argc = -1, len = strnlen( line, 256 );
	char* cmd_argv[MAX_CMD_ARGS];
	conCmd_t* c;
	conVar_t* v;

	memset( cmd_argv, MAX_CMD_ARGS, sizeof( char* ) );

	cmd_argv[++cmd_argc] = line;
	for ( i = 0; ( i < len ) && ( cmd_argc < MAX_CMD_ARGS ); i++ ) {
		if ( line[i] <= ' ' ) {
			line[i] = '\0';
			cmd_argv[++cmd_argc] = &line[i+1];
		}
	}

	c = ConCmd( cmd_argv[0] );
	if ( c ) {
		c->func( cmd_argc, cmd_argv );
	} else {
		v = ConVar( cmd_argv[0] );
		if ( !v ) {
			printf( "no such command or variable: %s\n", cmd_argv[0] );
			return false;
		}
		if ( cmd_argc == 0 ) {
			if ( v->type == VAR_TYPE_INTEGER ) {
				printf( "%s = %i\n", v->name, v->asInt );
			} else {
				printf( "%s = \"%s\"\n", v->name, v->asChar );
			}
		} else if ( cmd_argc == 1 ) {
			cmd_argv[2] = cmd_argv[1];
			cmd_argv[1] = cmd_argv[0];
			cmd_argv[0] = "set";
			ConCmd_Set( 2, cmd_argv );
		}
	}

	return true;
}

void ConAddCmd( char* name, void (*func)( int argc, char** argv ) ) {
	conCmd_t* cmd = malloc( sizeof( conCmd_t ) );
	
	cmd->name = name;
	cmd->func = func;

	if ( lastConCmd )
		lastConCmd->next = cmd;
	else
		firstConCmd = cmd;
	lastConCmd = cmd;
}

void ConInit( void ) {
	FILE* conf = fopen( "config.cfg", "r" );
	char str[256];

	ConAddCmd( "set", ConCmd_Set );

	if ( !conf ) {
		printf( "Couldn't open config.cfg\n" );
		return;
	}

	while ( ( fscanf( conf, "%[^\n]\n", str ) ) > 0 ) {
		printf( "] %s\n", str );
		ConEval( str );
	}
}


