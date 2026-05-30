//函数声明
void create_new_file();
void display_student_record(char* sp);
void add_student_record();
void print_order();
void search_files();
int check_input(char* p);
void print_file_list();

void ranking();
void average();
void fun_5();
void fun_7();
void fun_8();

//存储结构体声明
typedef struct student_information{
    int sequence;
    char name[20];
    char gender[4];
    char student_number[20];
    int Chinese;
    int Math;
    int English;
    int Physics;
    int Chemistry;
    int Biology;
    int History;
    int Politics;
    int Geometry;
    int average;
}stu_info;



