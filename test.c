#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

//��������
typedef struct
{
	int data;
	struct Node* next;
}Node, * pNode;

//��ʼ������
void InitList(pNode p)
{
	p = (Node*)malloc(sizeof(Node));
	p->next = p;                  //ͷ�ڵ�ָ��ͷ�ڵ�
}

//�ж������Ƿ�Ϊ��
bool isEmpty(pNode p)
{
	if ((p->next) == p)
	{
		return true;
	}
	return false;
}

//��������
bool Destroy(pNode p)
{
	pNode pn = p->next;           //��һ�����
	p->next = NULL;              //ͷ�ڵ�ָ����Ϊ��
	p = pn;                       //ָ���һ�����
	while (pn != NULL)
	{
		p = pn;
		p = p->next;
		free(pn);
	}
}

//���
int GetLength(pNode p)
{
	Node* n;
	int i = 0;
	n = p->next;           //ָ���һ�����
	while ((n->next) != p)
	{
		i++;
		n = n->next;
	}
	return i;
}

//ͷ��
bool CreateList(pNode p, int x)          //pΪͷ���
{
	pNode pm, pn;           //pnΪ�½��
	pm = p->next;           //��һ�����
	pn = (Node*)malloc(sizeof(Node));
	pn->data = x;
	pn->next = pm;
	p->next = pn;
	return true;
}

//β��
bool TailList(pNode p, int x)
{
	Node* n, * m;          //mΪ�½��
	n = p->next;         //��һ�����
	while (1)
	{
		n = n->next;
		if ((n->next) == p)
			break;
	}
	m = (Node*)malloc(sizeof(Node));
	m->data = x;
	n->next = m;
	m->next = p;
	return true;
}

//�������
void PrintList(pNode p)
{
	pNode n;
	n = p->next;
	while (1)
	{
		printf("%d ", &(n->data));
		n = n->next;
		if ((n->next) == p)
			break;
	}
}

//����βָ��
Node* Tail_Pointer(pNode p)
{
	Node* n;
	n = p->next;
	while (1)
	{
		n = n->next;
		if ((n->next) == p)
			return n;
	}
}

//�ϲ�����ѭ������
void mergeList(pNode p1, pNode p2)
{
	Node* m,* n;          //mΪp1��ͷ�ڵ�
	m = p1->next;
	n = p2->next;
	p1->next = n->next;
	free(n);
	p2->next = m;
}

int main()
{
	return 0;
}