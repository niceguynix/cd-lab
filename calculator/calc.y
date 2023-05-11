%{
#include<stdio.h>
void yyerror(char *);
int yylex(void);
int sym[260],i=0;
%}

%token INTEGER VARIABLE
%left '+' '-'
%left '*' '/'

%%
program:
program statement '\n' 
| /* NULL */
;
statement:
expression {printf("%d\n",$1);}
| VARIABLE '=' expression {/* printf ("Node = %d\n",$3);*/ sym[$1] = $3;}
;
expression:
INTEGER
| VARIABLE { /*printf("Value of Variable %d %d\n",$$,$1);print(sym);*/$$ = sym[$1]; }
| expression '+' expression { $$ = $1 + $3; }
| expression '-' expression {$$ = $1 - $3; }
| expression '*' expression { $$ = $1 * $3; }
| expression '/' expression { $$ = $1 / $3; }
| '(' expression ')' { $$ = $2; }
;
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
int main(void) {
    yyparse();
}
