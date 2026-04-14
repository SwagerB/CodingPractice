#define MAXSIZE 100

typedef int Elemtype;

typedef struct{
    Elemtype data[MAXSIZE];
    int length;
}SqList;

void InitList(SqList *L);

int InsertList(SqList *L, int i, Elemtype e);

void PrintList(SqList *L);

