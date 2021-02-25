%{
#define YYPARSER

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include "symtab.h"

#define YYSTYPE NodeInfoOrType
typedef union NodeInfoOrType NodeInfoOrType;
typedef struct Info{
	char * str;
	int line;
	char * scope;
}Info;
union NodeInfoOrType {
	TreeNode * tree;
	ExpType expType;
	TokenType opType;
	Info info;
};

static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */

char *scope;
static int yylex(void) { return getToken(); }

TreeNode * parse(void) {
  st_insert( copyString("input"), 0, copyString("Global"),Fun,Integer);
  st_insert( copyString("output"),0, copyString("Global"),Fun,Void);
  scope = copyString("Global");
  yyparse();
  return savedTree;
}

%}


%token ID NUM SOM SUB MUL DIV ATT PEV ABP FCP FIM ERR IF ELSE  INT  RETURN VOID  WHILE  COM  MENIG  MAIOR  MENOR  MAIIG   DIF  VIRG  ABCH  FECCH  ABCO FCCO IGLIGL ERROR

%% /* Gramatica do C- */

programa     : declaracao_lista
		{ savedTree = $1.tree; }
		;

declaracao_lista    : declaracao_lista declaracao
		{
			YYSTYPE t;
			t.tree = $1.tree;
			if (t.tree != NULL) {
				while (t.tree->sibling != NULL)  {
					t.tree = t.tree->sibling;
				}
				t.tree->sibling = $2.tree;
				$$.tree = $1.tree;
			} else {
				$$.tree = $2.tree;
			}
     	}
		| declaracao
		{ $$.tree=$1.tree; }
		;

declaracao        : var_declaracao
		{ $$.tree=$1.tree; }
		| fun_declaracao
		{ $$.tree=$1.tree; }
		;

var_declaracao    : tipo_especificador ID PEV
		{
			$$.tree=newDeclNode(VarK);
			$$.tree->type=$1.expType;
			if($$.tree->type==Void){
				printf("Erro semantico: declaracao invalida de variavel (void). Linha %d, variavel %s\n",$$.info.line,tokenString);
			}
			$$.tree->attr.name = copyString(tokenString);
			if(check_not_exist($$.tree->attr.name, copyString(scope),Var)==1)
				st_insert( $$.tree->attr.name,lineno, copyString(scope), Var, $$.tree->type);
		}
		| tipo_especificador ID
		{
			$$.info.str=copyString(tokenString);
			$$.info.scope=copyString(scope);$$.info.line=lineno;
		}
		ABCO NUM FCCO PEV
		{
			$$.tree=newDeclNode(VarArrayK);
			$$.tree->type=$1.expType;
			if($$.tree->type==Void){
				printf("Erro semantico: declaracao invalida de variavel (void). Linha %d, variavel %s\n",lineno,$3.info.str);
			}

			$$.tree->attr.name = $3.info.str;

			if(check_not_exist($$.tree->attr.name, $3.info.scope,Var)==1)
				st_insert( $$.tree->attr.name,$3.info.line, $3.info.scope, Var, $$.tree->type);
		}
	    ;

tipo_especificador   : INT
		{ $$.expType=Integer; }
 	    | VOID
		{ $$.expType=Void; }
		;

fun_declaracao    : tipo_especificador ID
		{
			$$.info.str =copyString(tokenString);
			if(check_not_exist(  copyString(tokenString),copyString("Global"),Fun)==1)
				st_insert( copyString(tokenString),lineno, copyString("Global"),Fun, $1.expType);
			scope = copyString($$.info.str);
		}
		ABP params FCP composto_decl
		{
			$$.tree=newDeclNode(FunK);
			$$.tree->type=$1.expType;
			$$.tree->attr.name =$3.info.str;
			$$.tree->child[0]=$5.tree;
			$$.tree->child[1]=$7.tree;
			scope = copyString("Global");
		}

	    ;
params		: param_lista
		{ $$.tree=$1.tree; }
		| VOID
		{ $$.tree=NULL; }
		;

param_lista : param_lista VIRG param
		{
			YYSTYPE t;
		   	t.tree = $1.tree;
			if (t.tree != NULL) {
				while (t.tree->sibling != NULL)
					t.tree = t.tree->sibling;
				t.tree->sibling = $3.tree;
				$$.tree = $1.tree;
			} else {
				$$.tree = $3.tree;
			}
		}
	    | param
		{$$.tree=$1.tree;}
		;

