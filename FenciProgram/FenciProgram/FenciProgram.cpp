
/*
*Date:2017-8-27
Programing : The Function of dismimate word
*/
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

const int s1 = 0XB0, s2 = 0XA1, e1 = 0XF8, e2 = 0XFF; //S1=176 ,S2=161, E1=248, E2=255
const int maxwordlen = 50;  //最大词组长度 中文25个

struct Second
{
	string key;
	Second *next;
	Second(string k = "", Second *n = 0) :key(k), next(n) {}
};

struct words {
	string word;
	int count = 0;
	struct words *next = NULL;
};

struct Head
{
	int size;
	string key;
	vector<Second*> W;
	Head(string k = "", int s = 0) :key(k), size(s) {}
};

class Dictiory
{
	struct words *head = NULL;
	vector<Head> H;
	ifstream fin;
	ifstream fcin;
	ofstream fout;
	int hash[e1 - s1][e2 - s2];
	int BinarySearch(string str, int k);
	int GetNum();
	void LoadDic();
	bool IsC(char c);
	bool IsEc(char c);
	void AddWord(string str, int k);
	void InsertWord(string str, int k);
	bool IsWord(string str, int k, int t);
	void SkipNotChinese(string &str, stack<string> &stk);
public:
	struct words *CreatNode(struct words *head);
	void AddNewWords(struct words *head, string s);
	void PrintToTxt(struct words *head, string s);
	Dictiory(string sfilename, string dfilename);
	void SegmentWord(string s);
	void PrintDic()
	{
		for (int i = 0; i < e1 - s1; i++)
			for (int j = 0; j < e2 - s2; j++)
			{
				if (hash[i][j] >= 0)
				{
					fout << H[hash[i][j]].key << endl;
					for (int k = 0; k < H[hash[i][j]].W.size(); k++)
					{
						Second *t = H[hash[i][j]].W[k];
						while (t)
						{
							fout << H[hash[i][j]].key;
							fout << t->key << endl;
							t = t->next;
						}
					}
				}
				fout << endl;
			}
	}
};

struct words *Dictiory::CreatNode(struct words *head) {
	words *temp;
	temp = new struct words;
	if (!temp) {
		cout << "没有足够的内存，申请失败" << endl;
		return NULL;
	}
	else {
		temp->word = "分词系统和词频统计";
		temp->next = NULL;
		head = temp;
	}
	return head;
}


void Dictiory::AddNewWords(struct words *head, string s)
{
	struct words *temp, *tail = head, *search = head;
	for (; search->next;) {
		if (s == search->word) {
			search->count++;
			return;
		}
		search = search->next;
	}
	temp = new struct words;
	if (!temp) {
		cout << "存放失败，没有足够的内存存放词语" << endl;
	}
	else {
		for (; tail->next;) {
			tail = tail->next;
		}
		temp->word = s;
		temp->count++;
		tail->next = temp;
		temp->next = NULL;
	}
};

void Dictiory::PrintToTxt(struct words *head, string s) {
	fcin.open(s.c_str());
	struct words *temp = head;
	for (; temp;) {
		if (temp->count == 0)
		{
			fout << temp->word << endl;
		}
		fout << temp->word << " 词频： " << temp->count << endl;
		temp = temp->next;
	}
}


Dictiory::Dictiory(string sfilename, string dfilename)
{
	int i, j;
	for (i = 0; i < e1 - s1; i++)
		for (j = 0; j < e2 - s2; j++)
			hash[i][j] = -1;
	H.resize(6768);
	fin.open(sfilename.c_str());  //dictionary.txt
	fout.open(dfilename.c_str());	//data.txt		
	LoadDic();
}
int Dictiory::BinarySearch(string str, int k)
{
	int len = str.length();
	int L = 0, R = H[k].W.size() - 1, M;
	while (L <= R)
	{
		M = (L + R) / 2;
		if (H[k].W[M]->key.size() == len)
			return M;
		else if (H[k].W[M]->key.size() < len)
			L = M + 1;
		else R = M - 1;
	}
	return -1;
}

void Dictiory::AddWord(string str, int k)
{
	if (str.length() > H[k].size)
	{
		H[k].size = str.length();
		Second *t = new Second(str);
		H[k].W.push_back(t);
	}
	else
		InsertWord(str, k);
}

void Dictiory::InsertWord(string str, int k)
{

	int in = BinarySearch(str, k);
	if (in == -1)
	{
		int L = 0, R = H[k].W.size() - 1;
		int len = str.length();
		while (L <= R&&len > H[k].W[L]->key.size())
			L++;
		H[k].W.resize(H[k].W.size() + 1);
		for (int i = R + 1; i > L; i--)
			H[k].W[i] = H[k].W[i - 1];
		Second *t = new Second(str);
		H[k].W[L] = t;
	}
	else
	{
		Second *pre = NULL, *t = H[k].W[in];
		while (t)
		{
			pre = t;
			t = t->next;
		}
		pre->next = new Second(str);
	}
}

