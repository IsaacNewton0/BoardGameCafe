#pragma once

#include <iostream>
#include <string>

class Seat
{
private:
	int number;//자리에 앉아있는 사람 수
	std::string line, name, game;//자리 위치 : line / 손님 이름 : name
	Seat* next;//linked list node
	Seat *head, *last;//linked list head, last
public:
	Seat() { ; };

	//setter funtion
	void setGame(std::string g);//game : 할 게임
	void setNumber(int n);//number : 그 자리에 있는 사람의 수
	void setLine(std::string l);//line : 예약된 자리
	void setName(std::string n);//name : 자리를 예약한 사람의 이름
	void setNext(Seat *next);

	//getter funtion
	std::string getGame();
	int getNumber();
	std::string getLine();
	std::string getName();
	Seat* getNext();

	//기능 함수
	void SeatAdd(std::string line, std::string name, int number, std::string game);//사용자 등록(name : 손님 이름, line : 자리, number : 사람 수, game : 할 게임)
	void SeatList();//사용자 리스트 출력
	void SeatSearch(std::string searchStr, std::string mod);//사용자 검색(searchStr은 이름 또는 자리, mods == (line) || (name))
	void SeatDelete(std::string searchStr, std::string mod);//사용자 삭제
	void Showmenu();//자리 메뉴 출력
};