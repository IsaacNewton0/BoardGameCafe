#pragma once

#include <iostream>
#include <string>

class Seat
{
protected:
	int wid, hig, time, money, a_number, c_number;//�ڸ��� �ɾ��ִ� ��� ��
	std::string line, name, game, age;//�ڸ� ��ġ : line / �մ� �̸� : name
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
	void SeatAdd(std::string line, std::string name, std::string game, int use_time, int a_n, int c_n);//����� ���(name : �մ� �̸�, line : �ڸ�, number : ��� ��, game : �� ����)
	void SeatSave(int width, int length);
	void SeatLoad(int width, int length);
	void SeatList();//����� ����Ʈ ���
	void SeatSearch(std::string searchStr, std::string mod);//����� �˻�(searchStr�� �̸� �Ǵ� �ڸ�, mods == (line) || (name))
	void SeatDelete(std::string searchStr, std::string mod);//����� ����
	void Showmenu();
};