#include "seqList.h"

void test()
{
	SL sl;
	int res;
	seqListInit(&sl);
	backInsert(&sl, 1);
	backInsert(&sl, 2);
	backInsert(&sl, 3);
	backInsert(&sl, 4);
	backInsert(&sl, 5);
	printf("插入之前：\n");
	printList(&sl);
	backDelete(&sl);
	printf("尾删之后：\n");
	printList(&sl);
	printf("头插之后：\n");
	headInsert(&sl, 10);
	headInsert(&sl, 20);
	headInsert(&sl, 30);
	printList(&sl);
	printf("头删之后：\n");
	headDelete(&sl);
	printList(&sl);
	res=FindList(&sl, 10);
	printf("10的位置是%d\n", res);
	Insert(&sl, 3, 8);
	printf("在第3个位置插入8：\n");
	printList(&sl);
	Delete(&sl, 3);
	printf("删除第3个位置:\n");
	printList(&sl);
	DestoryList(&sl);

}
int main() {
	
	test();
	return 0;
}






void seqListInit(SL* sl){
	sl->elem = NULL;
	sl->capacity = sl->size = 0;//当然这里也可以开辟n个
}
void backInsert(SL *sl, DataType x){
	//扩容操作
	if (sl->capacity == sl->size) {
		int newcapicity = sl->capacity == 0 ? 4 : sl->capacity * 2;//两种情况
		DataType *tep = (DataType*)realloc(sl->elem, newcapicity*(sizeof(DataType)));
		if (tep == NULL) {
			printf("开辟失败了\n");
			exit(-1);
		}
		sl->elem = tep;
		sl->capacity = newcapicity;
	}
	sl->elem[sl->size] = x;
	sl->size++;
}
void printList(SL*sl) {
	for (int i = 0; i < sl->size; i++) {
		printf("%d ", sl->elem[i]);
	}
	printf("\n");
}
void backDelete(SL*sl) {
	int back = sl->size - 1;
	if (sl->size > 0) {//防止越界
		sl->elem[back] = 0;
		sl->size--;
	}
}
void checkSL(SL*sl) {
	if (sl->capacity == sl->size) {
		int newcapicity = sl->capacity == 0 ? 4 : sl->capacity * 2;//两种情况
		DataType *tep = (DataType*)realloc(sl->elem, newcapicity*(sizeof(DataType)));
		if (tep == NULL) {
			printf("开辟失败了\n");
			exit(-1);
		}
		sl->elem = tep;
		sl->capacity = newcapicity;
	}
}
void headInsert(SL* sl, DataType x) {
	checkSL(sl);
	int end = sl->size - 1;
	while (end >= 0) {
		sl->elem[end + 1] = sl->elem[end];
		end--;
	}
	sl->elem[0] = x;
	sl->size++;
}
void headDelete(SL* sl) {
	int start = 1;
	if (sl->size > 0) {
		while (start < sl->size) {
			sl->elem[start - 1] = sl->elem[start];
			start++;
		}
	}
	sl->size--;
}
int FindList(SL* sl, DataType x) {
	if (sl->size <= 0) {
		printf("都没有表，别找了！\n");
	}
	else {
		int point = 0;
		while (point<sl->size)
		{
			if (sl->elem[point] == x)
				return point;
			point++;
		}
	}
}
void Insert(SL* sl, int pos,DataType x) {
	if (pos>sl->size || pos<0) {
		printf("插入位置无效！\n");
		return;
	}
	int end = sl->size - 1;
	while (end>=pos)
	{
		sl->elem[end + 1] = sl->elem[end];
		end--;
	}
	sl->elem[pos] = x;
	sl->size++;
}
void Delete(SL* sl, int pos) {
	if (pos>sl->size || pos<0) {
		printf("删除位置无效！\n");
	}
	int start = pos + 1;
	while (start<sl->size)
	{
		sl->elem[start - 1] = sl->elem[start];
		start++;
	}
	sl->size--;
}
void DestoryList(SL*sl) {
	free(sl->elem);
	sl->elem = NULL;
	sl->capacity = sl->size = 0;
}
