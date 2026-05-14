#include <stdio.h>
#include "declaration.h"

int main()
{
    do{
        print_order();
        search_files();//这个函数可以查询当前存在的文件，有一个全局的字符二维数组，里面有当前存在的文件名，可以通过下标获得文件名访问文件

        int n;
        scanf("%d",&n);
        while(getchar()!='\n');

        switch(n){
            case 1:{new_file();break;}
            case 2:{fun_2();break;}
            case 3:{fun_3();break;}
            case 4:{fun_1();break;}
            case 5:{fun_5();break;}
            case 6:{fun_6();break;}
            case 7:{fun_7();break;}
            case 8:{fun_8();break;}
            default:{printf("无效选项，请重新输入\n\n");continue;}
        }
        printf("\n");
    }while(1);
}

