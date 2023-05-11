%{
#include<stdio.h>
int e,k,c,d,i,s;
%}

%%
include|void|main|int|float|double|scanf|char|printf { i++;}
[a-z][a-zA-Z0-9]* { k++;}
[0-9]* {e++;}
[+|-|*|/|=]* { c++;}
[;|:|(|)|{|}|"|'|,|\n|\t]* { d++;}
[#|<|>|%]* {s++;}
%%

int main(void)
{
    yyin=fopen("code.txt","r");
    yylex();
    printf("\nidentifier %d\n",k);
    printf("Symbols %d\n",s);
    printf("digits %d\n",e);
    printf(" Operator %d\n",c);
    printf(" keywords %d\n",i);
    printf("delimeter %d\n",d);
    return 0;
}

int yywrap()
{
    return 1;
}
