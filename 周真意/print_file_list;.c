#include <stdio.h>
#include "../declaration.h"
#include <string.h>

extern char existed_files[100][260];

void print_file_list()
{
    if(!existed_files[0][0]){
        printf("\n当前暂无文件，请新建文件!\n");
        return;
    }
    else {
        printf("\n当前文件夹下的文件:\n");
        for(int i=0;existed_files[i][0];i++){
            int len;
            char* p=strstr(existed_files[i],".txt");
            len=p-existed_files[i];
            printf("%.*s\n",len,existed_files[i]);
        }
    printf("\n");
    }
}

