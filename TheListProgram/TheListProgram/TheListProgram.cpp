// TheListProgram.cpp : 定义控制台应用程序的入口点。
/*
*Creat by ZZQ  2017-8-22
*/
#include "stdafx.h"
#include <iostream>
#include<string>
using namespace  std;

struct StuData   //数据结点类型 
{
	string studentID;  //学号 
	string name;//姓名
	int age;//年龄
};
struct NodeType          //定义链表结构 
{
	StuData nodeStuData;
	NodeType *nextNode;
};

NodeType * AddTheNode(NodeType *head, StuData nodeData)
{
	NodeType *node, *temp;
	if (!(node = new NodeType))
	{
		cout << "分配内存失败！" << endl;  //分配内存失败 
		return NULL;
	}
	else
	{
		node->nodeStuData = nodeData;         //保存结点数据 
		node->nextNode = NULL;   //设置结点指针为空，即作为表尾 
		if (head == NULL)   //当链表是空表的时候 
		{
			head = node;
			return head;
		}
		temp = head;
		while (temp->nextNode != NULL) //遍历链表 查找链表的末尾
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
		cout << "分配内存失败" << endl;
		return NULL;
	}
	else
	{
		node->nodeStuData = nodeData;  //保存结点数据 
		node->nextNode = head;  //指向头指针所指向的指针 
		head = node;   //头指针指向新增结点 
		return head;
	}
}

NodeType *FindNodeNum(NodeType *head, int k)
{
	NodeType *temp;
	int i = 1;
	temp = head;    //保存链表头指针 
	for (i = 1;i<k&&temp;i++)   //找到该结点 
	{
		temp = temp->nextNode;
	}
	return temp;     //返回指向第k个结点的指针 
}

NodeType *FindNodeName(NodeType *head, string name)
{
	NodeType * temp;
	temp = head;    //保存链表头指针 
	while (temp)
	{
		if (temp->nodeStuData.name == name) //当结点关键字和传入关键字相同 
		{
			return temp;  //返回该结点指针 
		}
		temp = temp->nextNode;
	}
	return NULL;
}

NodeType *InsertNode(NodeType *head, int k, StuData nodeData)
{
	NodeType *node, *nodetemp;
	if (!(node = new NodeType))   //申请结点 
	{
		cout << "申请内存失败" << endl;
		return NULL;
	}
	else
	{
		node->nodeStuData = nodeData;  //保存结点中的数据
		nodetemp = FindNodeNum(head, k - 1);    //通过按照结点序号查找函数找到插入点前一个结点（关键结点） 
		if (nodetemp)
		{
			node->nextNode = nodetemp->nextNode;  //插入的结点指向关键结点的下一个节点 
			nodetemp->nextNode = node;    //关键结点指向插入点 
		}
		else
		{
			cout << "没有找到正确的插入位置" << endl;
			delete node;
		}
	}
	return head;      //返回头指针 
}

int DeleteTheNode(NodeType *head, string name)
{
	NodeType *node, *temp;    //node用于删除结点的前一个结点
	temp = head;
	node = head;
	while (temp)
	{
		if (temp->nodeStuData.name == name)             //找到关键字，执行删除操作 
		{
			node->nextNode = temp->nextNode;  //使前一结点指向当前节点的下一结点
			delete temp;   //释放该结点的空间（即，删除了结点）
			return 1;
		}
		else
		{
			node = temp;   //指向当前节点 
			temp = temp->nextNode;  //指向下一个结点 
		}
	}
	return 0;     //删除失败 
}

int GetLength(NodeType *head)
{
	NodeType *temp;
	int Length = 0;
	temp = head;
	while (temp)     //遍历整个数组
	{
		Length++;     //累加结点的数量
		temp = temp->nextNode;    //处理下一个结点 
	}
	return Length;
}

void ShowAllNode(NodeType *head)
{
	NodeType *temp;
	StuData nodeData;
	temp = head;
	cout << "链表长度为：" << GetLength(head) << endl;
	while (temp)     //遍历整个数组
	{
		nodeData = temp->nodeStuData;   //获取结点数据 
		cout << "学号 :" << nodeData.studentID <<"  "<<",姓名:" << nodeData.name << "  " << ",年龄 :" << nodeData.age << endl;
		temp = temp->nextNode;    //处理下一个结点 
	}
}

int main()
{
	NodeType *node, *head = NULL;
	StuData nodeData;
	string name;
	int k;
	cout << "请输入学生信息  : " << endl;
	cout << "格式如下：学号  姓名  年龄（当输入的年龄为0时  结束输入）" << endl;
	while (1)
	{
		cin >> nodeData.studentID >> nodeData.name >> nodeData.age;
		if (nodeData.age == 0)
			break;
		head = AddTheNode(head, nodeData);  //在链表的尾部添加结点 
	}

	//显示所有的结点
	ShowAllNode(head);    
	//演示在头部插入数据 
	cout << "请输入一个结点，并在链表的头部插入" << endl;
	cout << "格式为：学号，姓名，年龄" << endl;
	cin >> nodeData.studentID >> nodeData.name >> nodeData.age;
	head = AddHeadNode(head, nodeData);
	ShowAllNode(head);
	//演示在中间位置插入一个数据
	cout << "请输入插入点的位置：";
	cin >> k;
	cout << "请输入一个在链表内部插入的结点：" << endl;
	cin >> nodeData.studentID >> nodeData.name >> nodeData.age;
	head = InsertNode(head, k, nodeData);
	ShowAllNode(head);
	//演示按照序号查询数据 
	cout << "请输入要查询的节点序号：";
	cin >> k;
	node = FindNodeNum(head, k);
	cout << "您所查询的结点的学生信息为：" << endl;
	cout << "key:" << node->nodeStuData.studentID << ",name:" << node->nodeStuData.name << ",age:" << node->nodeStuData.age << endl;
	//演示按照姓名查询数据 
	cout << "请输入一个按照姓名查询的一个同学的姓名：";
	cin >> name;
	node = FindNodeName(head, name);
	cout << "您所查询的结点是：" << endl;
	cout << "key:" << node->nodeStuData.studentID << ",name:" << node->nodeStuData.name << ",age:" << node->nodeStuData.age << endl;
	//演示删除数据信息 
	cout << "请输入结点中的一个同学中的名字，系统会删除他的信息：";
	cin >> name;
	if (DeleteTheNode(head, name))cout << "数据删除成功！" << endl;
	ShowAllNode(head);
	return 0;
}
