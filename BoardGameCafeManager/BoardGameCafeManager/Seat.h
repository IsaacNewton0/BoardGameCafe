#pragma once

#include <iostream>
#include <string>

class Seat
{
protected:
	int wid, hig, time, money, a_number, c_number;//자리에 앉아있는 사람 수
	std::string line, name, game, age;//자리 위치 : line / 손님 이름 : name
	Seat* next;//linked list node
	Seat *head, *last;//linked list head, last
public:
	Seat() { ; };

	//setter funtion
	void setGame(std::string g);
	void setNumber_a(int a_n);
	void setNumber_c(int c_n);
	void setTime(int n_t);
	void setAge(std::string age);
	void setMoney(int money);
	void setLine(std::string l);
	void setName(std::string n);
	void setNext(Seat *next);

	//getter funtion
	std::string getGame();
	int getNumber_a();
	int getNumber_c();
	int getTime();
	std::string getAge();
	int getMoney();
	std::string getLine();
	std::string getName();
	Seat* getNext();

	void SeatLine(std::string line);
	void SeatAdd(std::string line, std::string name, std::string game, int use_time, int a_n, int c_n);//사용자 등록(name : 손님 이름, line : 자리, number : 사람 수, game : 할 게임)
	void SeatSave(int width, int length);
	void SeatLoad(int width, int length);
	void SeatList();//사용자 리스트 출력
	void SeatSearch(std::string searchStr, std::string mod);//사용자 검색(searchStr은 이름 또는 자리, mods == (line) || (name))
	void SeatDelete(std::string searchStr, std::string mod);//사용자 삭제
	void Showmenu();
};