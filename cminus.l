%{
#include "globals.h"
#include "util.h"
#include "scan.h"
/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];
char nextToken[MAXTOKENLEN+1];

FILE *f_out;


%}
/* Lexemas padrao */
LETRA [a-zA-Z]
DIGITO [0-9]

/* Espaco */
ESPACO [ \t]

/* Comentarios */
%x comentario

/* Erros */
%x erro
%%

"/""*"            { BEGIN(comentario); }
<comentario>.
<comentario>\n	  { lineno++; }
<comentario>"*/"  { BEGIN(INITIAL); }

else 			  { return ELSE; }
if				  { return IF; }
int				  { return INT; }
return 			  { return RETURN; }
void			  { return VOID; }
while			  { return WHILE; }

{DIGITO}+		  { return NUM; }
{LETRA}+     	  { return ID; }

"<"=              { return MENIG; }
"<"   			  { return MENOR; }
">"=			  { return MAIIG; }
">"				  { return MAIOR; }
==				  { return IGLIGL; }
!=				  { return DIF; }
=				  { return ATT; }
"+"				  { return SOM; }
"-"				  { return SUB; }
"*"				  { return MUL; }
"/"				  { return DIV; }
","				  { return VIRG; }
"{"				  { return ABCH; }
"}"				  { return FECCH; }
"["				  { return ABCO; }
"]"				  { return FCCO; }
;				  { return PEV; }
"("				  { return ABP; }
")"				  { return FCP;	}
{ESPACO}+         { /* ignora espaco em branco */ }
\n				  lineno++;

.                 { printf("[Erro - linha %d] Lexema não foi reconhecido: ", lineno);
                    ECHO;
                    BEGIN(erro);
                  }
<erro>^[" "\n\t]  ECHO;
<erro>\n		  { lineno++;
                    printf("\n");
                    BEGIN(INITIAL);
                    return ERROR;
                  }
<erro>{ESPACO}    { printf("\n");
                    BEGIN(INITIAL);
                    return ERROR;
                  }
%%


TokenType getToken(void)
{
    static int firstTime = TRUE;
    TokenType currentToken;
    if (firstTime) {
        firstTime = FALSE;
        lineno=1;
        yyin = source;
        yyout = listing;
        currentToken=yylex();
        strncpy(nextToken,yytext,MAXTOKENLEN);
        strncpy(tokenString,nextToken,MAXTOKENLEN);
    } else {
        strncpy(tokenString,nextToken,MAXTOKENLEN);
        currentToken = yylex();
        strncpy(nextToken,yytext,MAXTOKENLEN);
    }

    if (TraceScan) {
        fprintf(listing, "\t%d: ", lineno);
        printToken(currentToken,tokenString);
    }
    return currentToken;
}
