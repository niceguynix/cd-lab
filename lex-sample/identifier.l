ID ([a-z0-9])+

%%
{ID} {printf("It is an Identifier\n");}
%%

int yywrap(void)
{
    return 1;
}

int main(){
    yylex();
    return 0;
}