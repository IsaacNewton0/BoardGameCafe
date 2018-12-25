#pragma once

#include <iostream>
#include <string>

class Seat
{
private:
	int number, wid, hig;//자리에 앉아있는 사람 수
	std::string line, name, game;//자리 위치 : line / 손님 이름 : name
	Seat* next;//linked list node
	Seat *head, *last;//linked list head, last
public:
	Seat() { ; };

	//setter funtion
	void setGame(std::string g);
	void setNumber(int n);
	void setLine(std::string l);
	void setName(std::string n);
	void setNext(Seat *next);

	//getter funtion
	std::string getGame();
	int getNumber();
	std::string getLine();
	std::string getName();
	Seat* getNext();

	//기능 함수
	void SeatLine(std::string line);//자리 셋팅 함수
	void SeatAdd(std::string line, std::string name, int number, std::string game);//사용자 등록(name : 손님 이름, line : 자리, number : 사람 수, game : 할 게임)
	void SeatList();//사용자 리스트 출력
	void SeatSearch(std::string searchStr, std::string mod);//사용자 검색(searchStr은 이름 또는 자리, mods == (line) || (name))
	void SeatDelete(std::string searchStr, std::string mod);//사용자 삭제
	void Showmenu();//메뉴 출력
	void SeatSave(int width, int length);//자리 저장하기
	void SeatLoad(int width, int length);//자리 로드하기
};