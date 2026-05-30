#include <stdio.h>
#include "../declaration.h"
#include <string.h>

extern char existed_files[100][260];

void display_student_record(char* sp)
{
    //输入文件名
    char str[260]={0};
    FILE* fp;
    while(1){
        if(!sp){
            do{
                print_file_list();
                printf("请输入需要查看的文件:");
                fgets(str,256,stdin);
            }while(!check_input(str));
            strcat(str,".txt");
        }
        else strcpy(str,sp);

    //判断文件存在性
        fp=fopen(str,"r");
        if(!fp)printf("文件不存在或已打开!\n\n");
        else {
            printf("\n%s\n",str);
            break;
        }
    }

    //显示文件
    char s[1000];
    fp=fopen(str,"r");
    while(fgets(s,999,fp)){
        printf("%s",s);
    }
}

