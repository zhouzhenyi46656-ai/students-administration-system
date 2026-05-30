#include <stdio.h>
#include <string.h>
#include "../declaration.h"

int check_input(char* p)
{
    if(!strchr(p,'\n')||p[0]=='\n'){
        printf("ÊäÈë¸ñÊ½´íÎó£¡\n");
        while(getchar()!='\n');
        return 0;
    }
    else {
        p[strlen(p)-1]='\0';
        return 1;
    }

}
