#include <stdio.h>
#include "../declaration.h"

void print_order(){
    printf("%47s\n","学生成绩管理程序");
    printf("%s\n","菜单：");
    printf("%s","1.新建学生记录文件      ");
    printf("%s","2.显示学生记录          ");
    printf("%s","3.排序                  ");
    printf("%s\n","4.求平均值");
    printf("%s","5.筛选                  ");
    printf("%s","6.增加学生记录          ");
    printf("%s","7.查找学生记录          ");
    printf("%s\n","8.退出");
    printf("%s","请输入你的选择，并按enter确认：");
}
