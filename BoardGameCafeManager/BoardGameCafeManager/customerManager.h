#pragma once
#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include<iostream>
#include<string>

using std::string;

class Customer         //Customer information class
{
private:
	string name,ph;// name(customer name), ph(customer phone number)
	int visit;      //customer visit time
	Customer* next; //Linked list node
	Customer *head, *last; // ��ũ�� ����Ʈ ���,��Ʈ

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

	/*��� �Լ�*/
	void CustomerRegister(string name, string ph);//����� ���(name�� ������̸�,ph�� ����� ��ȭ��ȣ)
	void Customerlist();//����� ���
	void CustomerSearch(string searchStr,string mod);//����� �˻�(searchStr�� �̸� �Ǵ� ��ȭ��ȣ mod�� �˻� ��� :mod = "phone" or "name")
	void CustomerDelete(string searchStr, string mod);//����� ����(searchStr�� �̸� �Ǵ� ��ȭ��ȣ mod�� �˻� ��� :mod = "phone" or "name")
};
#endif // !CUSTOMERMANAGER_H