param	    : tipo_especificador ID
		{
			$$.tree=newDeclNode(ParamK);
			$$.tree->type=$1.expType;
			$$.tree->attr.name = copyString(tokenString);
			if($$.tree->type==Void){
				printf("Erro semantico: declaracao invalida de variavel (void). Linha %d, parametro %s\n",lineno,$$.tree->attr.name);
			}
			if(check_not_exist($$.tree->attr.name, copyString(scope), Var)==1)
				st_insert( $$.tree->attr.name,lineno, copyString(scope), Var, $$.tree->type);
		}
		| tipo_especificador ID
		{
			$$.info.str=copyString(tokenString);
			$$.info.scope=copyString(scope);
			$$.info.line=lineno;
		} ABCO FCCO
		{
			$$.tree=newDeclNode(ParamArrayK);
			$$.tree->type=$1.expType;
			$$.tree->attr.name =$3.info.str;
			if($$.tree->type==Void){
				printf("Erro semantico: declaracao invalida de variavel (void). Linha %d, parametro %s\n",$$.info.line,$3.info.str);
			}
			if(check_not_exist($$.tree->attr.name,$3.info.scope, Var)==1)
				st_insert( $$.tree->attr.name,$3.info.line,$3.info.scope, Var, $$.tree->type);
		}
		;

composto_decl : ABCH local_declaracoes statement_lista FECCH
		{
			$$.tree=newStmtNode(CompostK);
			$$.tree->child[0]=$2.tree;
			$$.tree->child[1]=$3.tree;
		}
		;

local_declaracoes  : local_declaracoes var_declaracao
		{
			YYSTYPE t;
		 	t.tree = $1.tree;
			if (t.tree != NULL){
				while (t.tree->sibling != NULL)
					t.tree = t.tree->sibling;
				t.tree->sibling = $2.tree;
				$$.tree = $1.tree;
			} else {
				$$.tree = $2.tree;
			}
		}
	    | vazio
		{ $$.tree=NULL; }
		/* | error { $$.tree = NULL; } */
		//scope end?
		;

statement_lista  : statement_lista statement
		{
			YYSTYPE t;
			t.tree = $1.tree;
			if (t.tree != NULL){
				while (t.tree->sibling != NULL)
					t.tree = t.tree->sibling;
				t.tree->sibling = $2.tree;
				$$.tree = $1.tree;
			}
			else {
				$$.tree = $2.tree;
			}
		}
		| vazio
		{ $$.tree=NULL; }
		;

statement		: expressao_decl
		{ $$.tree=$1.tree; }
		| composto_decl
		{ $$.tree=$1.tree; }
		| selecao_decl
		{ $$.tree=$1.tree; }
		| iteracao_decl
		{ $$.tree=$1.tree; }
		| retorno_decl
		{ $$.tree=$1.tree; }
	//| error {  $$.tree = NULL;  }
		;

expressao_decl    : expressao PEV
		{ $$.tree=$1.tree; }
	    | PEV
		{ $$.tree=NULL; }
	    ;

selecao_decl    : IF ABP expressao FCP statement
		{
			$$.tree=newStmtNode(IfK);
			$$.tree->child[0]=$3.tree;
			$$.tree->child[1]=$5.tree;
		}
	    | IF ABP expressao FCP statement ELSE statement
		{
			$$.tree=newStmtNode(IfElseK);
			$$.tree->child[0]=$3.tree;
			$$.tree->child[1]=$5.tree;
			$$.tree->child[2]=$7.tree;
		}
		;

iteracao_decl	: WHILE ABP  expressao FCP statement
		{
			$$.tree=newStmtNode(IterK);
			$$.tree->child[0]=$3.tree;
			$$.tree->child[1]=$5.tree;
		}
		;

retorno_decl    : RETURN PEV
		{
			$$.tree=newStmtNode(RetK);
			$$.tree->child[0]=NULL;
		}
		| RETURN expressao PEV
		{
			$$.tree=newStmtNode(RetK);
			$$.tree->child[0]=$2.tree;
		}
		;

expressao		: var
		{
			$$.info.str=copyString(tokenString);
			$$.info.scope=copyString(scope);
			$$.info.line=lineno;
		} ATT expressao
		{
			$$.tree=newStmtNode(AssignK);
			$$.tree->child[0]=$1.tree;
			$$.tree->attr.name=$2.info.str;
			$$.tree->child[1]=$4.tree;
		}
		| simples_expressao
		{ $$.tree=$1.tree; }
		;

