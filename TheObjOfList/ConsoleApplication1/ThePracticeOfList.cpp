/*
Programing :  The List
Author : zzq
Date:2017-4-4
*/


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
void Menu(struct Node *head);




int main()
{
	struct Node *head ;
	head = NULL;
	Menu(head);
	return 0;
}
void Menu(struct Node *head)
{ 
	int Select;
	printf("菜单列表：\n");
	printf("1.Creat the lsit。\n");
	printf("2.Print the list。\n");
	printf("3.Clean the list。\n");
	printf("4.Insert the head list。\n");
	printf("5.Insert the last list。\n");
	printf("6.Find the Node if the list。\n");
	printf("7.End\n");
	printf("请选择：");
	scanf_s("%d", &Select);
	if (0 >= Select || 7 <= Select)
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
		printf("1.clean the lsit \n 2.clean the node!");
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
		exit(0);
	};
}
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
		 printf("Please in put the data,when you input the value < 0,exit!\n");
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
	     printf("CreatList函数执行，链表创建成功\n");
	     return head;
		
}
void  PrintTheList(struct Node *head)
{
	if (NULL == head)
	{
		printf("The list is empty!");

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
void CleanTheList(struct Node *head)
{
	Node *pNext;
	
	     if (head == NULL)
	     {
	         printf("clearList函数执行，链表为空\n");
	         return;
	     }
	 while (head->next != NULL)
	     {
	         pNext = head->next;
	         free(head);
			 head = pNext;
	     }
	 printf("clearList函数执行，链表已经清除！\n");
}
struct Node *CleanTheNode(struct Node *PNode)
{
	printf("Input the ndoe you want to delete");
		int Delete;
		scanf_s("%d", &Delete);
		 if (Delete<1)
		     {
		         printf("Delete值非法\n");
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
	if(Delete = P->element)
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
struct  Node *FindThenNode(struct Node *head)
{
	int emm;
	printf("Please input the ndoe you want to find!");
	scanf_s("%d", &emm);
	if (NULL == head)
	{
		printf("FindThenNode函数执行，链表为空\n");
		return NULL;
	}
	if (emm < 0)
	{
		printf("FindThenNode函数执行，给定值不合法\n");
		return NULL;
	}
	while ((head->element != emm) && (NULL != head->next)) //判断是否到链表末尾，以及是否存在所要找的元素
	{
		head = head->next;
	}
	if (head->element = emm)
	{
		printf("  The data you find is : %d", head->element);
		printf("\n");
	}
	if ((head->element != emm) && (head != NULL))
	{
		printf("FindThenNode函数执行，在链表中未找到ele值\n");
		return NULL;
	}
	
	return head;//返回head的地址

}

int InsertHeadList(Node **pNode)
{
	int insertElem;
	printf("Input the insertElem you want to insert:  ");
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
int InsertLastList(Node **pNode)
{
	int insertElem;
	printf("Input the insertElem you want to insert:  ");
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
	printf("insertLastList函数执行，向表尾插入元素成功\n");

	return 1;
}