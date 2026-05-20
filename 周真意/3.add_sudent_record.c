#include <stdio.h>
#include "../declaration.h"
#include <string.h>
#include <stdlib.h>
#define INTV 10

int check_int(char* p);
int trans_int(char* p);
extern char existed_files[100][260];

void add_student_record()
{
    //打印文件列表
    if(!existed_files[0][0]){
        printf("当前暂无文件，请新建文件!");
        return;
    }
    else {
        for(int i=0;existed_files[i][0];i++){
            int len;
            char* p=strstr(existed_files[i],".txt");
            len=p-existed_files[i];
            printf("%.*s\n",len,existed_files[i]);
        }
    }


    stu_info stu={.average=-2};
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

            //读取当前记录序号
            char char_seq[10]={0};
            fseek(fp,-13*INTV+1,SEEK_END);
            fscanf(fp,"%s",char_seq);
            if(atoi(char_seq))stu.sequence=atoi(char_seq)+1;
            else stu.sequence=1;
            fclose(fp);
            break;
        }
    }


    while(1){
        //获取学生信息
        int status_code=0;
        char* p=0;

        //输入姓名
        do{
            printf("请输入学生姓名:");
            while(getchar()!='\n');
            fgets(stu.name,19,stdin);
            //判断用户是否返回
            if(!strcmp(stu.name,"b"))return;

            if(!strchr(stu.name,'\n')||stu.name[0]=='\n'){
                printf("输入格式错误！\n");
                status_code=0;
            }
            else status_code=1;
        }while(!status_code);
        p=stu.name;
        while(1){
            if(*p!='\n')p++;
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
        p=stu.student_number;
        while(1){
            if(*p!='\n')p++;
            else {*p='\0';break;}
        }

        //输入性别
        do{
            printf("请输入学生性别:");
            fgets(stu.gender,4,stdin);
            if(!strchr(stu.gender,'\n')||stu.gender[0]=='\n'){
                printf("输入格式错误！\n");
                while(getchar()!='\n');
                status_code=0;
            }
            else status_code=1;
        }while(!status_code);
        p=stu.gender;
        while(1){
            if(*p!='\n')p++;
            else {*p='\0';break;}
        }

        //输入成绩
        while(1){
            char score[100]={0};
            do{
                printf("请输入学生成绩（按照语文、数学、英语、物化生、政史地顺序，中间用空格隔开，不存在的填\"-1\"）:\n");
                fgets(score,40,stdin);
                if(!strchr(score,'\n')||!check_int(str)){
                    printf("输入格式错误！\n");
                    while(getchar()!='\n');
                    status_code=0;
                }
                else status_code=1;
            }while(!status_code);
            p=score;
            while(1){
                if(*p!='\n')p++;
                else {*p='\0';break;}
            }
            //分割获取成绩
            int* q=&stu.Chinese,status=1;
            p=strtok(score," ");
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
        fprintf(fp,"%-*s",INTV,stu.name);
        fprintf(fp,"%-*d",INTV,stu.sequence++);
        fprintf(fp,"%-*s",INTV,stu.student_number);
        fprintf(fp,"%-*s",INTV,stu.gender);

        int *q=&stu.Chinese;
        for(int i=0;i<9;i++)fprintf(fp,"%-*d",INTV,*q++);
        fprintf(fp,"%-*s\n",INTV,"未处理");
        fclose(fp);


        printf("学生记录添加成功!继续添加，或按b返回");
    }
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



