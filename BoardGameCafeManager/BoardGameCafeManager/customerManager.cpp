#include"pch.h"
#include<iostream>
#include"customerManager.h"

/*Setter Function*/
void Customer::SetName(string name) { this->name = name; }
void Customer::SetPh(string ph) { this->ph = ph; }
void Customer::SetVisit(int visit) { this->visit = visit; }
void Customer::SetNext(Customer* next) { this->next = next; }

/*Getter Function*/
string Customer::GetName() { return name; }
string Customer::GetPh() { return ph; }
int Customer::GetVisit() { return visit; }
Customer* Customer::GetNext() { return next; }

/*���۷�����*/
void Customer::CustomerRegister(string name, string ph)
{
	Customer * customer = new Customer;
	if (head == NULL)     //head,last pointer setting
	{
		head = customer;
		last = customer;
	}
	else   //pointing next customer
	{
		last->SetNext(customer);
		last = customer;
	}
	//string name, ph;
	//std::cout << "�̸� �Է�: "; std::cin >> name;
	//std::cout << "��ȭ��ȣ �Է�: "; std::cin >> ph;

	customer->SetName(name); customer->SetPh(ph);
}

void Customer::Customerlist()
{
	Customer *customer = NULL;
	while (true)
	{
		if (customer == NULL) // customer�ʱⰪ ����
			customer = head;
		std::cout << "�� �̸�:" << customer->GetName() << " ��ȭ��ȣ: " << customer->GetPh() << std::endl;
		if (customer->GetNext() == NULL)// ������ ��忡 �����ϸ� �Լ� ����
			return;
		customer = customer->GetNext();
	}
}

void Customer::CustomerSearch(string searchStr, string mod)
{
	string(Customer::*func)() = NULL;//����Լ������ͻ��
	if (mod == "phone")
		func = &Customer::GetPh;
	else if (mod == "name")
		func = &Customer::GetName;
	Customer *customer = NULL;
	while (true)
	{
		if (customer == NULL) // customer�ʱⰪ ����
			customer = head;
		if(searchStr == (customer->*func)())
		std::cout << "�� �̸�:" << customer->GetName() << " ��ȭ��ȣ: " << customer->GetPh() << std::endl;
		if (customer->GetNext() == NULL)// ������ ��忡 �����ϸ� �Լ� ����
			return;
		customer = customer->GetNext();
	}
}

void Customer::CustomerDelete(string searchStr, string mod) 
{
	string(Customer::*func)() = NULL;//����Լ������ͻ��
	if (mod == "phone")
		func = &Customer::GetPh;
	else if (mod == "name")
		func = &Customer::GetName;
	Customer *firstIndex, *lastIndex;
	firstIndex = lastIndex = NULL;
	while (true)
	{
		if (firstIndex == NULL) // customer�ʱⰪ ����
			firstIndex = head;
		if (searchStr == (firstIndex->*func)())
		{
			lastIndex->SetNext(firstIndex->GetNext());
			delete firstIndex;
			return;
		}
		if (firstIndex->GetNext() == NULL)// ������ ��忡 �����ϸ� �Լ� ����
			return;

		lastIndex = firstIndex;
		firstIndex = firstIndex->GetNext();
	}
}