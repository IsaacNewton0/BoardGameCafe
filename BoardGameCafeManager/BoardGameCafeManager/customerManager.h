#pragma once
#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

//고객 개인의 정보
class Customer         //Customer information class
{
private:
	string name, ph;// name(customer name), ph(customer phone number)
	int visit;      //customer visit time
	int money, year, isAdult;// 가상함수를 위한 변수(의미 없음)
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
	int year, money;//year : 태어난 연도,money : 가격
	int isAdult; // 성인 여부 체크 변수
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
	int year, money;//year : 태어난 연도,money : 가격
	int isAdult; // 성인 여부 체크 변수
public:
	Teen(int customerYear, string name, string ph)
		:Customer(name, ph), year(customerYear), money(1500), isAdult(1) { }
	int GetMoney();
	int GetYear();
	int GetIsAdult();
	void ShowInfo();
};

//고객 전체의 정보 관리
class CustomerManager
{
private:
	Customer *head, *last;

public:

	CustomerManager();

	/*Operator*/
	void TeenCustomerRegister(string name, string ph,int customerYear);//청소년 사용자 등록
	void AdultCustomerRegister(string name, string ph, int customerYear);//성인 사용자 등록
	void CustomerList();//사용자 목록 출력
	void CustomerSearch(string searchStr, string mod);// 사용자 검색
	int IsAdult(string searchStr, string mod);// 청소년 성인 여부 체크(성인 : 2, 청소년 : 1, 검색 실패 ; 0)
	void CustomerDelete(string searchStr, string mod);// 사용자 삭제
	void ShowMenu();// 메뉴 출력
	void CustomerSave(string filename);// 사용자 목록 파일로 저장
	void CustomerLoad(string filename);// 사용자 목록 파일 읽어오기
};
#endif // !CUSTOMERMANAGER_H