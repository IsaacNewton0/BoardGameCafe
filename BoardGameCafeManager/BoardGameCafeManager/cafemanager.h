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
			string name, ph;//����� �̸�, �޴��� ��ȣ
			int customerYear;// ����� �¾ ����
			int select; //�޴� ����
			int searchModint;// �˻� ���(����)
			string searchModStr;// �˻� ���(���ڿ�)
			string searchStr;// �˻� ��忡 ���� �˻���

			customerManager->ShowMenu();
			cout << "���� : "; cin >> select;
			switch (select)
			{
				//���� ����� ���
			case 1:
				cout << "����� �̸� : "; cin >> name;
				cout << "����� �ڵ��� ��ȣ : "; cin >> ph;
				cout << "����� �¾ �⵵ : "; cin >> customerYear;
				customerManager->AdultCustomerRegister(name, ph, customerYear);
				break;
			
				//û�ҳ� ����� ���
			case 2:
				cout << "����� �̸� : "; cin >> name;
				cout << "����� �ڵ��� ��ȣ : "; cin >> ph;
				cout << "����� �¾ �⵵ : "; cin >> customerYear;
				customerManager->TeenCustomerRegister(name, ph, customerYear);
				break;
			
				//����� ��� ���
			case 3:
				customerManager->CustomerList();
				break;
				
				//����� �˻�
			case 4:
				cout << "�˻� ��带 �Է����ּ���(1.�̸� 2.�޴��� ��ȣ)"; cin >> searchModint;
				if (searchModint == 1)
				{
					searchModStr = "name";
					cout << "�̸� �Է�: "; cin >> searchStr;
				}

				else if (searchModint == 2)
				{
					searchModStr = "phone";
					cout << "�޴��� ��ȣ �Է�: "; cin >> searchStr;
				}
				else
				{
					cout << "�߸��Է��ϼ̽��ϴ�." << endl; 
					break;
				}
				customerManager->CustomerSearch(searchStr, searchModStr);
				break;

				/*����� ����*/
			case 5:
				cout << "���� ��� �˻� ��带 �Է����ּ���(1.�̸� 2.�޴��� ��ȣ)"; cin >> searchModint;
				if (searchModint == 1)
				{
					searchModStr = "name";
					cout << "������ �̸� �Է�: "; cin >> searchStr;
				}

				else if (searchModint == 2)
				{
					searchModStr = "ph";
					cout << "������ �޴��� ��ȣ �Է�: "; cin >> searchStr;
				}
				else
				{
					cout << "�߸��Է��ϼ̽��ϴ�." << endl;
					break;
				}
				customerManager->CustomerDelete(searchStr, searchModStr);
				break;

				/*ó�� ȭ������ ���ư���*/
			case 0:
				cout << "ó�� ȭ������ ���ư��ϴ�." << endl;
				customerManager->CustomerSave("CustomerInfo.txt");
				return;

			default:
				cout << "�ٽ� �Է��ϼ���" << endl;
				break;
			}
		}
		// �Լ� ����� �ڵ� ���̺�
		customerManager->CustomerSave("CustomerInfo.txt");
	}

	void SeatManage()
	{
		int select; //�޴� ����
		int searchModint;// �˻� ���(����)
		string searchModStr;// �˻� ���(���ڿ�)
		string searchStr;// �˻� ��忡 ���� �˻���
		int wid = 5, len = 10; //wid : �ڸ��� ���ο�, len : �ڸ��� ���ο�
		seat->SeatSave(wid, len);
		seat->SeatLoad(wid, len);
		while (true)
		{
			std::string line, name, g, age;//line: �ڸ�, name: �̸�, g:�����̸�
			int u_t, a_n, c_n;// u_t: ��� �ð�, a_n:� ��, c_n: û�ҳ� ��
			
			seat->Showmenu(); cout << "����: "; cin >> select;
			switch (select)
			{
				/*�ڸ� ���� ���*/
			case 1:
				cout << "�ڸ�, ����� �̸�, ����� �����̸�, �÷��̽ð�, � û�ҳ� ���� �Է��ϼ���\n";
				cin >> line >> name >> g >> u_t >> a_n >> c_n;
				seat->SeatAdd(line, name, g, u_t, a_n, c_n);
				break;

				/*�ڸ� ���� ����Ʈ*/
			case 2:
				seat->SeatList();
				break;

				/*�ڸ� ���� �˻�*/
			case 3:
				cout << "�˻� ��带 �Է����ּ���(1.�̸� 2.�ڸ�): "; cin >> searchModint;
				if (searchModint == 1)
				{
					searchModStr = "name";
					cout << "�̸� �Է�: "; cin >> searchStr;
				}

				else if (searchModint == 2)
				{
					searchModStr = "line";
					cout << "�ڸ� �Է�: "; cin >> searchStr;
				}
				else
				{
					cout << "�߸��Է��ϼ̽��ϴ�." << endl;
					break;
				}
				seat->SeatSearch(searchStr, searchModStr);
				break;

				/*�ڸ� ���� ����*/
			case 4:
				cout << "���� ��� �˻� ��带 �Է����ּ���(1.�̸� 2.�ڸ�): "; cin >> searchModint;
				if (searchModint == 1)
				{
					searchModStr = "name";
					cout << "�̸� �Է�: "; cin >> searchStr;
				}

				else if (searchModint == 2)
				{
					searchModStr = "line";
					cout << "�ڸ� �Է�: "; cin >> searchStr;
				}
				else
				{
					cout << "�߸��Է��ϼ̽��ϴ�." << endl;
					break;
				}
				seat->SeatDelete(searchStr, searchModStr);
				break;
			case 5:
				cout << "�ڸ��� ���ο��� ���ο��� �˷��ּ��� : ";
				cin >> wid >> len;
				seat->SeatSave(wid, len);
				seat->SeatLoad(wid, len);
				break;
			case 0:
				cout << "ó������ ���ư��ϴ�." << endl;
				return;
			}
		}
	}
};
#endif // !CUSTOMSTATISTIC_H
