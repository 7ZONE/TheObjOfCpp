// DiscrimimateWord.cpp : 定义控制台应用程序的入口点。
//program:分词系统
//date:2017/8/22
//author:敖俊华


#include "stdafx.h"
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
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

struct words { //存放词语的链表
	string word;
	int count = 0;
	struct words *next = NULL;
};

struct Head
{
	int size;	//关键字大小
	string key;  //存放关键字
	vector<Second*> W;
	Head(string k = "", int s = 0) :key(k), size(s) {}
};

class Dictiory
{
	struct words *head = NULL; //创建保存词语的链表
	vector<Head> H;
	ifstream fin;   //文件输入流
	ifstream fcin;	//文件输入流
	ofstream fout;	//文件输出流
	int hash[e1 - s1][e2 - s2];	  //hash[72][94]
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
//函数功能：新建链表
struct words *Dictiory::CreatNode(struct words *head) {
	words *temp;
	temp = new struct words;   //申请新的内存
	if (!temp) {
		cout << "erro 003新建链表时没有足够内存" << endl;
		return NULL;
	}
	else {
		temp->word = "---分词系统和词频统计---";
		temp->next = NULL;
		head = temp;    //将head头指针指向新建链表
	}
	return head;
}


/*函数功能：用尾插法添加新的词语*/
void Dictiory::AddNewWords(struct words *head, string s)
{
	struct words *temp, *tail = head, *search = head;
	for (; search->next;) {  //便利查找是否已存在词语在链表中
		if (s == search->word) {
			search->count++;
			return;
		}
		search = search->next;
	}
	temp = new struct words;
	if (!temp) {
		cout << "error001：没有足够的内存存放词语！" << endl;
	}
	else {
		for (; tail->next;) {
			tail = tail->next;
		}
		temp->word = s;
		temp->count++;
		tail->next = temp;    //将原来链表最后一个尾巴的指针指向新建链表
		temp->next = NULL;		//新建链表尾巴赋值空
	}
};

/*输出到记事本*/
void Dictiory::PrintToTxt(struct words *head, string s) {
	fcin.open(s.c_str());//返回一个指向正规C字符串的指针，内容与本String串相同
	struct words *temp = head;
	for (; temp;) {
		fout << temp->word << "  " << temp->count << endl;
		temp = temp->next;
	}
}


/*函数功能：初始化vector容器，读取文件*/
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

/*函数功能：统计字符串可以拆分为几个关键字*/
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

/*函数功能：读取关键字后，把第关键字中第二个中文字符存到关键字数组对应位置中*/
void Dictiory::AddWord(string str, int k)
{
	if (str.length() > H[k].size)
	{
		H[k].size = str.length();
		Second *t = new Second(str);  //读取关键字中第二个字符
		H[k].W.push_back(t);	//将关键字中第二个字符存到关键字数组对应位置中
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
	for (i = 0; i < strlen(cstr); i++)  //strlen(s)返回字符s的长度,不包括'\0'和NULL
		n = n * 10 + cstr[i] - '0';
	return n;
}

/*函数功能： 提取dictionary中的词组关键字 */
void Dictiory::LoadDic()
{
	char cstr[maxwordlen];
	string str;
	int i, j, k = 0, wordnumber;
	while (fin.getline(cstr, maxwordlen))/*从输出流fin中提取最多maxwordlen-1字符存入字符号串变量cstr中，
										 并在字符串结束符在字符串尾。如果在不到maxwordlen-1字符时遇到换行符或文件结束符时结束。
										 getline(char *s,streamsize n,char delim)是更高级的用法，你可以指定字符“delim”为结束标记符，*/
	{
		i = (unsigned char)cstr[0] - s1; //字符如果声明为unsigned char 且长度与int相同,则相加减后结果回事unsigned int类型
		j = (unsigned char)cstr[1] - s2;
		hash[i][j] = k;
		H[k].key = cstr;
		wordnumber = GetNum();
		for (i = 0; i < wordnumber; i++)  //循环遍历以txt中读取到的数字，将对应数量的关键字存放到关键字数组中
		{
			fin.getline(cstr, maxwordlen);
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

/*在字符串第一个中文字符对应位置寻找后面的关键字是否存在字典中*/
bool Dictiory::IsWord(string str, int k, int t)
{
	Second *temp = H[k].W[t];
	while (temp)
	{
		if (temp->key == str)
			return true;
		temp = temp->next;
	}
	return false;
}

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
	fcin.open(s.c_str());//返回一个指向正规C字符串的指针，内容与本String串相同
	char cstr[maxwordlen];
	string str, sstr;
	int i, j, startpos, endpos;
	char c;
	while (fcin.read(&c, sizeof(char)))  //将数据输入通道（一直到遇到标点符号停止载入，每次载入的都是一段句子）
	{
		if (!IsC(c))  //判断是否为字典中的字符
		{
			if (!str.empty())	//判断是否为空
			{
				cout << str << " " << str.length() << endl;  //向屏幕输出字符串所占长度
				startpos = 0, endpos = str.length();  //endpos等于字符串的长度
				while (startpos < endpos)
				{
					if (str.length() <= 2)
					{
						stk.push(str);
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
							string word = str.substr(2, str.length() - 2);  //获取关键字第二个中文字符后面的字符
							int in = BinarySearch(word, hash[i][j]);  //统计字符串可以拆分为几个关键字
							if ((in != -1) && IsWord(word, hash[i][j], in))  //当判断所选字符串含有关键字时
							{
								stk.push(H[hash[i][j]].key + word);   //stk存放已经确认为词语的关键字
								startpos += str.length();
								str = sstr;
								sstr.clear();
							}
							else
							{
								sstr = sstr + str.substr(0, 2);  //sstr存放字符串第一个中文字符
								str = str.substr(2, str.length() - 2);	//str存放字符串除第一个中文字符后面的所有字符串  
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
					//	fout << stk.top() << endl;
					AddNewWords(head, stk.top());  //添加新单词存到链表里
					stk.pop();
				}
			}
			str.clear();
			str += c;
			while (fcin.read(&c, sizeof(char)) && !IsC(c))
				str += c;
			//	fout << str << endl;   //向文件输出标点符号和换行符
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