var		: ID
		{
			$$.tree=newExpNode(IdK);
			$$.tree->attr.name=copyString(tokenString);
			if(validate_decl( $$.tree->attr.name,lineno, copyString(scope), Var, $$.tree->type)==1)
				st_insert( $$.tree->attr.name,lineno, copyString(scope), Var, $$.tree->type);
		}
		| ID
		{
			$$.info.str=copyString(tokenString);
			$$.info.scope=copyString(scope);$$.info.line=lineno;
		}
		ABCO expressao	FCCO
		{
			$$.tree=newExpNode(ArrayK);
			$$.tree->attr.name=$2.info.str;
			$$.tree->child[0]=$4.tree;
			st_insert( $$.tree->attr.name,$2.info.line, $2.info.scope, Var, $$.tree->type);
		}
		;

simples_expressao	: soma_expressao relacional soma_expressao
		{
			$$.tree=newExpNode(OpK);
			$$.tree->child[0]=$1.tree;
			$$.tree->attr.op=$2.opType;
			$$.tree->child[1]=$3.tree;
		}
		| soma_expressao
		{ $$.tree=$1.tree; }
		;

relacional         : MENIG
		{ $$.opType=MENIG; }
		| MENOR { $$.opType=MENOR; }
		| MAIOR	{ $$.opType=MAIOR; }
		| MAIIG	{ $$.opType=MAIIG; }
		| IGLIGL { $$.opType=IGLIGL; }
		| DIF	{ $$.opType=DIF; }
		;

soma_expressao		: soma_expressao soma termo
		{
			$$.tree=newExpNode(OpK);
			$$.tree->child[0]=$1.tree;
			$$.tree->attr.op=$2.opType;
			$$.tree->child[1]=$3.tree;
		}
		| termo
		{ $$.tree=$1.tree; }
		;

soma		: SOM
		{ $$.opType=SOM; }
		| SUB
		{ $$.opType=SUB; }
		;

termo		: termo mult fator
		{
			$$.tree=newExpNode(OpK);
			$$.tree->child[0]=$1.tree;
			$$.tree->attr.op=$2.opType;
			$$.tree->child[1]=$3.tree;
		}
		| fator
		{ $$.tree=$1.tree; }
		;

mult		: MUL
		{ $$.opType=MUL; }
		| DIV
		{ $$.opType=DIV; }
		;

fator		: ABP expressao FCP
		{ $$.tree=$2.tree; }
		| var
		{ $$.tree=$1.tree; }
		| ativacao
		{ $$.tree=$1.tree; }
		| NUM
		{
			$$.tree=newExpNode(ConstK);
			$$.tree->attr.name=copyString(nextToken);
		}
		;

ativacao	: ID
		{
			$$.info.str=copyString(tokenString);
			$$.info.scope=copyString(scope);
			$$.info.line=lineno;
		}
		ABP args FCP
		{
			$$.tree=newStmtNode(AtivK);
			$$.tree->attr.name=$2.info.str;
			$$.tree->child[0]=$4.tree;
			if(validate_decl($$.tree->attr.name,$2.info.line, $2.info.scope, Fun, $$.tree->type)==1)
				st_insert( $$.tree->attr.name,$2.info.line, $2.info.scope, Fun, $$.tree->type);
		}
		;

args		: arg_lista
		{ $$.tree=$1.tree; }
		| vazio
		{ $$.tree=NULL; }
		;

arg_lista	: arg_lista VIRG expressao
		{
			YYSTYPE t;
			t.tree = $1.tree;
			if (t.tree != NULL) {
				while (t.tree->sibling != NULL)
					t.tree = t.tree->sibling;
                     t.tree->sibling = $3.tree;
                     $$.tree = $1.tree;
			} else {
				$$.tree = $3.tree;
			}
		}
		| expressao
		{ $$.tree=$1.tree; }
		;

vazio		:{ $$.tree=NULL; };
		;

%%

int yyerror(char * message)
{
	if(yychar!=ERROR){
		printf("Erro de sintaxe na linha %d. ",lineno);
	  	printf("Token nao esperado: ");
	  	printToken(yychar,nextToken);
	}
  Error = 1;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
/*int main()
{
  yyparse();
  return 1;
}*/



