%{

#include "y.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9_]*   return ID;
\n      return NL;
.       {return yytext[0];}


%%