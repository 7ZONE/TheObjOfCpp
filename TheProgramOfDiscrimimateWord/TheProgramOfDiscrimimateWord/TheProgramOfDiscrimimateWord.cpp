// DiscrimimateWord.cpp : �������̨Ӧ�ó������ڵ㡣
//program:�ִ�ϵͳ
//date:2017/8/22
//author:������


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
const int maxwordlen = 50;  //�����鳤�� ����25��

struct Second
{
	string key;
	Second *next;
	Second(string k = "", Second *n = 0) :key(k), next(n) {}
};

struct words { //��Ŵ��������
	string word;
	int count = 0;
	struct words *next = NULL;
};

struct Head
{
	int size;	//�ؼ��ִ�С
	string key;  //��Źؼ���
	vector<Second*> W;
	Head(string k = "", int s = 0) :key(k), size(s) {}
};

class Dictiory
{
	struct words *head = NULL; //����������������
	vector<Head> H;
	ifstream fin;   //�ļ�������
	ifstream fcin;	//�ļ�������
	ofstream fout;	//�ļ������
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
//�������ܣ��½�����
struct words *Dictiory::CreatNode(struct words *head) {
	words *temp;
	temp = new struct words;   //�����µ��ڴ�
	if (!temp) {
		cout << "erro 003�½�����ʱû���㹻�ڴ�" << endl;
		return NULL;
	}
	else {
		temp->word = "---�ִ�ϵͳ�ʹ�Ƶͳ��---";
		temp->next = NULL;
		head = temp;    //��headͷָ��ָ���½�����
	}
	return head;
}


/*�������ܣ���β�巨����µĴ���*/
void Dictiory::AddNewWords(struct words *head, string s)
{
	struct words *temp, *tail = head, *search = head;
	for (; search->next;) {  //���������Ƿ��Ѵ��ڴ�����������
		if (s == search->word) {
			search->count++;
			return;
		}
		search = search->next;
	}
	temp = new struct words;
	if (!temp) {
		cout << "error001��û���㹻���ڴ��Ŵ��" << endl;
	}
	else {
		for (; tail->next;) {
			tail = tail->next;
		}
		temp->word = s;
		temp->count++;
		tail->next = temp;    //��ԭ���������һ��β�͵�ָ��ָ���½�����
		temp->next = NULL;		//�½�����β�͸�ֵ��
	}
};

/*��������±�*/
void Dictiory::PrintToTxt(struct words *head, string s) {
	fcin.open(s.c_str());//����һ��ָ������C�ַ�����ָ�룬�����뱾String����ͬ
	struct words *temp = head;
	for (; temp;) {
		fout << temp->word << "  " << temp->count << endl;
		temp = temp->next;
	}
}


/*�������ܣ���ʼ��vector��������ȡ�ļ�*/
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

/*�������ܣ�ͳ���ַ������Բ��Ϊ�����ؼ���*/
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

/*�������ܣ���ȡ�ؼ��ֺ󣬰ѵڹؼ����еڶ��������ַ��浽�ؼ��������Ӧλ����*/
void Dictiory::AddWord(string str, int k)
{
	if (str.length() > H[k].size)
	{
		H[k].size = str.length();
		Second *t = new Second(str);  //��ȡ�ؼ����еڶ����ַ�
		H[k].W.push_back(t);	//���ؼ����еڶ����ַ��浽�ؼ��������Ӧλ����
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
	for (i = 0; i < strlen(cstr); i++)  //strlen(s)�����ַ�s�ĳ���,������'\0'��NULL
		n = n * 10 + cstr[i] - '0';
	return n;
}

/*�������ܣ� ��ȡdictionary�еĴ���ؼ��� */
void Dictiory::LoadDic()
{
	char cstr[maxwordlen];
	string str;
	int i, j, k = 0, wordnumber;
	while (fin.getline(cstr, maxwordlen))/*�������fin����ȡ���maxwordlen-1�ַ������ַ��Ŵ�����cstr�У�
										 �����ַ������������ַ���β������ڲ���maxwordlen-1�ַ�ʱ�������з����ļ�������ʱ������
										 getline(char *s,streamsize n,char delim)�Ǹ��߼����÷��������ָ���ַ���delim��Ϊ������Ƿ���*/
	{
		i = (unsigned char)cstr[0] - s1; //�ַ��������Ϊunsigned char �ҳ�����int��ͬ,����Ӽ���������unsigned int����
		j = (unsigned char)cstr[1] - s2;
		hash[i][j] = k;
		H[k].key = cstr;
		wordnumber = GetNum();
		for (i = 0; i < wordnumber; i++)  //ѭ��������txt�ж�ȡ�������֣�����Ӧ�����Ĺؼ��ִ�ŵ��ؼ���������
		{
			fin.getline(cstr, maxwordlen);
			str = cstr;
			str = str.substr(2, str.length() - 2);	//substr(startnum,countnum) �����ַ�����startnumΪ�ַ�������ʼλ�ã�countnumΪ�����ַ���Ŀ		 
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

/*���ַ�����һ�������ַ���Ӧλ��Ѱ�Һ���Ĺؼ����Ƿ�����ֵ���*/
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
	fcin.open(s.c_str());//����һ��ָ������C�ַ�����ָ�룬�����뱾String����ͬ
	char cstr[maxwordlen];
	string str, sstr;
	int i, j, startpos, endpos;
	char c;
	while (fcin.read(&c, sizeof(char)))  //����������ͨ����һֱ������������ֹͣ���룬ÿ������Ķ���һ�ξ��ӣ�
	{
		if (!IsC(c))  //�ж��Ƿ�Ϊ�ֵ��е��ַ�
		{
			if (!str.empty())	//�ж��Ƿ�Ϊ��
			{
				cout << str << " " << str.length() << endl;  //����Ļ����ַ�����ռ����
				startpos = 0, endpos = str.length();  //endpos�����ַ����ĳ���
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
							string word = str.substr(2, str.length() - 2);  //��ȡ�ؼ��ֵڶ��������ַ�������ַ�
							int in = BinarySearch(word, hash[i][j]);  //ͳ���ַ������Բ��Ϊ�����ؼ���
							if ((in != -1) && IsWord(word, hash[i][j], in))  //���ж���ѡ�ַ������йؼ���ʱ
							{
								stk.push(H[hash[i][j]].key + word);   //stk����Ѿ�ȷ��Ϊ����Ĺؼ���
								startpos += str.length();
								str = sstr;
								sstr.clear();
							}
							else
							{
								sstr = sstr + str.substr(0, 2);  //sstr����ַ�����һ�������ַ�
								str = str.substr(2, str.length() - 2);	//str����ַ�������һ�������ַ�����������ַ���  
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
					AddNewWords(head, stk.top());  //����µ��ʴ浽������
					stk.pop();
				}
			}
			str.clear();
			str += c;
			while (fcin.read(&c, sizeof(char)) && !IsC(c))
				str += c;
			//	fout << str << endl;   //���ļ���������źͻ��з�
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
	PrintToTxt(head, s); //���ֺõĴ�������ı��ļ�
}

int main()
{
	Dictiory D("dictiory.txt", "data.txt");
	D.SegmentWord("sou.txt");
	system("pause");
	return 0;
}



