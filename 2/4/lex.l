%{
#include<stdio.h>
int vc=0,cc=0;
%}


%%
"a"|"e"|"i"|"o"|"u"  vc++;
[a-zA-Z]     cc++;
\n\n       return 0;
%%

int main(){
    yylex();
    printf("vowels:%d \t consonants:%d",vc,cc);
    return 0;
}

int yywrap(){
    return 0;
}

