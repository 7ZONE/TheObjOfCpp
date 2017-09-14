// list.cpp : 定义控制台应用程序的入口点。
//
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct Node
{
	int element;
	Node *next;
};
struct Node *CreatList(struct Node *head);
void  PrintTheList(struct Node *head);
void CleanTheList(struct Node *head);
struct Node *CleanTheNode(struct Node *PNode);
struct  Node *FindThenNode(struct Node *head);
int InsertHeadList(Node **pNode);
int InsertLastList(Node **pNode);
int InsertAtList(Node **pNode, int k);
struct  Node *FindTheNodePosition(struct Node *head, int k);
void Menu(struct Node *head);
int main()
{
	struct Node *head;
	head = NULL;
	Menu(head);
	return 0;
}
/*菜单函数*/
void Menu(struct Node *head)
{
	int Select;
	printf("菜单列表：\n");
	printf("1.创建链表。\n");
	printf("2.打印链表。\n");
	printf("3.清除。\n");
	printf("4.头插节点。\n");
	printf("5.尾插节点。\n");
	printf("6.寻找链表。\n");
	printf("7.退出\n");
	printf("8.中插节点。\n");
	printf("请选择：");
	scanf_s("%d", &Select);
	if (0 >= Select || 9 < Select)
	{
		printf("非法输入，请重新选择：\n");
		Menu(head);
	}
	switch (Select)
	{
	case 1:
		printf("1.Creat the lsit。\n");
		head = CreatList(head);
		PrintTheList(head);
		Menu(head);
		break;
	case 2:
		printf("2.Print the list。\n");
		PrintTheList(head);
		Menu(head);
		break;
	case 3:
		printf("3.Clean the list。\n");
		int n;
		printf("1.清除链表 \n 2.清除节点");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			CleanTheList(head);
			Menu(head);
			break;
		case 2:
			CleanTheNode(head);
			PrintTheList(head);
			Menu(head);
			break;
		}
		break;
	case 4:
		printf("4.Insert the head list。\n");
		InsertHeadList(&head);
		PrintTheList(head);
		Menu(head);
		break;
	case 5:
		printf("5.Insert the last list。\n");
		InsertLastList(&head);
		PrintTheList(head);
		Menu(head);
		break;
	case 6:
		printf("6.Find the Node if the list。\n");
		struct  Node *FindThenNode(struct Node *head);
		PrintTheList(head);
		Menu(head);
	case 7:
		break;
	case 8:
		printf("8.Please insert the position you want。\n");
		int k;
		scanf_s("%d", &k);
		InsertAtList(&head,k);
		PrintTheList(head);
		Menu(head);
		break;

	}
}
/*创建链表*/
struct Node *CreatList(struct Node *head)
{
	Node *p1, *p2;
	p1 = p2 = (Node *)malloc(sizeof(Node));
	if (p1 == NULL || p2 == NULL)
	{
		printf("内存分配失败\n");
		exit(0);
	}
	memset(p1, 0, sizeof(Node));
	printf("输入数据，以0结束\n");
	scanf_s("%d", &p1->element);
	p1->next = NULL;

