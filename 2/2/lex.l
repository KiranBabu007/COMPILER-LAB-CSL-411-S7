%{
#include <stdio.h>

int lc=1,wc=0,cc=0;


%}

%%

\n {lc++;wc++;}
[ \t] {wc++;}
[a-zA-Z] {cc++;}
\n\n    {return 0;}
.       {cc++;}

%%



int main() {
    yylex();
    printf("Lines %d \n Words %d\n Characters %d\n",lc,wc,cc);
    return 0;
}

int yywrap() {
    return 1;
}
