%{#include<stdio.h>
#include<stdlib.h>
int yylex();
void yyerror(char *msg);
%}
%token NUMBER ID NL
%left '-' '+'
%left '*' '/'
%%
stmt:exp NL {printf("%d",$1); exit(0);};
exp: exp '+' exp {$$=$1+$3;} 
| exp '-' exp  {$$=$1-$3;}
| ID  {$$=$1;} | NUMBER {$$=$1;} ;
%%

void yyerror(char *msg){
 printf("Pani Paali with %s",msg);
}

int main(){
    yyparse();
    return 0;
}