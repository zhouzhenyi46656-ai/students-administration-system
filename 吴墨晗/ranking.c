#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../declaration.h"

int check_int(char* p);
int trans_int(char* p);


void ranking()
{
    if(!existed_files[0][0]){
        printf("当前暂无文件，请新建文件\n");
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


    FILE* fp;
    char str[255]={0};
    //检查文件是否存在
    while(1){
        printf("请选择要排序的文件:");
        scanf("%s",str);
        strcat(str,".txt");
        fp=fopen(str,"r");
        if(!fp)
        {
         printf("文件不存在!请检查输入或新创建文件,按b返回:");
         if(getchar()=='b'))return;
        }
        else {
            fclose(fp);
            break;
        }
    }

    stu_info stu_arr[100];
    int count=0;int pcs;
    fp=fopen(str,"r");
    while((pcs=fscanf(fp,"%s %s %s %d %d %d %d %d %d %d %d %d",
                 &stu_arr[count].name,
                 &stu_arr[count].gender,
                 &stu_arr[count].student_number,
                 &stu_arr[count].Chinese,
                 &stu_arr[count].Math,
                 &stu_arr[count].English,
                 &stu_arr[count].Physics,
                 &stu_arr[count].Chemistry,
                 &stu_arr[count].Biology,
                 &stu_arr[count].Politics,
                 &stu_arr[count].History,
                 &stu_arr[count].Geometry))==12)
    {
        count++;
    }
    fclose(fp);

    if(count==0)
    {
        printf("文件中暂无学生数据，无法排序！\n");
        printf("按b返回：");
        if(getchar()=='b'))return;
    }
    else if(pcs!=0||pcs!=12)
    {
        printf("输入学生信息不完整！请检查后重试...\n");
        if(getchar()=='b'))return;
    }
    else
    {
        int scope=0,order=0,subject=0;
        printf("请选择排序模式：\n");
        printf("1.从大到小\n");
        printf("2.从小到大\n");
        printf("请输入你的选择，并按enter确认：\n");
        scanf("%d",&order);
        if(order!=1&&order!=2){printf("无效选项！");return;}
        printf("请选择排序人群：\n");
        printf("1.仅男生\n");
        printf("2.仅女生\n");
        printf("3.全体学生\n");
        printf("请输入你的选择，并按enter确认：\n");
        scanf("%d",&scope);
        if(scope!=1&&scope!=2&&scope!=3){printf("无效选项！");return;}
        printf("请选择排序科目：\n");
        printf("1.语文\n");
        printf("2.数学\n");
        printf("3.英语\n");
        printf("4.物理\n");
        printf("5.化学\n");
        printf("6.生物\n");
        printf("7.历史\n");
        printf("8.政治\n");
        printf("9.地理\n");
        printf("10.全部科目\n");
        printf("请输入你的选择，并按enter确认：\n");
        scanf("%d",&subject);
        for(int ii=1;ii<11;ii++)
        {
            int vrf=0;
            if(subject==ii){vfy=1;break;}
        }
        if(!vrf){printf("无效选项！");return;}
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


