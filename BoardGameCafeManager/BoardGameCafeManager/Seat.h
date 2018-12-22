#pragma once

#include <iostream>
#include <string>

class Seat
{
private:
	std::string line, name;//�ڸ� ��ġ : line / �մ� �̸� : name
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

	//��� �Լ�
	void SeatAdd(std::string line, std::string name);//����� ���(name : �մ� �̸�, line : �ڸ�)
	void SeatList();//����� ����Ʈ ���
	void SeatSearch(std::string searchStr, std::string mod);//����� �˻�(searchStr�� �̸� �Ǵ� �ڸ�, mods == (line) || (name))
	void SeatDelete(std::string searchStr, std::string mod);//����� ����
};