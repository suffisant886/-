#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct SeqList {
	DataType*elem;
	int size;//ʵ�ʴ洢��С
	int capacity;//������С
}SL;

void seqListInit(SL *sl);//��ʼ��
void backInsert(SL *sl, DataType x);//β��
void printList(SL*sl);//
void backDelete(SL*sl);//βɾ
void checkSL(SL*sl);
void headInsert(SL* sl, DataType x);
void headDelete(SL* sl);
int FindList(SL* sl, DataType x);
void Insert(SL* sl, int pos, DataType x);
void Delete(SL* sl, int pos);
void DestoryList(SL*sl);
