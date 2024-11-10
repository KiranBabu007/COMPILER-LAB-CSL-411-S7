%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(char *s);
%}

%token ID NL

%%
stmt: exp NL { printf("Valid expression\n"); exit(0); }
    ;

exp: ID
    ;

%%

int main() {
    printf("Enter expression: ");
    if (yyparse() == 0) {
        return 0;  // Successful parsing
    } else {
        return 1;  // Parsing error
    }
}

void yyerror(char *msg) {
    printf("Invalid string\n");
}
