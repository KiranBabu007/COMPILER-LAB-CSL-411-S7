%{#include<stdio.h>
#include<stdlib.h>
%}

%token NUMBER ID NL

%left '-''+'
%left '*''/'

%%
stmt:exp NL {printf("valid"); exit(0);};
exp: exp '+' exp {} | exp '-' exp | ID 


%%