#pragma once

#include <iostream>
#include <string>

class Seat
{
private:
	int number;//�ڸ��� �ɾ��ִ� ��� ��
	std::string line, name, game;//�ڸ� ��ġ : line / �մ� �̸� : name / ī�信�� �� ���� �̸� : game
	Seat* next;//linked list node
	Seat *head, *last;//linked list head, last
public:
	Seat() { ; };

	//setter funtion
	void setNumber(int n);
	void setLine(std::string l);
	void setName(std::string n);
	void setNext(Seat *next);

	//getter funtion
	int getNumber();
	std::string getLine();
	std::string getName();
	Seat* getNext();

	//��� �Լ�
	void SeatAdd(std::string line, std::string name, int number);//����� ���(name : �մ� �̸�, line : �ڸ�, number : ��� ��)
	void SeatList();//����� ����Ʈ ���
	void SeatSearch(std::string searchStr, std::string mod);//����� �˻�(searchStr�� �̸� �Ǵ� �ڸ�, mods == (line) || (name))
	void SeatDelete(std::string searchStr, std::string mod);//����� ����
};