int Dictiory::GetNum()
{
	char cstr[maxwordlen];
	fin.getline(cstr, maxwordlen);
	int n = 0, i;
	for (i = 0; i < strlen(cstr); i++)
		n = n * 10 + cstr[i] - '0';//转为数字
	return n;
}


void Dictiory::LoadDic()
{
	char cstr[maxwordlen];
	string str;
	int i, j, k = 0, wordnumber;
	while (fin.getline(cstr, maxwordlen))/*	 以逗号为分界点 getline(char *s,streamsize n,char delim)*/
	{
		i = (unsigned char)cstr[0] - s1;
		j = (unsigned char)cstr[1] - s2;
		hash[i][j] = k;
		H[k].key = cstr;//存入str
		wordnumber = GetNum();
		for (i = 0; i < wordnumber; i++)
		{
			fin.getline(cstr, maxwordlen);// 	fin.getline(char *s,streamsize n,char delim) 从输入流中提取最多n-1字符存入字符串变量S中，并加字符串结束符在字符串尾。如果在
										  //不到n-1字符时遇到换行符或文件结束符时结束
			str = cstr;
			str = str.substr(2, str.length() - 2);	//substr(startnum,countnum) 复制字符串，startnum为字符串的起始位置，countnum为复制字符数目		 
			AddWord(str, k);
		}
		k++;
	}
}

bool Dictiory::IsC(char c)
{
	unsigned value = unsigned((unsigned char)c);
	return value >= s1&&value < e1;
}

bool Dictiory::IsEc(char c)
{
	unsigned value = unsigned((unsigned char)c);
	return value <= 0X7F;
}

bool Dictiory::IsWord(string str, int k, int t)
{
	Second *temp = H[k].W[t];
	while (temp)
	{
		if (temp->key == str)//找到则返回true
			return true;
		temp = temp->next;//否则一直找   直到NULL
	}
	return false;
}
/*
如果不是中文 则跳过
*/
void Dictiory::SkipNotChinese(string &str, stack<string> &stk)
{
	unsigned L = 0, R = str.length();
	while (L < R&&!IsC(str[L]))
	{
		if (!IsEc(str[L]))
			L++;
		L++;
	}
	if (L > 0)
	{
		stk.push(str.substr(0, L));
		str = str.substr(L, R - L);
	}
}



void Dictiory::SegmentWord(string s)
{
	head = CreatNode(head);
	stack<string> stk;
	fcin.open(s.c_str());//fcin流打开S.c_cstr 返回一个指向正规C字符串的指针，内容与本String串相同
	char cstr[maxwordlen];
	string str, sstr;
	int i, j, startpos, endpos;
	char c;
	while (fcin.read(&c, sizeof(char))) 
	{
		if (!IsC(c))  //判断是否为合法字符
		{
			if (!str.empty())	//判断是否为空
			{
				cout << str << " 字符串长度：" << str.length() << endl;  //向屏幕输出字符串所占长度
				startpos = 0, endpos = str.length(); 
				while (startpos < endpos)
				{
					if (str.length() <= 2)
					{
						stk.push(str);//入栈
						if (!sstr.empty())
						{
							str = sstr;
							sstr.clear();
						}
						startpos += 2;
					}
					else
					{
						i = (unsigned char)str[0] - s1, j = (unsigned char)str[1] - s2;
						if (hash[i][j] >= 0)
						{
							string word = str.substr(2, str.length() - 2);  
							int in = BinarySearch(word, hash[i][j]); 
							if ((in != -1) && IsWord(word, hash[i][j], in)) 
							{
								stk.push(H[hash[i][j]].key + word);   
								startpos += str.length();
								str = sstr;
								sstr.clear();
							}
							else
							{
								sstr = sstr + str.substr(0, 2); 
								str = str.substr(2, str.length() - 2);	
							}
						}
						else
						{
							sstr = sstr + str.substr(0, 2);
							str = str.substr(2, str.length() - 2);
						}
					}
				}
				while (!stk.empty())
				{
					AddNewWords(head, stk.top());  //添加新单词存到链表里
					stk.pop();
				}
			}
			str.clear();
			str += c;
			while (fcin.read(&c, sizeof(char)) && !IsC(c))
				str += c;
			cout << str << " " << str.length() << endl;
			str.clear();
			str += c;
			fcin.read(&c, sizeof(char));
			str += c;
		}
		else
		{
			str += c;
			fcin.read(&c, sizeof(char));
			str += c;
		}
	}
	PrintToTxt(head, s); //将分好的词输出到文本文件
}

int main()
{
	Dictiory D("dictiory.txt", "data.txt");
	D.SegmentWord("sou.txt");
	system("pause");
	return 0;
}



