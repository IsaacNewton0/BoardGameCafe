// 보드게임 카페 매니저 프로그램입니다.
//README.md꼭 읽을 것
#include "pch.h"
#include <iostream>
#include<string>
#include"customerManager.h"//고객관리 헤더파일
#include"Seat.h"// 자리 관리 헤더파일
#include "cafemanager.h"// 카페 관리 헤더 파일
int main()
{
	CustomerManager customerManager;// 고객 관리 객체
	Seat seatManager;// 자리 관리자 객체
	int select;// 선택 번호

	//프로그램 시작시 고객 정보 로드
	customerManager.CustomerLoad("CustomerInfo.txt");

	//카페 관리 객체 생성(고객 관리, 자리 관리 통합되어있음)
	CafeManager cafeManager(&customerManager, &seatManager);

	while (true)
	{
		cout << "********보드 카페 관리 프로그램*********" << endl;
		cout << "*           1. 고객 관리               *" << endl;
		cout << "*           2. 자리 관리               *" << endl;
		cout << "*           0. 프로그램 종료           *" << endl;
		cout << "****************************************" << endl;
		cout << "선택: "; cin >> select;
		system("cls");//화면 클리어
		switch (select)
		{
			//고객 정보 관리
		case 1:
			cafeManager.CustomerManage();
			break;

			//자리 관리
		case 2:
			cafeManager.SeatManage();
			break;

			//프로그램 종료
		case 0:
			cout << "프로그램을 종료합니다." << endl;
			return 0;

		default:
			cout << "잘못 입력하셨습니다." << endl;
			break;
		}
		getchar();
		cout << "계속하려면 Enter를 누르세요";
		getchar();
		system("cls");//화면 클리어
	}
}