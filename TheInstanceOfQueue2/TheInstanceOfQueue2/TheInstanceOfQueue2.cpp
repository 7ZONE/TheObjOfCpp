/*#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int e, n, m;
	queue<int> q1;
	for (int i = 0;i<100;i++)
		q1.push(i);
	if (!q1.empty())
		cout << "dui lie  bu kong\n";
	n = q1.size();
	cout << "The size of queue"<<n << endl;
	m = q1.back();
	cout<<"The tail of the queue" << m << endl;
	for (int j = 0;j<n;j++)
	{
		e = q1.front();//head
		cout <<"是第"<<j<<"个元素"<< e << " ";
		q1.pop();
	}
	cout << endl;
	if (q1.empty())
		cout << "dui lie  bu kong\n";
	system("PAUSE");
	return 0;
}*/