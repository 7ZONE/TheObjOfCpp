// TheListProgram.cpp : �������̨Ӧ�ó������ڵ㡣
/*
*Creat by ZZQ  2017-8-22
*/
#include "stdafx.h"
#include <iostream>
#include<string>
using namespace  std;

struct StuData   //���ݽ������ 
{
	string studentID;  //ѧ�� 
	string name;//����
	int age;//����
};
struct NodeType          //��������ṹ 
{
	StuData nodeStuData;
	NodeType *nextNode;
};

NodeType * AddTheNode(NodeType *head, StuData nodeData)
{
	NodeType *node, *temp;
	if (!(node = new NodeType))
	{
		cout << "�����ڴ�ʧ�ܣ�" << endl;  //�����ڴ�ʧ�� 
		return NULL;
	}
	else
	{
		node->nodeStuData = nodeData;         //���������� 
		node->nextNode = NULL;   //���ý��ָ��Ϊ�գ�����Ϊ��β 
		if (head == NULL)   //�������ǿձ��ʱ�� 
		{
			head = node;
			return head;
		}
		temp = head;
		while (temp->nextNode != NULL) //�������� ���������ĩβ
		{
			temp = temp->nextNode;
		}
		temp->nextNode = node;
		return head;
	}

}

NodeType *AddHeadNode(NodeType *head, StuData nodeData)
{
	NodeType *node;
	if (!(node = new NodeType))
	{
		cout << "�����ڴ�ʧ��" << endl;
		return NULL;
	}
	else
	{
		node->nodeStuData = nodeData;  //���������� 
		node->nextNode = head;  //ָ��ͷָ����ָ���ָ�� 
		head = node;   //ͷָ��ָ��������� 
		return head;
	}
}

NodeType *FindNodeNum(NodeType *head, int k)
{
	NodeType *temp;
	int i = 1;
	temp = head;    //��������ͷָ�� 
	for (i = 1;i<k&&temp;i++)   //�ҵ��ý�� 
	{
		temp = temp->nextNode;
	}
	return temp;     //����ָ���k������ָ�� 
}

NodeType *FindNodeName(NodeType *head, string name)
{
	NodeType * temp;
	temp = head;    //��������ͷָ�� 
	while (temp)
	{
		if (temp->nodeStuData.name == name) //�����ؼ��ֺʹ���ؼ�����ͬ 
		{
			return temp;  //���ظý��ָ�� 
		}
		temp = temp->nextNode;
	}
	return NULL;
}

NodeType *InsertNode(NodeType *head, int k, StuData nodeData)
{
	NodeType *node, *nodetemp;
	if (!(node = new NodeType))   //������ 
	{
		cout << "�����ڴ�ʧ��" << endl;
		return NULL;
	}
	else
	{
		node->nodeStuData = nodeData;  //�������е�����
		nodetemp = FindNodeNum(head, k - 1);    //ͨ�����ս����Ų��Һ����ҵ������ǰһ����㣨�ؼ���㣩 
		if (nodetemp)
		{
			node->nextNode = nodetemp->nextNode;  //����Ľ��ָ��ؼ�������һ���ڵ� 
			nodetemp->nextNode = node;    //�ؼ����ָ������ 
		}
		else
		{
			cout << "û���ҵ���ȷ�Ĳ���λ��" << endl;
			delete node;
		}
	}
	return head;      //����ͷָ�� 
}

int DeleteTheNode(NodeType *head, string name)
{
	NodeType *node, *temp;    //node����ɾ������ǰһ�����
	temp = head;
	node = head;
	while (temp)
	{
		if (temp->nodeStuData.name == name)             //�ҵ��ؼ��֣�ִ��ɾ������ 
		{
			node->nextNode = temp->nextNode;  //ʹǰһ���ָ��ǰ�ڵ����һ���
			delete temp;   //�ͷŸý��Ŀռ䣨����ɾ���˽�㣩
			return 1;
		}
		else
		{
			node = temp;   //ָ��ǰ�ڵ� 
			temp = temp->nextNode;  //ָ����һ����� 
		}
	}
	return 0;     //ɾ��ʧ�� 
}

int GetLength(NodeType *head)
{
	NodeType *temp;
	int Length = 0;
	temp = head;
	while (temp)     //������������
	{
		Length++;     //�ۼӽ�������
		temp = temp->nextNode;    //������һ����� 
	}
	return Length;
}

void ShowAllNode(NodeType *head)
{
	NodeType *temp;
	StuData nodeData;
	temp = head;
	cout << "������Ϊ��" << GetLength(head) << endl;
	while (temp)     //������������
	{
		nodeData = temp->nodeStuData;   //��ȡ������� 
		cout << "ѧ�� :" << nodeData.studentID <<"  "<<",����:" << nodeData.name << "  " << ",���� :" << nodeData.age << endl;
		temp = temp->nextNode;    //������һ����� 
	}
}

int main()
{
	NodeType *node, *head = NULL;
	StuData nodeData;
	string name;
	int k;
	cout << "������ѧ����Ϣ  : " << endl;
	cout << "��ʽ���£�ѧ��  ����  ���䣨�����������Ϊ0ʱ  �������룩" << endl;
	while (1)
	{
		cin >> nodeData.studentID >> nodeData.name >> nodeData.age;
		if (nodeData.age == 0)
			break;
		head = AddTheNode(head, nodeData);  //�������β����ӽ�� 
	}

	//��ʾ���еĽ��
	ShowAllNode(head);    
	//��ʾ��ͷ���������� 
	cout << "������һ����㣬���������ͷ������" << endl;
	cout << "��ʽΪ��ѧ�ţ�����������" << endl;
	cin >> nodeData.studentID >> nodeData.name >> nodeData.age;
	head = AddHeadNode(head, nodeData);
	ShowAllNode(head);
	//��ʾ���м�λ�ò���һ������
	cout << "�����������λ�ã�";
	cin >> k;
	cout << "������һ���������ڲ�����Ľ�㣺" << endl;
	cin >> nodeData.studentID >> nodeData.name >> nodeData.age;
	head = InsertNode(head, k, nodeData);
	ShowAllNode(head);
	//��ʾ������Ų�ѯ���� 
	cout << "������Ҫ��ѯ�Ľڵ���ţ�";
	cin >> k;
	node = FindNodeNum(head, k);
	cout << "������ѯ�Ľ���ѧ����ϢΪ��" << endl;
	cout << "key:" << node->nodeStuData.studentID << ",name:" << node->nodeStuData.name << ",age:" << node->nodeStuData.age << endl;
	//��ʾ����������ѯ���� 
	cout << "������һ������������ѯ��һ��ͬѧ��������";
	cin >> name;
	node = FindNodeName(head, name);
	cout << "������ѯ�Ľ���ǣ�" << endl;
	cout << "key:" << node->nodeStuData.studentID << ",name:" << node->nodeStuData.name << ",age:" << node->nodeStuData.age << endl;
	//��ʾɾ��������Ϣ 
	cout << "���������е�һ��ͬѧ�е����֣�ϵͳ��ɾ��������Ϣ��";
	cin >> name;
	if (DeleteTheNode(head, name))cout << "����ɾ���ɹ���" << endl;
	ShowAllNode(head);
	return 0;
}
