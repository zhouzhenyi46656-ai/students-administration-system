#include <stdio.h>
#include "../declaration.h"
#include <string.h>

extern char existed_files[100][260];

void create_new_file()
{
    int cnt;
    //输入文件名
    char str[257]={0},*fname=str;
    do{
        while(1){
            printf("%s","请输入文件名：");
            fgets(fname,256,stdin);
            if(strchr(fname,'\n')==0){
                printf("文件名太长了！\n");
                while(getchar()!='\n');
                continue;
            }
            else {
                fname[strlen(fname)-1]='\0';
                break;
            }
        }
        strcat(fname,".txt");

    //检验文件是否存在
        cnt=0;
        while(existed_files[cnt++][0]!='\0'){
            if(!strcmp(existed_files[cnt-1],fname)){
                printf("该文件已存在，是否覆盖：");

                char ans[3]={0};
                scanf("%s",ans);
                getchar();
                if(!strcmp(ans,"是")){
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
    fp=fopen(fname,"w");
    fprintf(fp,"姓名      序号      学号      性别      语文      数学      英语      物理      化学      生物      历史      政治      地理      平均");
    fclose(fp);
    printf("文件创建成功\n");
}
