#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

//定义类型
typedef struct
{
	int data;
	struct Node* next;
}Node, * pNode;

//初始化链表
void InitList(pNode p)
{
	p = (Node*)malloc(sizeof(Node));
	p->next = p;                  //头节点指向头节点
}

//判断链表是否为空
bool isEmpty(pNode p)
{
	if ((p->next) == p)
	{
		return true;
	}
	return false;
}

//销毁链表
bool Destroy(pNode p)
{
	pNode pn = p->next;           //第一个结点
	p->next = NULL;              //头节点指针域为空
	p = pn;                       //指向第一个结点
	while (pn != NULL)
	{
		p = pn;
		p = p->next;
		free(pn);
	}
}

//求表长
int GetLength(pNode p)
{
	Node* n;
	int i = 0;
	n = p->next;           //指向第一个结点
	while ((n->next) != p)
	{
		i++;
		n = n->next;
	}
	return i;
}

//头插
bool CreateList(pNode p, int x)          //p为头结点
{
	pNode pm, pn;           //pn为新结点
	pm = p->next;           //第一个结点
	pn = (Node*)malloc(sizeof(Node));
	pn->data = x;
	pn->next = pm;
	p->next = pn;
	return true;
}

//尾插
bool TailList(pNode p, int x)
{
	Node* n, * m;          //m为新结点
	n = p->next;         //第一个结点
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

//输出链表
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

//查找尾指针
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

//合并两个循环链表
void mergeList(pNode p1, pNode p2)
{
	Node* m,* n;          //m为p1的头节点
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