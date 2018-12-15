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
	Customer *head, *last; // 링크드 리스트 헤드,라스트

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

	/*기능 함수*/
	void CustomerRegister(string name, string ph);//사용자 등록(name은 사용자이름,ph은 사용자 전화번호)
	void Customerlist();//사용자 목록
	void CustomerSearch(string searchStr,string mod);//사용자 검색(searchStr은 이름 또는 전화번호 mod는 검색 모드 :mod = "phone" or "name")
	void CustomerDelete(string searchStr, string mod);//사용자 삭제(searchStr은 이름 또는 전화번호 mod는 검색 모드 :mod = "phone" or "name")
};
#endif // !CUSTOMERMANAGER_H