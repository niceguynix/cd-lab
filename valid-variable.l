%%
[a-zA-Z][A-Za-z0-9]* {printf("Valid Variable");}
.* {printf("Invalid Variable");}
%%

int yywrap(void)
{
    return 1;
}

int main(){
    yylex();
}