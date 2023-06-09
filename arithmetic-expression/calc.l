%{
#include "y.tab.h"
#include <stdlib.h>
void yyerror(char *);
%}

%%
[a-z] {return VARIABLE;}
[0-9]+ {return INTEGER;}
[-+()=/*\n] { return *yytext; }
[ \t] ; /* skip whitespace */
. yyerror("Unknown character");
%%

int yywrap(void) {
    return 1;
}