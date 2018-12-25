// �⸻ ���� / ���� ���� ī�� ����� / �¼� ���� ���α׷� / class Seat

#include "pch.h"
#include "Seat.h"
#include <iostream>
#include <string>
#include <fstream>

//Setter Function
void Seat::setGame(std::string game) { this->game = game; };
void Seat::setNumber_a(int a_number) { this->a_number = a_number; };
void Seat::setNumber_c(int c_number) { this->c_number = c_number; };
void Seat::setTime(int time) { this->time = time; };
void Seat::setMoney(int money) { this->money = money; };
void Seat::setAge(std::string age) { this->age = age; };
void Seat::setLine(std::string line) { this->line = line; };
void Seat::setName(std::string name) { this->name = name; };
void Seat::setNext(Seat* next) { this->next = next; };

//Getter Function
std::string Seat::getGame() { return game; };
int Seat::getNumber_a() { return a_number; };
int Seat::getNumber_c() { return c_number; };
int Seat::getTime() { return time; };
std::string Seat::getAge() { return age; };
int Seat::getMoney() { return money; };
std::string Seat::getLine() { return line; };
std::string Seat::getName() { return name; };
Seat* Seat::getNext() { return next; };

//��� �Լ�
void Seat::seatMoney(int a_n, int c_n)
{

};
void Seat::SeatLine(std::string line)
{
	Seat *seat = new Seat;

	if (this->head == NULL)  //head,last pointer setting
	{
		this->head = seat;
		this->last = seat;
	}
	else   //pointing next seat
	{
		this->last->setNext(seat);
		this->last = seat;
	}

	seat->setLine(line);
};
void Seat::SeatAdd(std::string line, std::string name, std::string g, int u_t, int a_n, int c_n)
{
	Seat *seat = NULL;
	bool check = false;

	while (true)
	{
		if (seat == NULL) // seat�ʱⰪ ����
			seat = head;
		if (line == seat->getLine())
		{
			money = (a_n * 2500 * u_t) + (c_n * 2000 * u_t);
			seat->setName(name), seat->setNumber_a(a_n), seat->setNumber_c(c_n),
				seat->setGame(g), seat->setTime(u_t), seat->setMoney(money);//�� ������ ����
			check = true;
		}
		if (seat->getNext() == NULL)// ������ ��忡 �����ϸ� �Լ� ����
		{
			if (check = false)
			{
				std::cout << "����� �ڸ��� �����ϴ�.\n";
				return;
			}
			else
			{
				std::cout << "����Ǿ����ϴ�.\n";
				return;
			}
		}

		seat = seat->getNext();
	}
};
void Seat::SeatList()
{
	Seat *seat = NULL;
	int cnt = 0;

	while (true)
	{
		if (head == NULL)//����Ʈ�� �ƹ��͵� ���� �� (head �� null�϶� ���� ����)
		{
			std::cout << "���� �ο��� �����ϴ�.\n";
			return;
		}
		if (seat == NULL) // seat�ʱⰪ ����
			seat = head;
		if (seat->getNumber_a() != 0)
		{
			std::cout << "�ڸ� : " << seat->getLine() << "\t�̸� : " << seat->getName() //����� �ڸ�, �̸�, �ο���, �� ���� ����Ʈ�� ���
				<< "\t�ο��� (�, û�ҳ�): " << seat->getNumber_a() << ", " << seat->getNumber_c()
				<< "\t���� : " << seat->getGame() << "\t�̿� �ð� : " << seat->getTime()
				<< "\t��� : " << seat->getMoney() << std::endl;
			cnt++;
		}
		if (seat->getNext() == NULL)// ������ ��忡 �����ϸ� �Լ� ����
		{
			if (cnt == 0)
			{
				std::cout << "����� �ڸ��� �����ϴ�.\n";
				return;
			}
			else
				return;
		}

		seat = seat->getNext();
	}
};
void Seat::SeatSearch(std::string searchStr, std::string mod)
{
	std::string(Seat::*func)() = NULL;//����Լ������ͻ��
	if (mod == "line" || mod == "Line")
		func = &Seat::getLine;
	else if (mod == "name" || mod == "Name")
		func = &Seat::getName;
	Seat *seat = NULL;
	while (true)
	{
		if (seat == NULL) // seat�ʱⰪ ����
			seat = head;
		if (searchStr == (seat->*func)())//
			std::cout << "�ڸ� : " << seat->getLine() << "\t�̸� : " << seat->getName() << "\t�ο� �� (�, û�ҳ�): "
			<< seat->getNumber_a() << ", " << seat->getNumber_c() << "\t���� : " << seat->getGame()
			<< "\t�̿� �ð� : " << seat->getTime() << "\t��� : " << seat->getMoney() << std::endl;
		if (seat->getNext() == NULL)// ������ ��忡 �����ϸ� �Լ� ����
			return;
		seat = seat->getNext();
	}
};
void Seat::SeatDelete(std::string searchStr, std::string mod)
{
	std::string(Seat::*func)() = NULL; //����Լ������ͻ��
	if (mod == "line" || mod == "Line")
		func = &Seat::getLine;
	else if (mod == "name" || mod == "Name")
		func = &Seat::getName;
	Seat *firstIndex, *lastIndex;
	firstIndex = lastIndex = NULL;
	while (true)
	{
		if (firstIndex == NULL) // seat �ʱⰪ ����
		{
			firstIndex = head;
			lastIndex = head;
		}
		if (searchStr == (firstIndex->*func)())//seat�� ã�Ƽ� ����
		{
			lastIndex->setNext(firstIndex->getNext());
			delete firstIndex;
			firstIndex = NULL;
			std::cout << "������ �Ϸ�Ǿ����ϴ�.\n";
			return;
		}
		if (firstIndex->getNext() == NULL)// ������ ��忡 �����ϸ� �Լ� ����
			return;

		lastIndex = firstIndex;
		firstIndex = firstIndex->getNext();
	}
};
void Seat::Showmenu()
{
	std::cout << "1. �ڸ� ���� ���\n";
	std::cout << "2. �ڸ� ���� ����Ʈ\n";
	std::cout << "3. �ڸ� ���� �˻�\n";
	std::cout << "4. �ڸ� ���� ����\n";
	std::cout << "0. ���ư���\n";
};
void Seat::SeatSave(int width, int length)
{
	std::fstream fileStream;
	fileStream.open("reservation.txt", std::ios::out);
	// �� ������ ���Ͽ� ����(�Ź� ���Ϸε��� ������)
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			fileStream << i + 1 << "-" << j + 1 << std::endl;
		}
	}
	fileStream.close();
}
void Seat::SeatLoad(int width, int length)
{
	std::fstream fileStream;
	fileStream.open("reservation.txt", std::ios::in);
	if (!fileStream.is_open())//������ ������ ���
		return;
	std::string line;
	//���� �ε�(�Ź� �ε��ؼ� ��ũ�帮��Ʈ�� ������)
	for (int i = 0; i < width * length; i++)
	{
		fileStream >> line;
		SeatLine(line);
	}
	fileStream.close();
}