#include "globals.h"
#include "symtab.h"
#include "analyze.h"

static int location = 0;

BucketList get_bucket_list(char *name, char *scope) {
	BucketList l = get_bucket(name);
	BucketList l_global = NULL;
	while (l != NULL)
	{
		if (strcmp(name, l->name) == 0)
		{
			if (strcmp(l->scope, "Global") == 0)
				l_global = l;
			if (strcmp(scope, l->scope) == 0)
				break;
		}
		l = l->next;
	}
	if (l != NULL) return l;
	return l_global;
}

// Confirma que foi declarada e valida os tipos
int validate_decl(char *name, int lineno, char *scope, IDType idType, ExpType valType)
{
	// procura na hashtable onde esta a variavel
	BucketList l = get_bucket_list(name, scope);

	if (l == NULL)
	{
		if (idType)
			printf("Erro Semantico: uso de variavel nao declarada : %s. Linha: %d\n", name, lineno);
		else
			printf("Erro Semantico: chamada de funcao nao declarada: %s. Linha: %d\n", name, lineno);
		return -1;
	}
	else {
		if (idType != l->idType)
		{
			if (idType)
				printf("Erro Semantico: funcao %s eh usada como variavel, Linha: %d\n", name, lineno);
			else
				printf("Erro Semantico: variavel %s eh usada como funcao, Linha: %d\n", name, lineno);
			return -1;
		}
	}
	return 1;
}

int check_not_exist(char *name, char *scope, IDType idType)
{
	BucketList l = get_bucket_list(name, scope);

	if (l == NULL) return 1;

	if (l->idType == idType)
	{
		if (l->idType)
		{
			if (strcmp(scope, l->scope) == 0)
				printf("Erro Semantico: variavel %s ja havia sido declarada neste escopo (%s). Erro na Linha: %d\n", name, scope, lineno);
		}
		else
			printf("Erro Semantico: funcao %s ja havia sido declarada. Erro na Linha: %d\n", name, lineno);
	}
	else
	{
		if (idType)
			printf("Erro Semantico: declaracao invalida. %s ja havia sido declarada como funcao. Erro na Linha: %d\n", name, lineno);
		else if (strcmp(l->scope, "Global") == 0)
			printf("Erro Semantico: declaracao invalida. %s ja havia sido declarada como variavel. Erro na Linha: %d\n", name, lineno);
	}

	return -1;
}

int validate_main()
{
	BucketList l = get_bucket("main");
	while ((l != NULL) && (strcmp("main", l->name) != 0))
		l = l->next;
	if (l == NULL)
	{
		printf("\nErro Semantico: funcao main nao declarada.\n");
		return -1;
	}
	else
		return 1;
}

void build_tab_simb() {
	int main_exists = validate_main();
	if (main_exists) {
		print_tab_simb(listing);
	}
}