#include"pch.h"
#include<iostream>
#include<string>
#include"customerManager.h"
#include<fstream>
using std::string;
using std::cout;
using std::endl;

/*Class Customer*/

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

/*Operator*/
void Customer::ShowInfo()
{
	cout << "�̸�: " << GetName() << " �޴��� ��ȣ: " << GetPh() << endl;
}

/*Class CustomerManager*/
/*Constructor*/
CustomerManager::CustomerManager()// head �ʱ�ȭ
{
	head = new Customer;
	head->SetNext(NULL);
	head->SetName("");
	head->SetPh("");
}

/*Operator*/
void CustomerManager::CustomerRegister(string name,string ph)
{
	Customer* customer = new Customer;
	if (head->GetNext() == NULL)// head,last �ʱ�ȭ
	{
		head->SetNext(customer);
		last = customer;
	}
	else                       //last �����̱�
	{
		last->SetNext(customer);
		last = customer;
		last->SetNext(NULL);
	}
	customer->SetName(name); customer->SetPh(ph);
}
void CustomerManager::CustomerList()
{
	if (head->GetNext() == NULL)
		return;
	Customer *customer = head->GetNext();
	while (true)// ������ ���
	{
		customer->ShowInfo();
		if (customer->GetNext() == NULL)
			return;
		customer = customer->GetNext();
	}
}
void CustomerManager::CustomerSearch(string searchStr, string mod)
{
	Customer *customer =head->GetNext();
	string(Customer::*func)() = NULL;//����Լ� ������ ���
	//�˻� ���
	if (mod == "name")
		func = &Customer::GetName;
	else if(mod == "phone")
		func = &Customer::GetPh;

	while (true) //�մ� �˻�
	{
		if ((customer->*func)() == searchStr)
		{
			customer->ShowInfo();
			return;
		}
		if (customer->GetNext() == NULL)
		{
			cout << "��ϵ� ȸ���� �����ϴ�." << endl;
			return;
		}
		customer = customer->GetNext();
	}
}
void CustomerManager::CustomerDelete(string searchStr, string mod)
{
	Customer *firstIndex, *lastIndex;
	firstIndex = lastIndex = head;// firstIndex, lastIndex �ʱ�ȭ
	string(Customer::*func)() = NULL;//����Լ� ������ ���
	//�˻� ���
	if (mod == "name")
		func = &Customer::GetName;
	else if (mod == "phone")
		func = &Customer::GetPh;

	while (true)//�� ���� ����
	{
		if ((firstIndex->*func)() == searchStr)
		{
			lastIndex->SetNext(firstIndex->GetNext());
			delete firstIndex;
			cout << "������" << endl;
			return;
		}
		if (firstIndex->GetNext() == NULL)
		{
			cout << "��ϵ� ȸ���� �����ϴ�." << endl;
			return;
		}
		// firstIndex, lastIndex ��ĭ�� �����̱�
		lastIndex = firstIndex;
		firstIndex = firstIndex->GetNext();
	}
}
void CustomerManager::ShowMenu()
{
	cout << "1. ����� ���" << endl;
	cout << "1. ����� ��� ���" << endl;
	cout << "1. ����� �˻�" << endl;
	cout << "1. ����� ����" << endl;
}
void CustomerManager::CustomerSave(string filename)
{
	std::fstream fileStream;
	fileStream.open(filename, std::ios::out);
	if (head->GetNext() == NULL)
		return;
	Customer *customer = head->GetNext();
	// �� ������ ���Ͽ� ����(�Ź� ���Ϸε��� ������)
	while (true)
	{
		fileStream << customer->GetName() << " " << customer->GetPh() << endl;
		if (customer->GetNext() == NULL)
			return;
		customer = customer->GetNext();
	}
	fileStream.close();

	
}
void CustomerManager::CustomerLoad(string filename)
{
	std::fstream fileStream;
	fileStream.open(filename, std::ios::in);
	if (!fileStream.is_open())//������ ������ ���
	{
		cout << "������ �����ϴ�." << endl;
		return;
	}
	string name, ph;
	//���� �ε�(�Ź� �ε��ؼ� ��ũ�帮��Ʈ�� ������)
	while (true)
	{
		fileStream >> name >> ph;
		if (fileStream.eof())
			break;
		CustomerRegister(name, ph);
	}
	fileStream.close();
}