#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "globals.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash(char *key)
{
	int temp = 0;
	int i = 0;
	while (key[i] != '\0')
	{
		temp = ((temp << SHIFT) + key[i]) % SIZE;
		++i;
	}
	return temp;
}

/* the hash table */
static BucketList hashTable[SIZE];

void st_insert(char *name, int lineno, char *scope, IDType idType, ExpType valType)
{
	int h = hash(name);

	BucketList l = hashTable[h];
	BucketList lGlob = NULL;
	while (l != NULL)
	{
		if (strcmp(name, l->name) == 0)
		{
			if (strcmp(l->scope, "Global") == 0)
				lGlob = l;
			if (strcmp(scope, l->scope) == 0)
				break;
		}
		l = l->next;
	}

	if (l == NULL)
		l = lGlob;
	if (l == NULL) /* variable not yet in table */
	{
		l = (BucketList)malloc(sizeof(struct BucketListRec));
		l->name = name;
		l->lines = (LineList)malloc(sizeof(struct LineListRec));
		l->lines->lineno = lineno;
		l->scope = scope;
		l->valType = valType;
		l->idType = idType;
		l->lines->next = NULL;
		l->next = hashTable[h];
		hashTable[h] = l;
	}
	else /* found in table, so just add line number */
	{

		LineList t = l->lines;
		while (t->next != NULL)
			t = t->next;
		t->next = (LineList)malloc(sizeof(struct LineListRec));
		t->next->lineno = lineno;
		t->next->next = NULL;
	}
} /* st_insert */

BucketList get_bucket(char *name) {
	int h = hash(name);
	BucketList l = hashTable[h];
	return l;
}

/* Procedure printSymTab prints a formatted
 * listing of the symbol table contents
 * to the listing file
 */
void print_tab_simb(FILE *listing)
{
	int i;
	fprintf(listing, "Nome do identificador  Tipo           Escopo      \n");
	fprintf(listing, "---------------------  -------------  ------------\n");
	for (i = 0; i < SIZE; ++i)
	{
		if (hashTable[i] != NULL)
		{
			BucketList l = hashTable[i];
			while (l != NULL)
			{
				LineList t = l->lines;
				// Nome do identificador
				fprintf(listing, "%-20s  ", l->name);

				// Tipo
				if (l->idType)
					fprintf(listing, " %-14s ", "var");
				else
					fprintf(listing, " %-14s ", "func");

				// Escopo
				fprintf(listing, "%-14s   ", l->scope);

				fprintf(listing, "\n\n");

				l = l->next;
			}
		}
	}
	fprintf(listing, "\n");
}
