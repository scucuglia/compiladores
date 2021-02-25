#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include "globals.h"

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
typedef enum {Fun,Var} IDType;

void st_insert(char * name, int lineno, char * scope, IDType idType, ExpType valType);

typedef struct LineListRec
{
	int lineno;
	struct LineListRec *next;
} * LineList;

typedef struct BucketListRec
{
	char *name;
	LineList lines;
	char *scope;
	IDType idType;
	ExpType valType;
	struct BucketListRec *next;
} * BucketList;

BucketList get_bucket(char *name);

/* Procedure printSymTab prints a formatted
 * listing of the symbol table contents
 * to the listing file
 */
void print_tab_simb(FILE * listing);


#endif
