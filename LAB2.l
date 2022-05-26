LEX PROGRAM


%{
#include "y.tab.h"
%}
%%
a {return A;}
b {return B;}
"\n" {return ENTER;}
. {printf("invalid input");exit(0);}
%% 
