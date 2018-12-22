#pragma once

#include <iostream>
#include <string>

class Seat
{
private:
	std::string line, name;//자리 위치 : line / 손님 이름 : name
	Seat* next;//linked list node
	Seat *head, *last;//linked list head, last
public:
	Seat() { ; };

	//setter funtion
	void setLine(std::string l);
	void setName(std::string n);
	void setNext(Seat *next);

	//getter funtion
	std::string getLine();
	std::string getName();
	Seat* getNext();

	//기능 함수
	void SeatAdd(std::string line, std::string name);//사용자 등록(name : 손님 이름, line : 자리)
	void SeatList();//사용자 리스트 출력
	void SeatSearch(std::string searchStr, std::string mod);//사용자 검색(searchStr은 이름 또는 자리, mods == (line) || (name))
	void SeatDelete(std::string searchStr, std::string mod);//사용자 삭제
};