ID [a-z]([a-z0-9])+

%%
{ID} {printf("It is an Identifier\n");}
.* {printf("Nope");}
%%

int yywrap(void)
{
    return 1;
}

int main(){
    yylex();
    return 0;
}