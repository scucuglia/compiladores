#include "globals.h"
#include "util.h"
#include "analyze.h"

/* allocate global variables */
int lineno = 0;
FILE *source;
FILE *listing;
FILE *code;

int Error = FALSE;

int main(int argc, char *argv[])
{
	TreeNode *syntaxTree;
	char pgm[120]; /* source code file name */
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	strcpy(pgm, argv[1]);

	if (strchr(pgm, '.') == NULL)
		strcat(pgm, ".cm");
	source = fopen(pgm, "r");

	if (source == NULL)
	{
		fprintf(stderr, "File %s not found\n", pgm);
		exit(1);
	}


	listing = stdout;

	printf("\n*****************************\n");
	printf("*****************************\n");
	printf(">> COMPILADOR C-\n");
	printf(">>>>>> Arquivo: %s\n", pgm);
	printf("*****************************\n");
	printf("*****************************\n\n\n");

	syntaxTree = parse();
	printf("\n\n\n*****************************\n");
	printf("Arvore Sintática:\n");
	printf("*****************************\n");
	printTree(syntaxTree);


	printf("\n\n\n*****************************\n");
	printf("Tabela de Simbolos:\n");
	printf("*****************************\n\n");
	build_tab_simb();


	return 0;
}
