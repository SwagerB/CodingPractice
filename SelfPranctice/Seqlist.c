#include "fun.h"
#include <stdio.h>

int main()
{
    SqList list;
    InitList(&list);
    for (int i = 1; i <= 10; i++)   // 位置从 1 开始，插入值 i
    {
        InsertList(&list, i, i);
    }
    PrintList(&list);
    return 0;
}