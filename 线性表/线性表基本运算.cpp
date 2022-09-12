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
	printf("����֮ǰ��\n");
	printList(&sl);
	backDelete(&sl);
	printf("βɾ֮��\n");
	printList(&sl);
	printf("ͷ��֮��\n");
	headInsert(&sl, 10);
	headInsert(&sl, 20);
	headInsert(&sl, 30);
	printList(&sl);
	printf("ͷɾ֮��\n");
	headDelete(&sl);
	printList(&sl);
	res=FindList(&sl, 10);
	printf("10��λ����%d\n", res);
	Insert(&sl, 3, 8);
	printf("�ڵ�3��λ�ò���8��\n");
	printList(&sl);
	Delete(&sl, 3);
	printf("ɾ����3��λ��:\n");
	printList(&sl);
	DestoryList(&sl);

}
int main() {
	
	test();
	return 0;
}






void seqListInit(SL* sl){
	sl->elem = NULL;
	sl->capacity = sl->size = 0;//��Ȼ����Ҳ���Կ���n��
}
void backInsert(SL *sl, DataType x){
	//���ݲ���
	if (sl->capacity == sl->size) {
		int newcapicity = sl->capacity == 0 ? 4 : sl->capacity * 2;//�������
		DataType *tep = (DataType*)realloc(sl->elem, newcapicity*(sizeof(DataType)));
		if (tep == NULL) {
			printf("����ʧ����\n");
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
	if (sl->size > 0) {//��ֹԽ��
		sl->elem[back] = 0;
		sl->size--;
	}
}
void checkSL(SL*sl) {
	if (sl->capacity == sl->size) {
		int newcapicity = sl->capacity == 0 ? 4 : sl->capacity * 2;//�������
		DataType *tep = (DataType*)realloc(sl->elem, newcapicity*(sizeof(DataType)));
		if (tep == NULL) {
			printf("����ʧ����\n");
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
		printf("��û�б������ˣ�\n");
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
		printf("����λ����Ч��\n");
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
		printf("ɾ��λ����Ч��\n");
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
