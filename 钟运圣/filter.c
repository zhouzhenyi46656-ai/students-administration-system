#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../declaration.h"

extern char existed_files[100][260];

void filter()
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

    // ==================== 第2部分：选择要筛选的文件 ====================
    FILE* fp;
    char str[255] = {0};

    while(1){
        printf("请选择要筛选的文件:");
        scanf("%s", str);
        strcat(str, ".txt");
        fp = fopen(str, "r");
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

    // ==================== 第3部分：读取学生数据（正确方式） ====================
    fp = fopen(str, "r");
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

        // 按你的结构体顺序赋值
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

        // 平均分处理：如果"未处理"则暂时存0，否则转整数
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
        printf("文件中暂无学生数据，无法筛选！\n");
        return;
    }

    // ==================== 第4部分：筛选条件选择 ====================
    int subject = 0;
    int compare_mode = 0;
    int threshold = 0;
    int use_average = 0;

    printf("\n请选择筛选依据：\n");
    printf("1.按单科成绩筛选\n");
    printf("2.按平均分筛选\n");
    printf("请输入你的选择：");
    scanf("%d", &use_average);

    if(use_average == 2) {
        printf("\n请选择比较方式：\n");
        printf("1.大于等于指定分数\n");
        printf("2.小于等于指定分数\n");
        printf("请输入你的选择：");
        scanf("%d", &compare_mode);
        if(compare_mode != 1 && compare_mode != 2) {
            printf("无效选项！\n");
            return;
        }
        printf("请输入阈值分数：");
        scanf("%d", &threshold);
    }
    else if(use_average == 1) {
        printf("\n请选择科目：\n");
        printf("1.语文   2.数学   3.英语   4.物理   5.化学\n");
        printf("6.生物   7.历史   8.政治   9.地理\n");
        printf("请输入你的选择：");
        scanf("%d", &subject);

        int vrf = 0;
        for(int ii = 1; ii <= 9; ii++) {
            if(subject == ii) { vrf = 1; break; }
        }
        if(!vrf) {
            printf("无效选项！\n");
            return;
        }

        printf("\n请选择比较方式：\n");
        printf("1.大于等于指定分数\n");
        printf("2.小于等于指定分数\n");
        printf("请输入你的选择：");
        scanf("%d", &compare_mode);
        if(compare_mode != 1 && compare_mode != 2) {
            printf("无效选项！\n");
            return;
        }

        printf("请输入阈值分数：");
        scanf("%d", &threshold);
    }
    else {
        printf("无效选项！\n");
        return;
    }

    // ==================== 第5部分：计算平均分 ====================
    int avg_scores[100];
    for(int i = 0; i < count; i++) {
        int sum = stu_arr[i].Chinese + stu_arr[i].Math + stu_arr[i].English +
                  stu_arr[i].Physics + stu_arr[i].Chemistry + stu_arr[i].Biology +
                  stu_arr[i].History + stu_arr[i].Politics + stu_arr[i].Geometry;
        avg_scores[i] = sum / 9;
    }

    // ==================== 第6部分：执行筛选并输出 ====================
    printf("\n========== 筛选结果 ==========\n");
    int found_count = 0;

    for(int i = 0; i < count; i++) {
        int score_to_compare = 0;

        if(use_average == 2) {
            score_to_compare = avg_scores[i];
        }
        else {
            switch(subject) {
                case 1: score_to_compare = stu_arr[i].Chinese; break;
                case 2: score_to_compare = stu_arr[i].Math; break;
                case 3: score_to_compare = stu_arr[i].English; break;
                case 4: score_to_compare = stu_arr[i].Physics; break;
                case 5: score_to_compare = stu_arr[i].Chemistry; break;
                case 6: score_to_compare = stu_arr[i].Biology; break;
                case 7: score_to_compare = stu_arr[i].History; break;
                case 8: score_to_compare = stu_arr[i].Politics; break;
                case 9: score_to_compare = stu_arr[i].Geometry; break;
                default: break;
            }
        }

        int match = 0;
        if(compare_mode == 1) {
            match = (score_to_compare >= threshold);
        } else if(compare_mode == 2) {
            match = (score_to_compare <= threshold);
        }

        if(match) {
            found_count++;
            printf("姓名：%s\t", stu_arr[i].name);
            if(use_average == 2) {
                printf("平均分：%d\n", score_to_compare);
            } else {
                switch(subject) {
                    case 1: printf("语文：%d\n", score_to_compare); break;
                    case 2: printf("数学：%d\n", score_to_compare); break;
                    case 3: printf("英语：%d\n", score_to_compare); break;
                    case 4: printf("物理：%d\n", score_to_compare); break;
                    case 5: printf("化学：%d\n", score_to_compare); break;
                    case 6: printf("生物：%d\n", score_to_compare); break;
                    case 7: printf("历史：%d\n", score_to_compare); break;
                    case 8: printf("政治：%d\n", score_to_compare); break;
                    case 9: printf("地理：%d\n", score_to_compare); break;
                }
            }
        }
    }

    if(found_count == 0) {
        printf("没有找到符合条件的学生\n");
    } else {
        printf("\n共找到 %d 名学生\n", found_count);
    }

    printf("\n筛选完成！\n");
}
