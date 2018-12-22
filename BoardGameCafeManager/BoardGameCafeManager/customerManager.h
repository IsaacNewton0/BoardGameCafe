#pragma once
#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

class Customer         //Customer information class
{
private:
	string name, ph;// name(customer name), ph(customer phone number)
	int visit;      //customer visit time
	Customer* next; //Linked list node

public:
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
	void ShowInfo();
};

class CustomerManager
{
private:
	Customer *head, *last;

public:

	CustomerManager();

	/*Operator*/
	void CustomerRegister(string name, string ph);//����� ���
	void CustomerList();//����� ��� ���
	void CustomerSearch(string searchStr, string mod);// ����� �˻�
	void CustomerDelete(string searchStr, string mod);// ����� ����
	void ShowMenu();// �޴� ���
	void CustomerSave(string filename);// ����� ��� ���Ϸ� ����
	void CustomerLoad(string filename);// ����� ��� ���� �о����
};
#endif // !CUSTOMERMANAGER_H