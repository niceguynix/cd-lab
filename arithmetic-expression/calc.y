%{
#include<stdio.h>
void yyerror(char *);
int yylex(void);
%}

%token INTEGER VARIABLE
%left '+' '-'
%left '*' '/'

%%
program:
program statement '\n' {printf("Valid\n") ;}
| /* NULL */
;
statement:
expression
| VARIABLE '=' expression 
;
expression:
INTEGER
| VARIABLE 
| expression '+' expression 
| expression '-' expression 
| expression '*' expression 
| expression '/' expression 
| '(' expression ')'
;
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
int main(void) {
    yyparse();
}
