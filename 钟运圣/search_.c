#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../declaration.h"

extern char existed_files[100][260];

void search_()
{
    // ==================== 第1部分：显示现有文件 ====================
    if(!existed_files[0][0]){
        printf("当前暂无文件，请新建文件\n");
        return;
    }
    else {
        for(int i=0; existed_files[i][0]; i++){
            int len;
            char* p = strstr(existed_files[i], ".txt");
            if(p == NULL) continue;
            len = p - existed_files[i];
            printf("%.*s\n", len, existed_files[i]);
        }
    }

    // ==================== 第2部分：选择要查找的文件 ====================
    FILE* fp;
    char filename[255] = {0};

    while(1){
        printf("请选择要查找的文件:");
        scanf("%s", filename);
        strcat(filename, ".txt");
        fp = fopen(filename, "r");
        if(!fp)
        {
            printf("文件不存在!请检查输入或新创建文件,按b返回:\n");
            while(1){
                char ch = getchar();
                if(ch == 'b') return;
                if(ch == '\n') break;
            }
        }
        else {
            fclose(fp);
            break;
        }
    }

    // ==================== 第3部分：读取所有学生数据 ====================
    fp = fopen(filename, "r");
    if(!fp) {
        printf("文件打开失败！\n");
        return;
    }

    // 跳过第一行表头
    char header[500];
    fgets(header, sizeof(header), fp);

    stu_info stu_arr[100];
    int count = 0;

    while(1)
    {
        // 临时变量
        char temp_name[20];
        int temp_sequence;
        char temp_student_number[20];
        char temp_gender[4];
        int temp_Chinese, temp_Math, temp_English;
        int temp_Physics, temp_Chemistry, temp_Biology;
        int temp_History, temp_Politics, temp_Geometry;
        char temp_average[20];

        // 按文件顺序读取
        int ret = fscanf(fp, "%s", temp_name);
        if(ret == EOF) break;

        fscanf(fp, "%d", &temp_sequence);
        fscanf(fp, "%s", temp_student_number);
        fscanf(fp, "%s", temp_gender);
        fscanf(fp, "%d", &temp_Chinese);
        fscanf(fp, "%d", &temp_Math);
        fscanf(fp, "%d", &temp_English);
        fscanf(fp, "%d", &temp_Physics);
        fscanf(fp, "%d", &temp_Chemistry);
        fscanf(fp, "%d", &temp_Biology);
        fscanf(fp, "%d", &temp_History);
        fscanf(fp, "%d", &temp_Politics);
        fscanf(fp, "%d", &temp_Geometry);
        fscanf(fp, "%s", temp_average);

        // 按结构体顺序赋值
        stu_arr[count].sequence = temp_sequence;
        strcpy(stu_arr[count].name, temp_name);
        strcpy(stu_arr[count].gender, temp_gender);
        strcpy(stu_arr[count].student_number, temp_student_number);
        stu_arr[count].Chinese = temp_Chinese;
        stu_arr[count].Math = temp_Math;
        stu_arr[count].English = temp_English;
        stu_arr[count].Physics = temp_Physics;
        stu_arr[count].Chemistry = temp_Chemistry;
        stu_arr[count].Biology = temp_Biology;
        stu_arr[count].History = temp_History;
        stu_arr[count].Politics = temp_Politics;
        stu_arr[count].Geometry = temp_Geometry;

        // 平均分处理
        if(strcmp(temp_average, "未处理") == 0) {
            stu_arr[count].average = 0;
        } else {
            stu_arr[count].average = atoi(temp_average);
        }

        count++;
        if(count >= 100) break;
    }
    fclose(fp);

    // 检查是否有数据
    if(count == 0) {
        printf("文件中暂无学生数据，无法查找！\n");
        return;
    }

    // ==================== 第4部分：用户输入查找条件 ====================
    int search_type = 0;
    char search_key[50] = {0};

    printf("\n请选择查找方式：\n");
    printf("1.按姓名查找\n");
    printf("2.按学号查找\n");
    printf("请输入你的选择：");
    scanf("%d", &search_type);

    if(search_type != 1 && search_type != 2) {
        printf("无效选项！\n");
        return;
    }

    printf("请输入要查找的%s：", (search_type == 1) ? "姓名" : "学号");
    scanf("%s", search_key);

    // ==================== 第5部分：执行查找并输出 ====================
    printf("\n========== 查找结果 ==========\n");
    int found_count = 0;

    for(int i = 0; i < count; i++) {
        int match = 0;

        if(search_type == 1) {
            // 按姓名查找（忽略大小写）
            if(strcmp(stu_arr[i].name, search_key) == 0) {
                match = 1;
            }
        } else {
            // 按学号查找
            if(strcmp(stu_arr[i].student_number, search_key) == 0) {
                match = 1;
            }
        }

        if(match) {
            found_count++;

            // 输出该学生的所有信息
            printf("\n--- 第 %d 条匹配记录 ---\n", found_count);
            printf("姓名：%s\n", stu_arr[i].name);
            printf("序号：%d\n", stu_arr[i].sequence);
            printf("学号：%s\n", stu_arr[i].student_number);
            printf("性别：%s\n", stu_arr[i].gender);
            printf("语文成绩：%d\n", stu_arr[i].Chinese);
            printf("数学成绩：%d\n", stu_arr[i].Math);
            printf("英语成绩：%d\n", stu_arr[i].English);
            printf("物理成绩：%d\n", stu_arr[i].Physics);
            printf("化学成绩：%d\n", stu_arr[i].Chemistry);
            printf("生物成绩：%d\n", stu_arr[i].Biology);
            printf("历史成绩：%d\n", stu_arr[i].History);
            printf("政治成绩：%d\n", stu_arr[i].Politics);
            printf("地理成绩：%d\n", stu_arr[i].Geometry);

            // 计算并显示平均分
            if(stu_arr[i].average == 0) {
                int sum = stu_arr[i].Chinese + stu_arr[i].Math + stu_arr[i].English +
                          stu_arr[i].Physics + stu_arr[i].Chemistry + stu_arr[i].Biology +
                          stu_arr[i].History + stu_arr[i].Politics + stu_arr[i].Geometry;
                int avg = sum / 9;
                printf("平均分：%d\n", avg);
            } else {
                printf("平均分：%d\n", stu_arr[i].average);
            }
        }
    }

    if(found_count == 0) {
        printf("未找到匹配的学生，请检查输入的%s是否正确\n",
               (search_type == 1) ? "姓名" : "学号");
    } else {
        printf("\n共找到 %d 条匹配记录\n", found_count);
    }

    printf("\n查找完成！\n");
}
