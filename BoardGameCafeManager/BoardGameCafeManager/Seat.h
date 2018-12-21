#pragma once

#include <iostream>
#include <string>

class Seat
{
private:
	std::string line, name;
	Seat* next;
	Seat *head, *last;
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

	//기능 함수
	void SeatAdd(std::string line, std::string name);
	void SeatList();
	void SeatSearch(std::string searchStr, std::string mod);
	void SeatDelete(std::string searchStr, std::string mod);
};