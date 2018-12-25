// 기말 과제 / 보드 게임 카페 만들기 / 좌석 예약 프로그램 / class Seat

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

//기능 함수
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
		if (seat == NULL) // seat초기값 설정
			seat = head;
		if (line == seat->getLine())
		{
			money = (a_n * 2500 * u_t) + (c_n * 2000 * u_t);
			seat->setName(name), seat->setNumber_a(a_n), seat->setNumber_c(c_n),
				seat->setGame(g), seat->setTime(u_t), seat->setMoney(money);//각 변수의 저장
			check = true;
		}
		if (seat->getNext() == NULL)// 마지막 노드에 도달하면 함수 종료
		{
			if (check = false)
			{
				std::cout << "예약된 자리가 없습니다.\n";
				return;
			}
			else
			{
				std::cout << "예약되었습니다.\n";
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
		if (head == NULL)//리스트에 아무것도 없을 때 (head 가 null일때 오류 방지)
		{
			std::cout << "예약 인원이 없습니다.\n";
			return;
		}
		if (seat == NULL) // seat초기값 설정
			seat = head;
		if (seat->getNumber_a() != 0)
		{
			std::cout << "자리 : " << seat->getLine() << "\t이름 : " << seat->getName() //예약된 자리, 이름, 인원수, 할 게임 리스트로 출력
				<< "\t인원수 (어른, 청소년): " << seat->getNumber_a() << ", " << seat->getNumber_c()
				<< "\t게임 : " << seat->getGame() << "\t이용 시간 : " << seat->getTime()
				<< "\t요금 : " << seat->getMoney() << std::endl;
			cnt++;
		}
		if (seat->getNext() == NULL)// 마지막 노드에 도달하면 함수 종료
		{
			if (cnt == 0)
			{
				std::cout << "예약된 자리가 없습니다.\n";
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
	std::string(Seat::*func)() = NULL;//멤버함수포인터사용
	if (mod == "line" || mod == "Line")
		func = &Seat::getLine;
	else if (mod == "name" || mod == "Name")
		func = &Seat::getName;
	Seat *seat = NULL;
	while (true)
	{
		if (seat == NULL) // seat초기값 설정
			seat = head;
		if (searchStr == (seat->*func)())//
			std::cout << "자리 : " << seat->getLine() << "\t이름 : " << seat->getName() << "\t인원 수 (어른, 청소년): "
			<< seat->getNumber_a() << ", " << seat->getNumber_c() << "\t게임 : " << seat->getGame()
			<< "\t이용 시간 : " << seat->getTime() << "\t요금 : " << seat->getMoney() << std::endl;
		if (seat->getNext() == NULL)// 마지막 노드에 도달하면 함수 종료
			return;
		seat = seat->getNext();
	}
};
void Seat::SeatDelete(std::string searchStr, std::string mod)
{
	std::string(Seat::*func)() = NULL; //멤버함수포인터사용
	if (mod == "line" || mod == "Line")
		func = &Seat::getLine;
	else if (mod == "name" || mod == "Name")
		func = &Seat::getName;
	Seat *firstIndex, *lastIndex;
	firstIndex = lastIndex = NULL;
	while (true)
	{
		if (firstIndex == NULL) // seat 초기값 설정
		{
			firstIndex = head;
			lastIndex = head;
		}
		if (searchStr == (firstIndex->*func)())//seat값 찾아서 삭제
		{
			lastIndex->setNext(firstIndex->getNext());
			delete firstIndex;
			firstIndex = NULL;
			std::cout << "삭제가 완료되었습니다.\n";
			return;
		}
		if (firstIndex->getNext() == NULL)// 마지막 노드에 도달하면 함수 종료
			return;

		lastIndex = firstIndex;
		firstIndex = firstIndex->getNext();
	}
};
void Seat::Showmenu()
{
	std::cout << "1. 자리 예약 등록\n";
	std::cout << "2. 자리 예약 리스트\n";
	std::cout << "3. 자리 예약 검색\n";
	std::cout << "4. 자리 예약 삭제\n";
	std::cout << "0. 돌아가기\n";
};
void Seat::SeatSave(int width, int length)
{
	std::fstream fileStream;
	fileStream.open("reservation.txt", std::ios::out);
	// 고객 정보를 파일에 저장(매번 파일로드후 저장함)
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
	if (!fileStream.is_open())//파일이 없으면 경고
		return;
	std::string line;
	//파일 로드(매번 로드해서 링크드리스트에 저장함)
	for (int i = 0; i < width * length; i++)
	{
		fileStream >> line;
		SeatLine(line);
	}
	fileStream.close();
}