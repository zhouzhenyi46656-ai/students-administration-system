#include <stdio.h>
#include "../declaration.h"
#include <windows.h>

char existed_files[100][260];

void search_files()
{
    //第一次查找
    int cnt=0;
    WIN32_FIND_DATA findData;
    HANDLE hFind;
    hFind=FindFirstFile("*.txt",&findData);
    if(hFind==INVALID_HANDLE_VALUE){
        return;
    }

    //后续查找
    do{
        strcpy(existed_files[cnt++],findData.cFileName);
    }while(FindNextFile(hFind,&findData));
    FindClose(hFind);
    return;
}
