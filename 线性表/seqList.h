#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct SeqList {
	DataType*elem;
	int size;//实际存储大小
	int capacity;//容量大小
}SL;

void seqListInit(SL *sl);//初始化
void backInsert(SL *sl, DataType x);//尾插
void printList(SL*sl);//
void backDelete(SL*sl);//尾删
void checkSL(SL*sl);
void headInsert(SL* sl, DataType x);
void headDelete(SL* sl);
int FindList(SL* sl, DataType x);
void Insert(SL* sl, int pos, DataType x);
void Delete(SL* sl, int pos);
void DestoryList(SL*sl);
