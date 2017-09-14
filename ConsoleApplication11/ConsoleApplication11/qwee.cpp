#include <cstdio>  
#include <string.h>  
#include <stdlib.h>  

struct queue
{
	int data[1000];
	int head;
	int tail;
};

struct stack
{
	int data[10];
	int top;
};

int main(int argc, char const *argv[])
{
	struct queue q1, q2;
	struct stack s;
	int book[10];
	int i, t;

	q1.head = q1.tail = 0;
	q2.head = q2.tail = 0;

	s.top = -1;

	for (i = 1; i <= 9; ++i)         // ��¼��������Щ�ƣ���ʼΪ��  
	{
		book[i] = 0;
	}


	for (i = 0; i < 6; ++i)
	{
		scanf_s("%d", &q1.data[q1.tail++]);
	}

	for (i = 0; i < 6; ++i)
	{
		scanf_s("%d", &q2.data[q2.tail++]);
	}

	while (q1.head < q1.tail && q2.head < q2.tail)
	{
		t = q1.data[q1.head];       // ��һ���˳���һ���� ����  
		if (0 == book[t])            // ����û�������� ��ջ  
		{
			s.data[++s.top] = t;
			book[t] = 1;        //����������Ѿ�������Ϊt����  
			q1.head++;
		}
		else
		{
			q1.data[q1.tail++] = t;         // Ӯ��  
			q1.head++;
			while (s.data[s.top] != t)       // ����ͬ���Ʒŵ�ĳ�������Ƶ�ĩβ  
			{
				book[s.data[s.top]] = 0;
				q1.data[q1.tail++] = s.data[s.top--];
			}
		}

		t = q2.data[q2.head];
		if (0 == book[t])
		{
			s.data[++s.top] = t;
			book[t] = 1;
			q2.head++;
		}
		else
		{
			q2.data[q2.tail++] = t;
			q2.head++;
			while (s.data[s.top] != t)
			{
				book[s.data[s.top]] = 0;
				q2.data[q2.tail++] = s.data[s.top--];
			}
		}
	}

	if (q2.head == q2.tail)                 // ��������û����  
	{
		printf("\nA win\n");
		printf("A���е�ֽ��: ");
		for (i = q1.head; i < q1.tail; ++i)
		{
			printf("%d ", q1.data[i]);
		}

		if (s.top > -1)                       // ������ϵ���  
		{
			printf("\n���ϵ���: ");
			for (i = 0; i <= s.top; ++i)
			{
				printf("%d ", s.data[i]);
			}
		}
		else
		{
			printf("\n�����Ѿ�û��ֽ���ˣ�");
		}
	}
	else
	{
		printf("\nB win\n");
		printf("B���е�ֽ��: ");
		for (i = q2.head; i < q2.tail; ++i)
		{
			printf("%d ", q2.data[i]);
		}

		if (s.top > -1)
		{
			printf("\n���ϵ���: ");
			for (i = 0; i <= s.top; ++i)
			{
				printf("%d ", s.data[i]);
			}
		}
		else
		{
			printf("\n�����Ѿ�û��ֽ���ˣ�");
		}
	}
	return 0;
}