// TheProOfGame21.cpp : 定义控制台应用程序的入口点。
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
//洗牌函数
void xipai()
{
	for (int i = 0; i < 13; ++i)
		for (int j = 0; j < 4; ++j)
			pai[j][i] = i + 1;
}
//发牌函数，z张数，p谁，x p发了第几张了
void fapai(int z, int *p, int &x)
{
	srand((unsigned)time(NULL));//随机初始化

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
				cout << "黑桃 ";
				break;
			case 1:
				cout << "红桃 ";
				break;
			case 2:
				cout << "方块 ";
				break;
			case 3:
				cout << "梅花 ";
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
//判断21点
int pd(int *p, int x)
{
	int sum = 0;
	for (int i = 0; i < x; ++i)
		sum += p[i];
	return sum;
}
//判断输赢 
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
//输出输赢 
void scsy()
{
	switch (pdsy(pc, pcs, ren, rens))
	{
	case level:cout << "\n平局哦！\n";
		break;
	case win:cout << "\n电脑赢了哦!\n";
		break;
	case lose:cout << "\n恭喜，你赢了！\n";
		break;
	case other:cout << "两个都超过21点了，算平局吧！\n";

	}
}
//人是否发牌
int rfp()
{
	cout << "\n是否继续发牌？(Y or N)";
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		cout << "\n人发一张牌:\n";
		fapai(1, ren, rens);
		return 1;
	}

	else return 0;
}
//电脑是否发牌
void pfp()
{
	if ((pdsy(pc, pcs, ren, rens)<1))
	{
		cout << "\n电脑发一张牌:\n";
		fapai(1, pc, pcs);
	}
}
//结束看牌
void kp()
{
	cout << "电脑的牌是\n";
	for (int i = 0;i<pcs;++i)
		cout << pc[i] << '\t';
	cout << "\n人的牌是" << endl;

	for (int j = 0;j<rens;++j)
		cout << ren[j] << '\t';
	cout << endl;
}
int main()
{
	xipai();
	cout << "开始发牌\n";
	cout << "电脑的两张是：\n";
	fapai(2, pc, pcs);
	if (pd(pc, pcs)>21)
	{
		cout << "\n发牌就输了，真失败!\n";
		goto  KKKKKK;
	}
	cout << "\n人的两张是:\n";
	fapai(2, ren, rens);
	if (pd(ren, rens)>21)
	{
		cout << "\n发牌就输了，真失败!\n";
		goto  KKKKKK;
	}

	while (rfp())   //人要牌，就继续 
		pfp();
	pfp();  //人不要牌了，电脑还算算要不要 
	cout << "\n\n\n";
	kp();
	scsy();

KKKKKK:
	system("pause");
	return 0;
}