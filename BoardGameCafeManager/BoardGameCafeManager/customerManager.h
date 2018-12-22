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
	void CustomerRegister(string name, string ph);//사용자 등록
	void CustomerList();//사용자 목록 출력
	void CustomerSearch(string searchStr, string mod);// 사용자 검색
	void CustomerDelete(string searchStr, string mod);// 사용자 삭제
	void ShowMenu();// 메뉴 출력
	void CustomerSave(string filename);// 사용자 목록 파일로 저장
	void CustomerLoad(string filename);// 사용자 목록 파일 읽어오기
};
#endif // !CUSTOMERMANAGER_H