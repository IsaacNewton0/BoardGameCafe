// 기말 과제 / 좌석 예약 프로그램

#include "pch.h"
#include "Seat.h"
#include <iostream>
#include <string>


//Setter Function
void Seat::setGame(std::string game) { this->game = game; };
void Seat::setNumber(int number) { this->number = number; };
void Seat::setLine(std::string line) { this->line = line; };
void Seat::setName(std::string name) { this->name = name; };
void Seat::setNext(Seat* next) { this->next = next; };

//Getter Function
std::string Seat::getGame() { return game; };
int Seat::getNumber() { return number; };
std::string Seat::getLine() { return line; };
std::string Seat::getName() { return name; };
Seat* Seat::getNext() { return next; };

//기능 함수
void Seat::SeatAdd(std::string line, std::string name, int number, std::string g)
{
	Seat *seat = new Seat;

	if (head == NULL)  //head,last pointer setting
	{
		head = seat;
		last = seat;
	}
	else   //pointing next seat
	{
		last->setNext(seat);
		last = seat;
	}

	seat->setLine(line); seat->setName(name), seat->setNumber(number), seat->setGame(g);//각 변수의 저장
};
void Seat::SeatList()
{
	Seat *seat = NULL;

	while (true)
	{
		if (head == NULL)//리스트에 아무것도 없을 때 (head 가 null일때 오류 방지)
		{
			std::cout << "예약 인원이 없습니다.\n";
			return;
		}
		if (seat == NULL) // seat초기값 설정
			seat = head;
		std::cout << "자리 : " << seat->getLine() << "\t이름 : " << seat->getName() //자리와 이름 리스트로 출력
			<< "\t인원수 : " << seat->getNumber() << "\t게임 : " << seat->getGame() << std::endl;
		if (seat->getNext() == NULL)// 마지막 노드에 도달하면 함수 종료
			return;

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
		if (head == NULL)//리스트에 아무것도 없을 때 (head 가 null일때 오류 방지)
		{
			std::cout << "예약 인원이 없습니다.\n";
			return;
		}
		if (seat == NULL) // seat초기값 설정
			seat = head;
		if (searchStr == (seat->*func)())//
			std::cout << "자리 : " << seat->getLine() << "\t이름 : " << seat->getName() << "\t인원 수 : " << seat->getNumber()
			<< "\t게임 : " << seat->getGame() << std::endl;
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
			std::cout << "삭제가 완료되었습니다.\n";
			this->head = NULL;//헤더에 쓰레기값 방지
			return;
		}
		if (firstIndex->getNext() == NULL)// 마지막 노드에 도달하면 함수 종료
			return;

		lastIndex = firstIndex;
		firstIndex = firstIndex->getNext();
	}
};
