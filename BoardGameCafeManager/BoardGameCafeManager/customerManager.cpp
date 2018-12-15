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

/*오퍼레이터*/
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
	//std::cout << "이름 입력: "; std::cin >> name;
	//std::cout << "전화번호 입력: "; std::cin >> ph;

	customer->SetName(name); customer->SetPh(ph);
}

void Customer::Customerlist()
{
	Customer *customer = NULL;
	while (true)
	{
		if (customer == NULL) // customer초기값 설정
			customer = head;
		std::cout << "고객 이름:" << customer->GetName() << " 전화번호: " << customer->GetPh() << std::endl;
		if (customer->GetNext() == NULL)// 마지막 노드에 도달하면 함수 종료
			return;
		customer = customer->GetNext();
	}
}

void Customer::CustomerSearch(string searchStr, string mod)
{
	string(Customer::*func)() = NULL;//멤버함수포인터사용
	if (mod == "phone")
		func = &Customer::GetPh;
	else if (mod == "name")
		func = &Customer::GetName;
	Customer *customer = NULL;
	while (true)
	{
		if (customer == NULL) // customer초기값 설정
			customer = head;
		if(searchStr == (customer->*func)())
		std::cout << "고객 이름:" << customer->GetName() << " 전화번호: " << customer->GetPh() << std::endl;
		if (customer->GetNext() == NULL)// 마지막 노드에 도달하면 함수 종료
			return;
		customer = customer->GetNext();
	}
}

void Customer::CustomerDelete(string searchStr, string mod) 
{
	string(Customer::*func)() = NULL;//멤버함수포인터사용
	if (mod == "phone")
		func = &Customer::GetPh;
	else if (mod == "name")
		func = &Customer::GetName;
	Customer *firstIndex, *lastIndex;
	firstIndex = lastIndex = NULL;
	while (true)
	{
		if (firstIndex == NULL) // customer초기값 설정
			firstIndex = head;
		if (searchStr == (firstIndex->*func)())
		{
			lastIndex->SetNext(firstIndex->GetNext());
			delete firstIndex;
			return;
		}
		if (firstIndex->GetNext() == NULL)// 마지막 노드에 도달하면 함수 종료
			return;

		lastIndex = firstIndex;
		firstIndex = firstIndex->GetNext();
	}
}