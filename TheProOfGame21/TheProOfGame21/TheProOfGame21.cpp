// TheProOfGame21.cpp : �������̨Ӧ�ó������ڵ㡣
/*
Programing : Game 21
Date:2017-5-13
Author : ZZQ
*/


1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
#include <iostream>
using namespace std;
int pai[4][13] = { 0 };
int pc[7] = { 0 };
int ren[7] = { 0 };
int pcs = 0;
int rens = 0;
//ϴ�ƺ���
void xipai()
{
	for (int i = 0; i < 13; ++i)
		for (int j = 0; j < 4; ++j)
			pai[j][i] = i + 1;
}
//���ƺ�����z������p˭��x p���˵ڼ�����
void fapai(int z, int *p, int &x)
{
	srand((unsigned)time(NULL));//�����ʼ��

	for (int i = 0; i < z; ++i)
	{
		int a = rand() % 4;
		int b = rand() % 13;
		if (pai[a][b] >0)
		{
			p[x] = pai[a][b];
			pai[a][b] = -1;
			switch (a)
			{
			case 0:
				cout << "���� ";
				break;
			case 1:
				cout << "���� ";
				break;
			case 2:
				cout << "���� ";
				break;
			case 3:
				cout << "÷�� ";
				break;
			}
			cout << p[x];
			++x;
		}
		else
		{
			--i;
			continue;
		}
	}
}
//�ж�21��
int pd(int *p, int x)
{
	int sum = 0;
	for (int i = 0; i < x; ++i)
		sum += p[i];
	return sum;
}
//�ж���Ӯ 
enum shuying { lose, level, win, other };
shuying pdsy(int *p, int ps, int *r, int rs)
{
	int rss = pd(r, rs);
	int pss = pd(p, ps);

	if (rss>21 && pss>21)
		return other;
	if (rss>21 && pss<21)
		return win;
	if (rss<21 && pss>21)
		return lose;
	if (rss>pss) return lose;
	if (rss<pss) return win;
	return level;
}
//�����Ӯ 
void scsy()
{
	switch (pdsy(pc, pcs, ren, rens))
	{
	case level:cout << "\nƽ��Ŷ��\n";
		break;
	case win:cout << "\n����Ӯ��Ŷ!\n";
		break;
	case lose:cout << "\n��ϲ����Ӯ�ˣ�\n";
		break;
	case other:cout << "����������21���ˣ���ƽ�ְɣ�\n";

	}
}
//���Ƿ���
int rfp()
{
	cout << "\n�Ƿ�������ƣ�(Y or N)";
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		cout << "\n�˷�һ����:\n";
		fapai(1, ren, rens);
		return 1;
	}

	else return 0;
}
//�����Ƿ���
void pfp()
{
	if ((pdsy(pc, pcs, ren, rens)<1))
	{
		cout << "\n���Է�һ����:\n";
		fapai(1, pc, pcs);
	}
}
//��������
void kp()
{
	cout << "���Ե�����\n";
	for (int i = 0;i<pcs;++i)
		cout << pc[i] << '\t';
	cout << "\n�˵�����" << endl;

	for (int j = 0;j<rens;++j)
		cout << ren[j] << '\t';
	cout << endl;
}
int main()
{
	xipai();
	cout << "��ʼ����\n";
	cout << "���Ե������ǣ�\n";
	fapai(2, pc, pcs);
	if (pd(pc, pcs)>21)
	{
		cout << "\n���ƾ����ˣ���ʧ��!\n";
		goto  KKKKKK;
	}
	cout << "\n�˵�������:\n";
	fapai(2, ren, rens);
	if (pd(ren, rens)>21)
	{
		cout << "\n���ƾ����ˣ���ʧ��!\n";
		goto  KKKKKK;
	}

	while (rfp())   //��Ҫ�ƣ��ͼ��� 
		pfp();
	pfp();  //�˲�Ҫ���ˣ����Ի�����Ҫ��Ҫ 
	cout << "\n\n\n";
	kp();
	scsy();

KKKKKK:
	system("pause");
	return 0;
}