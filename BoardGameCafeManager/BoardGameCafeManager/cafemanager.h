#pragma once
#ifndef CUSTOMSTATISTIC_H
#define CUSTOMSTATISTIC_H

#include<string>
#include<iostream>
#include"customerManager.h"
#include"Seat.h"

using std::cout;
using std::string;
using std::endl;
using std::cin;

class CafeManager
{
private:
	CustomerManager *customerManager;
	Seat *seat;
public:
	CafeManager(CustomerManager *customerManager,Seat *seat)
	{ 
		this->customerManager = customerManager;
		this->seat = seat;
	}
	void CustomerManage()
	{
		while (true)
		{
			string name, ph;//사용자 이름, 휴대폰 번호
			int customerYear;// 사용자 태어난 연도
			int select; //메뉴 선택
			int searchModint;// 검색 모드(숫자)
			string searchModStr;// 검색 모드(문자열)
			string searchStr;// 검색 모드에 따른 검색어

			customerManager->ShowMenu();
			cout << "선택 : "; cin >> select;
			switch (select)
			{
				//성인 사용자 등록
			case 1:
				cout << "사용자 이름 : "; cin >> name;
				cout << "사용자 핸드폰 번호 : "; cin >> ph;
				cout << "사용자 태어난 년도 : "; cin >> customerYear;
				customerManager->AdultCustomerRegister(name, ph, customerYear);
				break;
			
				//청소년 사용자 등록
			case 2:
				cout << "사용자 이름 : "; cin >> name;
				cout << "사용자 핸드폰 번호 : "; cin >> ph;
				cout << "사용자 태어난 년도 : "; cin >> customerYear;
				customerManager->TeenCustomerRegister(name, ph, customerYear);
				break;
			
				//사용자 목록 출력
			case 3:
				customerManager->CustomerList();
				break;
				
				//사용자 검색
			case 4:
				cout << "검색 모드를 입력해주세요(1.이름 2.휴대폰 번호)"; cin >> searchModint;
				if (searchModint == 1)
				{
					searchModStr = "name";
					cout << "이름 입력: "; cin >> searchStr;
				}

				else if (searchModint == 2)
				{
					searchModStr = "phone";
					cout << "휴대폰 번호 입력: "; cin >> searchStr;
				}
				else
				{
					cout << "잘못입력하셨습니다." << endl; 
					break;
				}
				customerManager->CustomerSearch(searchStr, searchModStr);
				break;

				/*사용자 삭제*/
			case 5:
				cout << "삭제 대상 검색 모드를 입력해주세요(1.이름 2.휴대폰 번호)"; cin >> searchModint;
				if (searchModint == 1)
				{
					searchModStr = "name";
					cout << "삭제할 이름 입력: "; cin >> searchStr;
				}

				else if (searchModint == 2)
				{
					searchModStr = "ph";
					cout << "삭제할 휴대폰 번호 입력: "; cin >> searchStr;
				}
				else
				{
					cout << "잘못입력하셨습니다." << endl;
					break;
				}
				customerManager->CustomerDelete(searchStr, searchModStr);
				break;

				/*처음 화면으로 돌아가기*/
			case 0:
				cout << "처음 화면으로 돌아갑니다." << endl;
				customerManager->CustomerSave("CustomerInfo.txt");
				return;

			default:
				cout << "다시 입력하세요" << endl;
				break;
			}
		}
		// 함수 종료시 자동 세이브
		customerManager->CustomerSave("CustomerInfo.txt");
	}

	void SeatManage()
	{
		int select; //메뉴 선택
		int searchModint;// 검색 모드(숫자)
		string searchModStr;// 검색 모드(문자열)
		string searchStr;// 검색 모드에 따른 검색어
		int wid = 5, len = 10; //wid : 자리의 가로열, len : 자리의 세로열
		seat->SeatSave(wid, len);
		seat->SeatLoad(wid, len);
		while (true)
		{
			std::string line, name, g, age;//line: 자리, name: 이름, g:게임이름
			int u_t, a_n, c_n;// u_t: 사용 시간, a_n:어른 수, c_n: 청소년 수
			
			seat->Showmenu(); cout << "선택: "; cin >> select;
			switch (select)
			{
				/*자리 예약 등록*/
			case 1:
				cout << "자리, 사용자 이름, 사용할 게임이름, 플레이시간, 어른 청소년 수를 입력하세요\n";
				cin >> line >> name >> g >> u_t >> a_n >> c_n;
				seat->SeatAdd(line, name, g, u_t, a_n, c_n);
				break;

				/*자리 예약 리스트*/
			case 2:
				seat->SeatList();
				break;

				/*자리 예약 검색*/
			case 3:
				cout << "검색 모드를 입력해주세요(1.이름 2.자리): "; cin >> searchModint;
				if (searchModint == 1)
				{
					searchModStr = "name";
					cout << "이름 입력: "; cin >> searchStr;
				}

				else if (searchModint == 2)
				{
					searchModStr = "line";
					cout << "자리 입력: "; cin >> searchStr;
				}
				else
				{
					cout << "잘못입력하셨습니다." << endl;
					break;
				}
				seat->SeatSearch(searchStr, searchModStr);
				break;

				/*자리 예약 삭제*/
			case 4:
				cout << "삭제 대상 검색 모드를 입력해주세요(1.이름 2.자리): "; cin >> searchModint;
				if (searchModint == 1)
				{
					searchModStr = "name";
					cout << "이름 입력: "; cin >> searchStr;
				}

				else if (searchModint == 2)
				{
					searchModStr = "line";
					cout << "자리 입력: "; cin >> searchStr;
				}
				else
				{
					cout << "잘못입력하셨습니다." << endl;
					break;
				}
				seat->SeatDelete(searchStr, searchModStr);
				break;
			case 5:
				cout << "자리의 가로열와 세로열를 알려주세오 : ";
				cin >> wid >> len;
				seat->SeatSave(wid, len);
				seat->SeatLoad(wid, len);
				break;
			case 0:
				cout << "처음으로 돌아갑니다." << endl;
				return;
			}
		}
	}
};
#endif // !CUSTOMSTATISTIC_H
