#include <stdio.h>
#include "../declaration.h"
#include <string.h>

extern char existed_files[100][260];

void new_file()
{
    int cnt;
    //输入文件名
    char str[40]={0},*fname=str;
    do{
        printf("%s","请输入文件名：");
        scanf("%s",fname);
        if(strlen(fname)>255){
            printf("文件名太长了！");
            continue;
        }
        strcat(fname,".txt");

    //检验文件是否存在
        cnt=0;
        while(existed_files[cnt++]){
            if(!strcmp(existed_files[cnt-1],fname)){
                printf("该文件已存在，是否覆盖：");

                char ans[2]={0};
                scanf("%s",ans);
                if(strcmp(ans,"是")){
                    cnt=-1;
                    break;
                }
                else {
                    cnt=-2;
                    break;
                }
            }
            else continue;
        }
    }while(cnt==-2);

    //新建文件
    FILE *fp;
    strcat(fname,".txt");
    fp=fopen(fname,"w");
    fclose(fp);
    printf("文件创建成功\n");
}
