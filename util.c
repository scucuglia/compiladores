#include "globals.h"
#include "util.h"

/*
 * Funcao para printar tokens/lexemas
 */
void printToken(TokenType token, const char *tokenString)
{
	switch (token)
	{
	case ATT:
		printf("Token: ATT, Lexema: =\n");
		break;
	case ABCH:
		printf("Token: ABCH, Lexema: {\n");
		break;
	case FECCH:
		printf("Token: FECCH, Lexema: }\n");
		break;
	case ABCO:
		printf("Token: ABCO, Lexema: [\n");
		break;
	case FCCO:
		printf("Token: FCCO, Lexema: ]\n");
		break;
	case ABP:
		printf("Token: ABP, Lexema: (\n");
		break;
	case FCP:
		printf("Token: FCP, Lexema: )\n");
		break;
	case VIRG:
		printf("Token: VIRG, Lexema: ,\n");
		break;
	case PEV:
		printf("Token: PEV, Lexema: ;\n");
		break;
	case DIF:
		printf("Token: DIF, Lexema: !=\n");
		break;
	case MAIOR:
		printf("Token: MAIOR, Lexema: >\n");
		break;
	case MAIIG:
		printf("Token: MAIIG, Lexema: >=\n");
		break;
	case MENOR:
		printf("Token: MENOR, Lexema: <\n");
		break;
	case MENIG:
		printf("Token: MENIG, Lexema: <=\n");
		break;
	case IGLIGL:
		printf("Token: IGLIGL, Lexema: ==\n");
		break;
	case SOM:
		printf("Token: SOM, Lexema: +\n");
		break;
	case SUB:
		printf("Token: SUB, Lexema: -\n");
		break;
	case MUL:
		printf("Token: MUL, Lexema: *\n");
		break;
	case DIV:
		printf("Token: DIV, Lexema: /\n");
		break;
	case IF:
		printf("Token: IF, Lexema: if\n");
		break;
	case ELSE:
		printf("Token: ELSE, Lexema: else\n");
		break;
	case INT:
		printf("Token: INT, Lexema: int\n");
		break;
	case RETURN:
		printf("Token: RETURN, Lexema: return\n");
		break;
	case VOID:
		printf("Token: VOID, Lexema: void\n");
		break;
	case WHILE:
		printf("Token: WHILE, Lexema: while\n");
		break;
	case NUM:
		printf("Token: NUM, Lexema: %s\n", tokenString);
		break;
	case ID:
		printf("Token: ID, Lexema: %s\n", tokenString);
		break;
	case 0:
		printf("Token: 0, Lexema: EOF\n");
		break;
	case ERROR:
		printf("%s (erro)\n", tokenString);
		break;
	}
}

/*
 * Cria um no declaracao para a syntax tree
 */
TreeNode *newDeclNode(DeclKind kind)
{
	TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", lineno);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = DeclK;
		t->kind.decl = kind;
		t->lineno = lineno;
	}
	return t;
}

/*
 * Cria um no statement para a syntax tree
 */
TreeNode *newStmtNode(StmtKind kind)
{
	TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", lineno);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = StmtK;
		t->kind.stmt = kind;
		t->lineno = lineno;
	}
	return t;
}

/*
 * Cria um no expressao para a syntax tree
 */
TreeNode *newExpNode(ExpKind kind)
{
	TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
	int i;
	if (t == NULL)
		printf("Out of memory error at line %d\n", lineno);
	else
	{
		for (i = 0; i < MAXCHILDREN; i++)
			t->child[i] = NULL;
		t->sibling = NULL;
		t->nodekind = ExpK;
		t->kind.exp = kind;
		t->lineno = lineno;
		t->type = Void;
	}
	return t;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char *copyString(char *s)
{
	int n;
	char *t;
	if (s == NULL)
		return NULL;
	n = strlen(s) + 1;
	t = malloc(n);
	if (t == NULL)
		printf("Out of memory error at line %d\n", lineno);
	else
		strcpy(t, s);
	return t;
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno += 2
#define UNINDENT indentno -= 2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{
	int i;
	for (i = 0; i < indentno; i++) {
		if (i % 4 == 0) {
			printf("|");
		}
		printf(" ");
	}
}

/* procedure printTree prints a syntax tree to the
 * listing file using indentation to indicate subtrees
 */
void printTree(TreeNode *tree)
{
	int i;
	INDENT;
	while (tree != NULL)
	{
		printSpaces();
		if (tree->nodekind == StmtK)
		{
			switch (tree->kind.stmt)
			{
			case IfK:
				printf("If\n");
				break;
			case IterK:
				printf("While\n");
				break;
			case AssignK:
				printf("Assign\n");
				break;
			case IfElseK:
				printf("If-Else\n");
				break;
			case RetK:
				printf("Return\n");
				break;
			case AtivK:
				printf("Chamada Funcao: %s\n", tree->attr.name);
				break;
			case CompostK:
				printf("Sequencia de Statements\n");
				break;
			default:
				printf("Unknown StmtNode kind\n");
				break;
			}
		}
		else if (tree->nodekind == ExpK)
		{
			switch (tree->kind.exp)
			{
			case OpK:
				printf("Op: ");
				printToken(tree->attr.op, "\0");
				break;
			case ConstK:
				printf("Const: %s\n", tree->attr.name);
				break;
			case IdK:
				printf("Id: %s\n", tree->attr.name);
				break;
			case ArrayK:
				printf("Array: %s\n", tree->attr.name);
				break;
			default:
				printf("Unknown ExpNode kind\n");
				break;
			}
		}
		else if (tree->nodekind == DeclK)
		{
			switch (tree->kind.decl)
			{
			case FunK:
				if (tree->type)
					printf("Function Declaration: %s, type: Integer\n", tree->attr.name);
				else
					printf("Function Declaration: %s, type: Void\n", tree->attr.name);
				break;
			case VarK:
				printf("Variable Declaration: %s\n", tree->attr.name);
				break;
			case VarArrayK:
				printf("Var Array Declaration: %s\n", tree->attr.name);
				break;
			case ParamK:
				printf("Parameter Declaration: %s\n", tree->attr.name);
				break;
			case ParamArrayK:
				printf("Parameter Array Declaration: %s\n", tree->attr.name);
				break;
			default:
				printf("Unknown DeclNode kind\n");
				break;
			}
		}
		else
			printf("Unknown node kind\n");
		for (i = 0; i < MAXCHILDREN; i++)
			printTree(tree->child[i]);
		tree = tree->sibling;
	}
	UNINDENT;
}
