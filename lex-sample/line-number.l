%{
    int l=1;
%}

%%
.* {printf("%d\t%s",l++,yytext);}
%%

int yywrap(void)
{
    return 1;
}

int main(int argc,char *argv[])
{   
    yyin=fopen(argv[1],"r");
    yylex();
}
