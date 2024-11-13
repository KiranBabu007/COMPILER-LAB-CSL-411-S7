%{
#include<stdio.h>
#include<stdlib.h>

int yylex();
void yyerror(char *msg);
%}


%token ID NL

%%

stmt: exp NL  {printf("Coreeectttt"); exit(0);};
exp : ID ;

%%

int main(){
    yyparse();
    return 0;
}

void yyerror(char *msg){
    printf("error");
   
}