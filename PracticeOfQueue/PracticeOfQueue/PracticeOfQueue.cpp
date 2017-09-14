// PracticeOfQueue.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include "queue.h"
using namespace std;


int main()
{
	Queue<int> q(10); //声明队列
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
		q.push(i + 1);
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
		if (!q.empty()) //此处需要判断此时队列是否为空
		{
			q.push(q.front());
			q.pop();
		}
	}
	cout << endl;
	return 0;
}

