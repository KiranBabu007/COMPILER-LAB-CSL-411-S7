%{#include <stdio.h>

%}

%%
if|else|int|char|while  printf("KEYWORD:%s\n",yytext);
[0-9]+  printf("Number:%s\n",yytext);
[a-zA-Z][a-zA-Z0-9]*  printf("identifier:%s\n",yytext);
"="|"+"|"-"|"/"|"*"   printf("operator:%s\n",yytext);
[\t]*                 
.|[0-9][a-zA-Z]*      printf("Unknown Text:%s\n",yytext);
%%

int main(){
yylex();

return 0;
}

int yywrap(){
    return 1;
}




