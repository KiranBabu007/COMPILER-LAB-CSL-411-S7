%{
#include<stdio.h>
#include<stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token DIGIT ID NL
%left '-''+'
%left '*''/'

%%
stmt: exp NL  {printf("valid aane"); exit(0);}
exp:  exp '+' exp | exp '-' exp |ID|DIGIT|exp '*' exp|exp '/' exp ;
%%

void yyerror(const char *s){
    printf("Invalid String");
}

int main(){
    printf("Enter the exp:");
    yyparse();
    return 0;
}

