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
	cout << "이름: " << GetName() << " 휴대폰 번호: " << GetPh() << endl;
}

/*Class CustomerManager*/
/*Constructor*/
CustomerManager::CustomerManager()// head 초기화
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
	if (head->GetNext() == NULL)// head,last 초기화
	{
		head->SetNext(customer);
		last = customer;
	}
	else                       //last 움직이기
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
	while (true)// 고객정보 출력
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
	string(Customer::*func)() = NULL;//멤버함수 포인터 사용
	//검색 모드
	if (mod == "name")
		func = &Customer::GetName;
	else if(mod == "phone")
		func = &Customer::GetPh;

	while (true) //손님 검색
	{
		if ((customer->*func)() == searchStr)
		{
			customer->ShowInfo();
			return;
		}
		if (customer->GetNext() == NULL)
		{
			cout << "등록된 회원이 없습니다." << endl;
			return;
		}
		customer = customer->GetNext();
	}
}
void CustomerManager::CustomerDelete(string searchStr, string mod)
{
	Customer *firstIndex, *lastIndex;
	firstIndex = lastIndex = head;// firstIndex, lastIndex 초기화
	string(Customer::*func)() = NULL;//멤버함수 포인터 사용
	//검색 모드
	if (mod == "name")
		func = &Customer::GetName;
	else if (mod == "phone")
		func = &Customer::GetPh;

	while (true)//고객 정보 삭제
	{
		if ((firstIndex->*func)() == searchStr)
		{
			lastIndex->SetNext(firstIndex->GetNext());
			delete firstIndex;
			cout << "삭제됨" << endl;
			return;
		}
		if (firstIndex->GetNext() == NULL)
		{
			cout << "등록된 회원이 없습니다." << endl;
			return;
		}
		// firstIndex, lastIndex 한칸씩 움직이기
		lastIndex = firstIndex;
		firstIndex = firstIndex->GetNext();
	}
}
void CustomerManager::ShowMenu()
{
	cout << "1. 사용자 등록" << endl;
	cout << "1. 사용자 목록 출력" << endl;
	cout << "1. 사용자 검색" << endl;
	cout << "1. 사용자 삭제" << endl;
}
void CustomerManager::CustomerSave(string filename)
{
	std::fstream fileStream;
	fileStream.open(filename, std::ios::out);
	if (head->GetNext() == NULL)
		return;
	Customer *customer = head->GetNext();
	// 고객 정보를 파일에 저장(매번 파일로드후 저장함)
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
	if (!fileStream.is_open())//파일이 없으면 경고
	{
		cout << "파일이 없습니다." << endl;
		return;
	}
	string name, ph;
	//파일 로드(매번 로드해서 링크드리스트에 저장함)
	while (true)
	{
		fileStream >> name >> ph;
		if (fileStream.eof())
			break;
		CustomerRegister(name, ph);
	}
	fileStream.close();
}