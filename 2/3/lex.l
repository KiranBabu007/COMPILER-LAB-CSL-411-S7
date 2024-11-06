%{
#include <stdio.h>

char string[100];
%}

%%

\n strcat(string,"\n");
abc strcat(string,"ABC");
\n\n return 0;
.   strcat(string,yytext);

%%



int main() {
    yylex();
    printf("String:%s",string);
    return 0;
}

int yywrap() {
    return 1;
}
