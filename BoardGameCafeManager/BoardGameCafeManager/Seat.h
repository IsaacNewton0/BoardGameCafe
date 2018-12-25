#pragma once

#include <iostream>
#include <string>

class Seat
{
private:
	int number;//�ڸ��� �ɾ��ִ� ��� ��
	std::string line, name, game;//�ڸ� ��ġ : line / �մ� �̸� : name
	Seat* next;//linked list node
	Seat *head, *last;//linked list head, last
public:
	Seat() { ; };

	//setter funtion
	void setGame(std::string g);//game : �� ����
	void setNumber(int n);//number : �� �ڸ��� �ִ� ����� ��
	void setLine(std::string l);//line : ����� �ڸ�
	void setName(std::string n);//name : �ڸ��� ������ ����� �̸�
	void setNext(Seat *next);

	//getter funtion
	std::string getGame();
	int getNumber();
	std::string getLine();
	std::string getName();
	Seat* getNext();

	//��� �Լ�
	void SeatAdd(std::string line, std::string name, int number, std::string game);//����� ���(name : �մ� �̸�, line : �ڸ�, number : ��� ��, game : �� ����)
	void SeatList();//����� ����Ʈ ���
	void SeatSearch(std::string searchStr, std::string mod);//����� �˻�(searchStr�� �̸� �Ǵ� �ڸ�, mods == (line) || (name))
	void SeatDelete(std::string searchStr, std::string mod);//����� ����
	void Showmenu();//�ڸ� �޴� ���
};