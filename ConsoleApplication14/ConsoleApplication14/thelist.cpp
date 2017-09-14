// list.cpp : �������̨Ӧ�ó������ڵ㡣
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
/*�˵�����*/
void Menu(struct Node *head)
{
	int Select;
	printf("�˵��б�\n");
	printf("1.��������\n");
	printf("2.��ӡ����\n");
	printf("3.�����\n");
	printf("4.ͷ��ڵ㡣\n");
	printf("5.β��ڵ㡣\n");
	printf("6.Ѱ������\n");
	printf("7.�˳�\n");
	printf("8.�в�ڵ㡣\n");
	printf("��ѡ��");
	scanf_s("%d", &Select);
	if (0 >= Select || 9 < Select)
	{
		printf("�Ƿ����룬������ѡ��\n");
		Menu(head);
	}
	switch (Select)
	{
	case 1:
		printf("1.Creat the lsit��\n");
		head = CreatList(head);
		PrintTheList(head);
		Menu(head);
		break;
	case 2:
		printf("2.Print the list��\n");
		PrintTheList(head);
		Menu(head);
		break;
	case 3:
		printf("3.Clean the list��\n");
		int n;
		printf("1.������� \n 2.����ڵ�");
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
		printf("4.Insert the head list��\n");
		InsertHeadList(&head);
		PrintTheList(head);
		Menu(head);
		break;
	case 5:
		printf("5.Insert the last list��\n");
		InsertLastList(&head);
		PrintTheList(head);
		Menu(head);
		break;
	case 6:
		printf("6.Find the Node if the list��\n");
		struct  Node *FindThenNode(struct Node *head);
		PrintTheList(head);
		Menu(head);
	case 7:
		break;
	case 8:
		printf("8.Please insert the position you want��\n");
		int k;
		scanf_s("%d", &k);
		InsertAtList(&head,k);
		PrintTheList(head);
		Menu(head);
		break;

	}
}
/*��������*/
struct Node *CreatList(struct Node *head)
{
	Node *p1, *p2;
	p1 = p2 = (Node *)malloc(sizeof(Node));
	if (p1 == NULL || p2 == NULL)
	{
		printf("�ڴ����ʧ��\n");
		exit(0);
	}
	memset(p1, 0, sizeof(Node));
	printf("�������ݣ���0����\n");
	scanf_s("%d", &p1->element);
	p1->next = NULL;

	while (p1->element >0)  //�����ֵ����0�����������ֹͣ
	{
		if (head == NULL)//�ձ������ͷ
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
			printf("�ڴ����ʧ��\n");
			exit(0);
		}
		memset(p1, 0, sizeof(Node));
		scanf_s("%d", &p1->element);
		p1->next = NULL;
	}
	printf("�������ɹ�\n");
	return head;
}
/*��ӡ����*/
void  PrintTheList(struct Node *head)
{
	if (NULL == head)
	{
		printf("����Ϊ��!\n");
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
/*�������*/
void CleanTheList(struct Node *head)
{
	Node *pNext;
	if (head == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	while (head->next != NULL)
	{
		pNext = head->next;
		free(head);
		head = pNext;
	}
	printf("�����Ѿ������\n");
}
/*����ڵ�*/
struct Node *CleanTheNode(struct Node *PNode)
{
	printf("������������Ľڵ�");
	int Delete;
	scanf_s("%d", &Delete);
	if (Delete<1)
	{
		printf("�Ƿ�����\n");
	}
	struct Node *P, *P1;
	P = P1 = PNode;
	if (PNode == NULL)
	{
		printf("����ִ�У�����Ϊ��\n");
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
/*Ѱ�ҽڵ�*/
struct  Node *FindThenNode(struct Node *head)
{
	int emm;
	printf("Please input the ndoe you want to find!");
	scanf_s("%d", &emm);
	if (NULL == head)
	{
		printf("����ִ�У�����Ϊ��\n");
		return NULL;
	}
	if (emm < 0)
	{
		printf("����ִ�У�����ֵ���Ϸ�\n");
		return NULL;
	}
	while ((head->element != emm) && (NULL != head->next)) //�ж��Ƿ�����ĩβ���Լ��Ƿ������Ҫ�ҵ�Ԫ��
	{
		head = head->next;
	}
	if (head->element = emm)
	{
		printf("  ���ҵ�������: %d", head->element);
		printf("\n");
	}
	else if ((head->element != emm) && (head != NULL))
	{
		printf("����ִ�У���������δ�ҵ�eleֵ\n");
		return NULL;
	}
	return head;//����head�ĵ�ַ
}
/*ͷ�巨*/
int InsertHeadList(Node **pNode)
{
	int insertElem;
	printf("����������������:  ");
	scanf_s("%d", &insertElem);
	Node *pInsert;
	pInsert = (Node *)malloc(sizeof(Node));
	if (pInsert == NULL)  exit(1);
	memset(pInsert, 0, sizeof(Node));
	pInsert->element = insertElem;
	pInsert->next = *pNode;
	*pNode = pInsert;
	printf("insertHeadList����ִ�У����ͷ����Ԫ�سɹ�\n");
	return 1;
}
/*β�巨*/
int InsertLastList(Node **pNode)
{
	int insertElem;
	printf("����������������:  ");
	scanf_s("%d", &insertElem);
	Node *pInsert, *pHead, *pTmp;  // *pTmp����һ����ʱ����������ŵ�һ���ڵ�
	pHead = *pNode;
	pTmp = pHead;
	pInsert = (Node *)malloc(sizeof(Node)); //����һ���½ڵ�
	if (pInsert == NULL)  exit(1);
	memset(pInsert, 0, sizeof(Node));
	pInsert->element = insertElem;
	while (pHead->next != NULL)
	{
		pHead = pHead->next;
	}
	pHead->next = pInsert;   //������ĩβ�ڵ����һ���ָ������ӵĽڵ�
	*pNode = pTmp;
	printf("����ִ�У����β����Ԫ�سɹ�\n");
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
		printf("�����ڴ�ʧ��");
		return NULL;
	}
	else
	{
		printf("����������������:  ");
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
/*������һ�ڵ�ָ��*/
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