	while (p1->element >0)  //输入的值大于0则继续，否则停止
	{
		if (head == NULL)//空表，接入表头
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (Node *)malloc(sizeof(Node));
		if (p1 == NULL || p2 == NULL)
		{
			printf("内存分配失败\n");
			exit(0);
		}
		memset(p1, 0, sizeof(Node));
		scanf_s("%d", &p1->element);
		p1->next = NULL;
	}
	printf("链表创建成功\n");
	return head;
}
/*打印链表*/
void  PrintTheList(struct Node *head)
{
	if (NULL == head)
	{
		printf("链表为空!\n");
	}
	else
	{
		while (NULL != head)
		{
			printf("    %d", head->element);
			head = head->next;
		}
		printf("\n");
	}
}
/*清除链表*/
void CleanTheList(struct Node *head)
{
	Node *pNext;
	if (head == NULL)
	{
		printf("链表为空\n");
		return;
	}
	while (head->next != NULL)
	{
		pNext = head->next;
		free(head);
		head = pNext;
	}
	printf("链表已经清除！\n");
}
/*清除节点*/
struct Node *CleanTheNode(struct Node *PNode)
{
	printf("输入你想清除的节点");
	int Delete;
	scanf_s("%d", &Delete);
	if (Delete<1)
	{
		printf("非法输入\n");
	}
	struct Node *P, *P1;
	P = P1 = PNode;
	if (PNode == NULL)
	{
		printf("函数执行，链表为空\n");
		return PNode;
	}
	while (Delete != P->element&&P->next != NULL)
	{
		P1 = P;
		P = P->next;
	}
	if (Delete = P->element)
	{
		if (P == PNode)
		{
			PNode = P->next;
		}
		else
		{
			P1->next = P->next;
		}
		free(P);
	}
	else
	{
		printf("The data is not finf!\n");
	}
	return PNode;
}
/*寻找节点*/
struct  Node *FindThenNode(struct Node *head)
{
	int emm;
	printf("Please input the ndoe you want to find!");
	scanf_s("%d", &emm);
	if (NULL == head)
	{
		printf("函数执行，链表为空\n");
		return NULL;
	}
	if (emm < 0)
	{
		printf("函数执行，给定值不合法\n");
		return NULL;
	}
	while ((head->element != emm) && (NULL != head->next)) //判断是否到链表末尾，以及是否存在所要找的元素
	{
		head = head->next;
	}
	if (head->element = emm)
	{
		printf("  你找的数据是: %d", head->element);
		printf("\n");
	}
	else if ((head->element != emm) && (head != NULL))
	{
		printf("函数执行，在链表中未找到ele值\n");
		return NULL;
	}
	return head;//返回head的地址
}
/*头插法*/
int InsertHeadList(Node **pNode)
{
	int insertElem;
	printf("输入你想插入的数据:  ");
	scanf_s("%d", &insertElem);
	Node *pInsert;
	pInsert = (Node *)malloc(sizeof(Node));
	if (pInsert == NULL)  exit(1);
	memset(pInsert, 0, sizeof(Node));
	pInsert->element = insertElem;
	pInsert->next = *pNode;
	*pNode = pInsert;
	printf("insertHeadList函数执行，向表头插入元素成功\n");
	return 1;
}
/*尾插法*/
int InsertLastList(Node **pNode)
{
	int insertElem;
	printf("输入你想插入的数据:  ");
	scanf_s("%d", &insertElem);
	Node *pInsert, *pHead, *pTmp;  // *pTmp定义一个临时链表用来存放第一个节点
	pHead = *pNode;
	pTmp = pHead;
	pInsert = (Node *)malloc(sizeof(Node)); //申请一个新节点
	if (pInsert == NULL)  exit(1);
	memset(pInsert, 0, sizeof(Node));
	pInsert->element = insertElem;
	while (pHead->next != NULL)
	{
		pHead = pHead->next;
	}
	pHead->next = pInsert;   //将链表末尾节点的下一结点指向新添加的节点
	*pNode = pTmp;
	printf("函数执行，向表尾插入元素成功\n");
	return 1;
}
/*Insert at the list*/
int InsertAtList(Node **pNode, int k)
{
	Node *temp, *nodetemp;
	int insertElem;
	Node *head = *pNode;
	if (!(temp = new Node))
	{
		printf("申请内存失败");
		return NULL;
	}
	else
	{
		printf("输入你想插入的数据:  ");
		scanf_s("%d", &insertElem);
		temp->element = insertElem;
		nodetemp = FindTheNodePosition(head, k - 1);
			if (nodetemp)
			{
				temp->next = nodetemp->next;
				nodetemp->next = temp;
			}
			else
			{
				printf("Can't find the position to insert");
				delete temp;
			}
	}
	return 1;

}
/*返回上一节点指针*/
struct  Node *FindTheNodePosition(struct Node *head, int k)
{
	Node *temp;
	int i = 1;
	temp = head;
	for (i = 1;i<k&&temp;i++)
	{
		temp = temp->next;
	}
	return temp;
}


