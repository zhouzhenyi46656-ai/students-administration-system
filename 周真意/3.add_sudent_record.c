#include <stdio.h>
#include "../declaration.h"
#include <string.h>
#include <stdlib.h>

int check_int(char* p);
int trans_int(char* p);
extern existed_files[100][260];

void add_student_record()
{
    //打印文件列表
    if(!existed_files[0][0]){
        printf("当前暂无文件，请新建文件,按b返回:");
        return;
    }
    else {
        for(int i=0;!existed_files[i][0];i++){
            int len;
            char* p=strstr(existed_files[i],".txt");
            len=p-existed_files[i];
            printf("%.*s\n",len,existed_files[i]);
        }
    }


    FILE* fp;
    char str[255]={0};
    //检查文件是否存在
    while(1){
        printf("请选择添加记录的文件:");
        scanf("%s",str);
        if(!strcmp(str,"b"))return;
        strcat(str,".txt");
        fp=fopen(str,"r");
        if(!fp)printf("文件不存在!请检查输入或新创建文件,按b返回:");
        else {
            fclose(fp);
            break;
        }
    }


    do{
        //获取学生信息
        stu_info stu={.average=-2};
        int status_code=0;
        char* p=0;

        //输入姓名
        do{
            printf("请输入学生姓名:");
            fgets(stu.name,19,stdin);
            //判断用户是否返回
            if(strcmp(stu.name,"b"))return;

            if(!strchr(stu.name,'\n')||stu.name[0]=='\n'){
                printf("输入格式错误！\n");
                while(getchar()!='\n');
                status_code=0;
            }
            else status_code=1;
        }while(!status_code);
        while(1){
            p=stu.name;
            if(*p=='\n')p++;
            else {*p='\0';break;}
        }

        //输入学号
        do{
            printf("请输入学生学号:");
            fgets(stu.student_number,19,stdin);
            if(!strchr(stu.student_number,'\n')||stu.student_number[0]=='\n'){
                printf("输入格式错误！\n");
                while(getchar()!='\n');
                status_code=0;
            }
            else status_code=1;
        }while(!status_code);
        while(1){
            p=stu.student_number;
            if(*p=='\n')p++;
            else {*p='\0';break;}
        }

        //输入性别
        do{
            printf("请输入学生性别:");
            fgets(stu.gender,2,stdin);
            if(!strchr(stu.gender,'\n')||stu.gender[0]=='\n'){
                printf("输入格式错误！\n");
                while(getchar()!='\n');
                status_code=0;
            }
            else status_code=1;
        }while(!status_code);
        while(1){
            p=stu.gender;
            if(*p=='\n')p++;
            else {*p='\0';break;}
        }

        //输入成绩
        while(1){
            char str[100]={0};
            do{
                printf("请输入学生成绩（按照语文、数学、英语、物化生、政史地顺序，中间用空格隔开，不存在的填\"-1\"）:\n");
                fgets(str,40,stdin);
                if(!strchr(str,'\n')||!check_int(str)){
                    printf("输入格式错误！\n");
                    while(getchar()!='\n');
                    status_code=0;
                }
                else status_code=1;
            }while(!status_code);
            while(1){
                p=str;
                if(*p=='\n')p++;
                else {*p='\0';break;}
            }
            //分割获取成绩
            int* q=&stu.Chinese,status=1;
            p=strtok(str," ");
            *q++=trans_int(p);
            while(p){
                p=strtok(NULL," ");
                if(p!=NULL){
                    *q++=trans_int(p);
                    status++;
                }
            }
            //判断成绩输入是否合法
            if(status==9)break;
            else printf("输入格式错误!\n");
        }


        //写入文件
        fp=fopen(str,"a");





        printf("学生记录添加成功!继续添加，或按b返回");
    }while(1);
}

int check_int(char* p)
{
    char *end;
    long n=strtol(p,&end,10);
    if(end==p)return 0;
    else return n;
}

int trans_int(char* p)
{
    char *end;
    long n=strtol(p,&end,10);
    if(end==p)return -2;
    else return (int)n;
}



