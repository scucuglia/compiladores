#ifndef _ANALYZE_H_
#define _ANALYZE_H_

#include "symtab.h"

int validate_decl(char * name, int lineno, char * scope, IDType idType, ExpType valType);

int check_not_exist (char * name, char *scope, IDType idType);

int validate_main();

void build_tab_simb();

#endif
