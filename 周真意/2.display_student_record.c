#include <stdio.h>
#include "../declaration.h"
#include <string.h>

extern char existed_files[100][260];

void display_student_record()
{
    //输入文件名
    char str[260]={0};
    while(1){
        printf("请输入需要查看的文件:");
        scanf("%s",str);
        getchar();
        strcat(str,".txt");

    //判断文件存在性
        FILE* fp;
        fp=fopen(str,"r");
        if(!fp)printf("文件不存在或已打开!\n\n");
        else break;
    }


}
