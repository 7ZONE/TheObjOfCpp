/*
Programing : Virtual And Class Point 
Date :2017-5-9
Author : zzq
*/
#include"stdafx.h"
#include<iostream>
#include<string>

using namespace std;
//��������ҵ����ɸ�������Ӧ�ĳ�Ա���������캯�������麯��ʵ�֣�����������ָ�룬����õ��������ֵĹ��ʺ�����

class TTroop
{

private:
	float base_pay, allowance;
	string weapon;
public:
	TTroop(string w, float payment, float allowancee)
	{
		weapon = w;
		base_pay = payment;
		allowance = allowancee;
	}

	virtual void display_pay()
	{
		cout << "pay is " << base_pay + allowance << endl;
		cout << "weapon is " << weapon << endl;
	
	}

};

//base_pay+allowance*1.3
//weapon is Aircraft carrier
class TNavy :public TTroop
{

private:
	float base_pay, allowance;
	string weapon;
public:
	TNavy(string w, float payment, float allowancee) :TTroop(w, payment, allowancee)
	{
		weapon = w;
		base_pay = payment;
		allowance = allowancee;
	}
void display_pay()
	{
		cout << "Navy's payment is " << (base_pay + allowance)*1.3 << endl;
		cout << "Navy's weapon is " << weapon << endl;
	}


};
//base_pay+allowance
//weapon is Tank
class TArmy :public TTroop
{
private:
	float base_pay, allowance;
	string weapon;
public:

	TArmy(string w, float payment, float allowancee) :TTroop(w, payment, allowancee)
	{
		weapon = w;
		base_pay = payment;
		allowance = allowancee;
	}
	 void display_pay()
	{
		cout << "Army's payment is " << base_pay + allowance << endl;
		cout << "Army's weapon is " << weapon << endl;
	}

};
//base_pay+allwoance+500
//weapon is battleplane
class TAirforce :public TTroop
{
private:
	float base_pay, allowance;
	string weapon;
public:

	TAirforce(string w, float payment, float allowancee) :TTroop(w, payment, allowancee)
	{
		weapon = w;
		base_pay = payment;
		allowance = allowancee;
	}
 void display_pay()
	{
		cout << "Airforce's payment is :" << base_pay + allowance +500<< endl;
		cout << "Airforce's weapon is : " << weapon << endl;
	}

};
//base_pay+allwoance+1500
//weapon is Missile
class TRocketForce :public TTroop
{
private:
	float base_pay, allowance;
	string weapon;
public:

	TRocketForce(string w, float payment, float allowancee) :TTroop(w, payment, allowancee)
	{
		weapon = w;
		base_pay = payment;
		allowance = allowancee;
	}
 void display_pay()
	{
		cout << "RocketForce's payment is " << base_pay + allowance + 1500 << endl;
		cout << "RocketForce's weapon is " << weapon << endl;
	}

};

int main()
{
	TTroop *A_P;
	TNavy Y1( "Aircraft carrier", 9999, 10000);
	TArmy M1("Tank", 9999, 10000);
	TAirforce M2("battleplane", 9999, 10000);
	TRocketForce M3("Missile", 9999, 10000);

	A_P = &Y1;
	A_P->display_pay();
	A_P = &M1;
	A_P->display_pay();
	A_P = &M2;
	A_P->display_pay();
	A_P = &M3;
	A_P->display_pay();
	return 0;
}
