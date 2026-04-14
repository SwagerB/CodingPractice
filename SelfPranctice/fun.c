#include "fun.h"
#include <stdio.h>

void InitList(SqList *L){
    L->length = 0;
}

int InsertList(SqList *L, int i, Elemtype e){
    if(i < 1 || i > L->length + 1){
        return 0; // 插入位置不合法
    }
    if(L->length >= MAXSIZE){
        return 0; // 顺序表已满
    }
    for(int j = L->length - 1; j >= i - 1; j--){
        L->data[j + 1] = L->data[j]; // 元素后移
    }
    L->data[i - 1] = e; // 插入元素
    L->length++; // 长度增加
    return 1; // 插入成功
}

void PrintList(SqList *L){
    for(int i = 0; i < L->length; i++){
        printf("%d ", L->data[i]);
    }
    printf("\n");
}
