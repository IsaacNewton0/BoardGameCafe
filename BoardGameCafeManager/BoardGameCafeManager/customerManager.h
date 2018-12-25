#pragma once
#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

//�� ������ ����
class Customer         //Customer information class
{
private:
	string name, ph;// name(customer name), ph(customer phone number)
	int visit;      //customer visit time
	int money, year, isAdult;// �����Լ��� ���� ����(�ǹ� ����)
	Customer* next; //Linked list node

public:
	Customer(){}
	Customer(string customerName, string customerPh) :name(customerName), ph(customerPh) {}


	/*Setter Function*/
	void SetName(string name);
	void SetPh(string ph);
	void SetVisit(int visit);
	void SetNext(Customer* next);

	/*Getter Function*/
	string GetName();
	string GetPh();
	int GetVisit();
	Customer* GetNext();

	/*Operator*/
	//void ShowInfo();

	/*Virtual function*/
	virtual int GetMoney() { return money; }
	virtual void ShowInfo() { return; }
	virtual int GetYear() { return year; }
	virtual int GetIsAdult() { return isAdult; }
};

class Adult : public Customer
{
private:
	int year, money;//year : �¾ ����,money : ����
	int isAdult; // ���� ���� üũ ����
public:
	Adult(int customerYear, string name, string ph)
		:Customer(name, ph), year(customerYear), money(2000),isAdult(2) { }
	int GetMoney();
	int GetYear();
	int GetIsAdult();
	void ShowInfo();
};

class Teen : public Customer
{
private:
	int year, money;//year : �¾ ����,money : ����
	int isAdult; // ���� ���� üũ ����
public:
	Teen(int customerYear, string name, string ph)
		:Customer(name, ph), year(customerYear), money(1500), isAdult(1) { }
	int GetMoney();
	int GetYear();
	int GetIsAdult();
	void ShowInfo();
};

//�� ��ü�� ���� ����
class CustomerManager
{
private:
	Customer *head, *last;

public:

	CustomerManager();

	/*Operator*/
	void TeenCustomerRegister(string name, string ph,int customerYear);//û�ҳ� ����� ���
	void AdultCustomerRegister(string name, string ph, int customerYear);//���� ����� ���
	void CustomerList();//����� ��� ���
	void CustomerSearch(string searchStr, string mod);// ����� �˻�
	int IsAdult(string searchStr, string mod);// û�ҳ� ���� ���� üũ(���� : 2, û�ҳ� : 1, �˻� ���� ; 0)
	void CustomerDelete(string searchStr, string mod);// ����� ����
	void ShowMenu();// �޴� ���
	void CustomerSave(string filename);// ����� ��� ���Ϸ� ����
	void CustomerLoad(string filename);// ����� ��� ���� �о����
};
#endif // !CUSTOMERMANAGER_H