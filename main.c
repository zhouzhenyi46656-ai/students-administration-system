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
            case 1:{create_new_file();break;}
            case 2:{display_student_record(NULL);break;}
            case 3:{ranking();break;}
            case 4:{average();break;}
            case 5:{filter();break;}
            case 6:{add_student_record();break;}
            case 7:{search_();break;}
            case 8:{exit();break;}
            default:{printf("无效选项，请重新输入\n\n");continue;}
        }
        printf("\n");
    }while(1);
}

