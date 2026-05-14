#include <stdio.h>
#include "declaration.h"

int main()
{
    do{
        print_order();
        search_files();

        int n;
        scanf("%d",&n);
        switch(n){
            case 1:{new_file();break;}
            case 2:{fun_2();break;}
            case 3:{fun_3();break;}
            case 4:{fun_1();break;}
            case 5:{fun_5();break;}
            case 6:{fun_6();break;}
            case 7:{fun_7();break;}
            case 8:{fun_8();break;}
        }
    }while(1);
}

