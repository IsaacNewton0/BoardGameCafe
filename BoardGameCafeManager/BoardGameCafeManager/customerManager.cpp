#include"pch.h"
#include<iostream>
#include<string>
#include"customerManager.h"
#include<fstream>
#include<time.h>
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
void CustomerManager::AdultCustomerRegister(string name, string ph,int customerYear)
{
	Customer* customer = new Adult(customerYear, name, ph);
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
	
	//customer->SetName(name); customer->SetPh(ph);
}
void CustomerManager::TeenCustomerRegister(string name, string ph, int customerYear)
{
	Customer* customer = new Teen(customerYear, name, ph);
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

	//customer->SetName(name); customer->SetPh(ph);
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
	Customer *customer = head->GetNext();
	string(Customer::*func)() = NULL;//����Լ� ������ ���
	//�˻� ���
	if (mod == "name")
		func = &Customer::GetName;
	else if (mod == "phone")
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
int CustomerManager::IsAdult(string searchStr, string mod)
{
	Customer *customer = head->GetNext();
	string(Customer::*func)() = NULL;//����Լ� ������ ���
	//�˻� ���
	if (mod == "name")
		func = &Customer::GetName;
	else if (mod == "phone")
		func = &Customer::GetPh;

	while (true) //�մ� �˻�
	{
		if ((customer->*func)() == searchStr)
		{
			return customer->GetIsAdult();
		}
		if (customer->GetNext() == NULL)
		{
			cout << "��ϵ� ȸ���� �����ϴ�." << endl;
			return 0;
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
	cout << "***********************" << endl;
	cout << "1. ���� ����� ���" << endl;
	cout << "2. û�ҳ� ����� ���" << endl;
	cout << "3. ����� ��� ���" << endl;
	cout << "4. ����� �˻�" << endl;
	cout << "5. ����� ����" << endl;
	cout << "0. ���ư���" << endl;
	cout << "***********************\n\n" << endl;
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
		fileStream << customer->GetName() << " " << customer->GetPh() << " " << customer->GetYear() << endl;
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
	int year;

	/*���� �����, û�ҳ� ����� ������ ���� �κ�*/
	tm todayYear;
	time_t t = time(NULL);
	localtime_s(&todayYear, &t);
	//���� �ε�(�Ź� �ε��ؼ� ��ũ�帮��Ʈ�� ������)
	while (true)
	{
		fileStream >> name >> ph >> year;
		if (fileStream.eof())//���� ���� ���� �Լ� ����
			break;

		/*���ΰ� û�ҳ��� �����Ͽ� �ٸ��� ��ü ����*/
		if (todayYear.tm_year+1900 - year > 18)
			AdultCustomerRegister(name, ph, year);
		else
			TeenCustomerRegister(name, ph, year);
	}
	fileStream.close();
}

/*Teen Class*/
void Teen::ShowInfo()
{
	cout << "�̸�: " << GetName() << " �޴��� ��ȣ: " << GetPh() << " �¾ �⵵: " << year << endl;
}
int Teen::GetMoney() { return money; }
int Teen::GetYear() { return year; }
int Teen::GetIsAdult() { return isAdult; }

/*Adult Class*/
int Adult::GetMoney() { return money; }
int Adult::GetYear() { return year; }
int Adult::GetIsAdult() { return isAdult; }
void Adult::ShowInfo()
{
	cout << "�̸�: " << GetName() << " �޴��� ��ȣ: " << GetPh() << " �¾ �⵵: " << year << endl;
}