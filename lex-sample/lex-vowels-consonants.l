%{
int count=0,count2=0;
%}

%%
"a"|"e"|"i"|"o"|"u" {++count; printf("\nVowel: %d",count);}
[a-z] {++count2; printf("\nConsonants: %d",count2);}
%%

int yywrap(void){
    return 1;
}

int main(){
        yylex();
}
