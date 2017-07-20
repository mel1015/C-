#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "Permanent.h"
#include "Temporary.h"
#include "Sales.h"
using namespace std;

void Print_Menu();
void Print_Sub_Menu();
void Add_Employee(Employee** Employee_Pointer, int& List_Length);
void Delete_Employee(Employee** Employee_Pointer, int& List_Length);
void Change_Employee_Data(Employee** Employee_Pointer, int& List_Length);
void Search_Employee(Employee** Employee_Pointer, int& List_Length);
void Print_All_Employee(Employee** Employee_Pointer, int& List_Length);

int main()
{
	int cmd;
	int List_Length = 0;
	bool flag = true;
	Employee* Employee_List = nullptr;

	while (flag)
	{
		Print_Menu();
		cin >> cmd;
		cin.ignore(1, '\n');
		cout << endl;

		switch (cmd)
		{
		case 1:
			Add_Employee(&Employee_List, List_Length);
			break;
		case 2:
			Delete_Employee(&Employee_List, List_Length);
			break;
		case 3:
			Change_Employee_Data(&Employee_List, List_Length);
			break;
		case 4:
			Search_Employee(&Employee_List, List_Length);
			break;
		case 5:
			Print_All_Employee(&Employee_List, List_Length);
			break;
		case -1:
			flag = false;
			break;
		default:
			cout << "Wrong Menu Number." << endl << endl;
		}
	}

	Employee* Search_Pointer = Employee_List;
	for (int i = 0; i < List_Length - 1; i++)
	{
		Search_Pointer = Search_Pointer->getNext_Object();
	}
	for (int i = 0; i < List_Length; i++)
	{
		if (Search_Pointer->getPrev_Object() == nullptr)
		{
			delete Search_Pointer;
			Search_Pointer = nullptr;
			Employee_List = nullptr;
			break;
		}
		Search_Pointer = Search_Pointer->getPrev_Object();
		delete Search_Pointer->getNext_Object();
		Search_Pointer->setNext_Object(nullptr);
	}

	cout << "Exit the program." << endl;
	return 0;
}

void Print_Menu()
{
	cout << "----------Menu----------" << endl
		<< "1. Add Employee" << endl
		<< "2. Delete Employee" << endl
		<< "3. Chage Employee Data" << endl
		<< "4. Search Employee" << endl
		<< "5. Employee List" << endl
		<< "-1. Exit" << endl
		<< "------------------------" << endl
		<< "Select Menu Number : ";
}

void Print_Sub_Menu()
{
	cout << "----------List----------" << endl
		<< "1. Permanent Employee" << endl
		<< "2. Temporary Employee" << endl
		<< "3. Sales Employee" << endl
		<< "4. Print All Employee" << endl
		<< "-1. Back" << endl
		<< "------------------------" << endl
		<< "Select Menu Number : ";
}

void Add_Employee(Employee** Employee_Pointer, int& List_Length)
{
	bool Type_Check = true;
	Employee* temp = nullptr;
	char type;
	char* name = new char[21];
	int number;

	while (Type_Check)
	{
		cout << "Job Type : ";
		cin >> type;
		cin.ignore(1, '\n');
		switch (type)
		{
		case 'p':
		case 'P':
			int monthlyPay;
			cout << "Permanent Employee name : ";
			cin.getline(name, 21);
			cout << "Permanent Employee number : ";
			cin >> number;
			cout << "Permanent Employee monthly pay : ";
			cin >> monthlyPay;
			cin.ignore(1, '\n');

			temp = new Permanent(toupper(type), name, number, monthlyPay);
			Type_Check = false;
			break;
		case 't':
		case 'T':
			int hourlyPay;
			int time;
			cout << "Temporary Employee name : ";
			cin.getline(name, 21);
			cout << "Temporary Employee number : ";
			cin >> number;
			cout << "Temporary Employee hourly pay : ";
			cin >> hourlyPay;
			cin.ignore(1, '\n');
			cout << "Temporary Employee working time : ";
			cin >> time;
			cin.ignore(1, '\n');

			temp = new Temporary(toupper(type), name, number, hourlyPay, time);
			Type_Check = false;
			break;
		case 's':
		case 'S':
			int sales;
			cout << "Sales Employee name : ";
			cin.getline(name, 21);
			cout << "Sales Employee number : ";
			cin >> number;
			cin.ignore(1, '\n');
			cout << "Sales Employee monthly pay : ";
			cin >> monthlyPay;
			cin.ignore(1, '\n');
			cout << "Sales Employee sales : ";
			cin >> sales;
			cin.ignore(1, '\n');

			temp = new Sales(toupper(type), name, number, monthlyPay, sales);
			Type_Check = false;
			break;
		default:
			cout << "Wrong Menu" << endl << endl;
			break;
		}
	}

	++List_Length;
	if (*Employee_Pointer == nullptr)
	{
		*Employee_Pointer = temp;
	}
	else
	{
		Employee* Search_Pointer = *Employee_Pointer;
		for (int i = 0; i < List_Length; i++)
		{
			if (Search_Pointer->getNext_Object() == nullptr)
			{
				temp->setPrev_Object(Search_Pointer);
				Search_Pointer->setNext_Object(temp);
				break;
			}
			Search_Pointer = Search_Pointer->getNext_Object();
		}
	}
	cout << "Employee registration is complete." << endl << endl;
	delete[] name;
	name = nullptr;
	temp = nullptr;
}

void Delete_Employee(Employee** Employee_Pointer, int& List_Length)
{
	if (List_Length == 0)
	{
		cout << "No registered employees." << endl << endl;
	}
	else
	{
		bool check = true;
		Employee* Search_Pointer = *Employee_Pointer;
		char type;
		char* name = new char[21];
		int number;
		cout << "Employee type to delete : ";
		cin >> type;
		cin.ignore(1, '\n');
		cout << "Employee name to delete : ";
		cin.getline(name, 21);
		cout << "Employee number to delete : ";
		cin >> number;
		cin.ignore(1, '\n');
		for (int i = 0; i < List_Length; i++)
		{
			if (Search_Pointer->getType() == toupper(type)
				&& !strcmp(Search_Pointer->getName(), name)
				&& Search_Pointer->getNumber() == number)
			{
				if (Search_Pointer->getPrev_Object() == nullptr
					&& Search_Pointer->getNext_Object() == nullptr)
				{
					*Employee_Pointer = nullptr;
				}
				else if (Search_Pointer->getPrev_Object() == nullptr
					&& Search_Pointer->getNext_Object() != nullptr)
				{
					*Employee_Pointer = Search_Pointer->getNext_Object();
					(Search_Pointer->getNext_Object())->setPrev_Object(nullptr);
				}
				else if (Search_Pointer->getNext_Object() == nullptr)
				{
					(Search_Pointer->getPrev_Object())->setNext_Object(nullptr);
				}
				else
				{
					(Search_Pointer->getPrev_Object())->setNext_Object(Search_Pointer->getNext_Object());
					(Search_Pointer->getNext_Object())->setPrev_Object(Search_Pointer->getPrev_Object());
				}
				delete Search_Pointer;
				Search_Pointer = nullptr;

				cout << "Delete complete" << endl << endl;
				--List_Length;
				check = false;
				break;
			}
			if (Search_Pointer->getNext_Object() == nullptr)
			{
				break;
			}
			Search_Pointer = Search_Pointer->getNext_Object();
		}
		if (check == true)
			cout << "No such employee" << endl << endl;

		delete[] name;
		name = nullptr;
	}
}

void Change_Employee_Data(Employee** Employee_Pointer, int& List_Length)
{
	if (List_Length == 0)
	{
		cout << "No registered employees." << endl << endl;
	}
	else
	{
		bool check = true;
		int number;
		char type;
		char* name = new char[21];
		Employee* Search_Pointer = *Employee_Pointer;
		cout << "Employee type to change : ";
		cin >> type;
		cin.ignore(1, '\n');
		cout << "Employee name to change : ";
		cin.getline(name, 21);
		cout << "Employee number to change : ";
		cin >> number;
		cin.ignore(1, '\n');
		for (int i = 0; i < List_Length; i++)
		{
			if (Search_Pointer->getType() == toupper(type)
				&& !strcmp(Search_Pointer->getName(), name)
				&& Search_Pointer->getNumber() == number)
			{
				delete[] name;
				name = nullptr;
				name = new char[21];
				number = 0;
				if (check)
				{
					char type2;
					cout << "Changed type : ";
					cin >> type2;
					cin.ignore(1, '\n');
					if (toupper(type) == toupper(type2))
					{
						switch (type2)
						{
						case 'p':
						case 'P':
							int monthlyPay;
							cout << "Changed Employee name : ";
							cin.getline(name, 21);
							cout << "Changed Employee number : ";
							cin >> number;
							cin.ignore(1, '\n');
							cout << "Changed Employee monthly pay : ";
							cin >> monthlyPay;
							cin.ignore(1, '\n');

							Search_Pointer->setType(type2);
							Search_Pointer->setName(name);
							Search_Pointer->setNumber(number);
							((Permanent*)Search_Pointer)->setMonthlyPay(monthlyPay);
							check = false;
							break;
						case 't':
						case 'T':
							int hourlyPay;
							int time;
							cout << "Changed Employee name : ";
							cin.getline(name, 21);
							cout << "Changed Employee number : ";
							cin >> number;
							cin.ignore(1, '\n');
							cout << "Changed Employee hourly pay : ";
							cin >> hourlyPay;
							cin.ignore(1, '\n');
							cout << "Changed Employee working time : ";
							cin >> time;
							cin.ignore(1, '\n');

							Search_Pointer->setType(type2);
							Search_Pointer->setName(name);
							Search_Pointer->setNumber(number);
							((Temporary*)Search_Pointer)->setHourlyPay(hourlyPay);
							((Temporary*)Search_Pointer)->setTime(time);
							check = false;
							break;
						case 's':
						case 'S':
							int sales;
							cout << "Changed Employee name : ";
							cin.getline(name, 21);
							cout << "Changed Employee number : ";
							cin >> number;
							cin.ignore(1, '\n');
							cout << "Changed Employee monthly pay : ";
							cin >> monthlyPay;
							cin.ignore(1, '\n');
							cout << "Changed Employee sales : ";
							cin >> sales;
							cin.ignore(1, '\n');

							Search_Pointer->setType(type2);
							Search_Pointer->setName(name);
							Search_Pointer->setNumber(number);
							((Sales*)Search_Pointer)->setMonthlyPay(monthlyPay);
							((Sales*)Search_Pointer)->setSales(sales);
							check = false;
							break;
						default:
							cout << "Wrong Menu" << endl << endl;
							break;
						}
					}
				}
			}
			if (Search_Pointer->getNext_Object() == nullptr)
			{
				break;
			}
			Search_Pointer = Search_Pointer->getNext_Object();
		}
		if (check == true)
		{
			cout << "No such employee" << endl << endl;
		}
		else
			cout << "Employee data changed" << endl << endl;
		delete[] name;
		name = nullptr;
	}
}

void Search_Employee(Employee** Employee_Pointer, int& List_Length)
{
	if (List_Length == 0)
	{
		cout << "No registered employees." << endl << endl;
	}
	else
	{
		bool check = true;
		char type;
		char* name = new char[21];
		int number;
		Employee* Search_Pointer = *Employee_Pointer;

		cout << "Employee type to search : ";
		cin >> type;
		cin.ignore(1, '\n');
		cout << "Employee name to search : ";
		cin.getline(name, 21);
		cout << "Employee number to search : ";
		cin >> number;
		cin.ignore(1, '\n');
		for (int i = 0; i < List_Length; i++)
		{
			if (Search_Pointer->getType() == toupper(type)
				&& !strcmp(Search_Pointer->getName(), name)
				&& Search_Pointer->getNumber() == number)
			{
				switch (type)
				{
				case 'P':
				case 'p':
					cout << setw(8) << "Job Type" << setw(22) << "Name" << setw(10) << "Number" << setw(15) << "Monthly Pay" << endl;
					cout << "------------------------------------------------------------------------------------------" << endl;
					Search_Pointer->showDetail();
					cout << "------------------------------------------------------------------------------------------" << endl;
					break;
				case 'T':
				case 't':
					cout << setw(8) << "Job Type" << setw(22) << "Name" << setw(10) << "Number" << setw(15) << "Hourly Pay" << setw(8) << "Time" << endl;
					cout << "------------------------------------------------------------------------------------------" << endl;
					Search_Pointer->showDetail();
					cout << "------------------------------------------------------------------------------------------" << endl;
					break;
				case 'S':
				case 's':
					cout << setw(8) << "Job Type" << setw(22) << "Name" << setw(10) << "Number" << setw(15) << "Monthly Pay" << setw(15) << "Sales" << endl;
					cout << "------------------------------------------------------------------------------------------" << endl;
					Search_Pointer->showDetail();
					cout << "------------------------------------------------------------------------------------------" << endl;
					break;
				}
				cout << "Searching Complete" << endl << endl;
				check = false;
				break;
			}
			if (Search_Pointer->getNext_Object() == nullptr)
			{
				break;
			}
			Search_Pointer = Search_Pointer->getNext_Object();
		}
		if (check == true)
		{
			cout << "No such employee" << endl << endl;
		}
		delete[] name;
		name = nullptr;
	}
}
void Print_All_Employee(Employee** Employee_Pointer, int& List_Length)
{
	if (List_Length == 0)
	{
		cout << "No registered employees." << endl << endl;
	}
	else
	{
		int cmd;
		bool check = true;
		Employee* Search_Pointer = nullptr;
		Print_Sub_Menu();
		cin >> cmd;
		cin.ignore(1, '\n');
		cout << endl;

		while (check)
		{
			switch (cmd)
			{
			case 1:
				Search_Pointer = *Employee_Pointer;
				cout << setw(8) << "Job Type" << setw(22) << "Name" << setw(10) << "Number" << setw(15) << "Monthly Pay" << endl;
				cout << "------------------------------------------------------------------------------------------" << endl;
				for (int i = 0; i < List_Length; i++)
				{
					if (Search_Pointer->getType() == 'P')
					{
						Search_Pointer->showDetail();
					}
					if (Search_Pointer->getNext_Object() == nullptr)
						break;
					Search_Pointer = Search_Pointer->getNext_Object();
				}
				cout << "------------------------------------------------------------------------------------------" << endl << endl;
				check = false;
				break;
			case 2:
				Search_Pointer = *Employee_Pointer;
				cout << setw(8) << "Job Type" << setw(22) << "Name" << setw(10) << "Number" << setw(15) << "Hourly Pay" << setw(8) << "Time" << endl;
				cout << "------------------------------------------------------------------------------------------" << endl;
				for (int i = 0; i < List_Length; i++)
				{
					if (Search_Pointer->getType() == 'T')
					{
						Search_Pointer->showDetail();
					}
					if (Search_Pointer->getNext_Object() == nullptr)
						break;
					Search_Pointer = Search_Pointer->getNext_Object();
				}
				cout << "------------------------------------------------------------------------------------------" << endl << endl;
				check = false;
				break;
			case 3:
				Search_Pointer = *Employee_Pointer;
				cout << setw(8) << "Job Type" << setw(22) << "Name" << setw(10) << "Number" << setw(15) << "Monthly Pay" << setw(15) << "Sales" << endl;
				cout << "------------------------------------------------------------------------------------------" << endl;
				for (int i = 0; i < List_Length; i++)
				{
					if (Search_Pointer->getType() == 'S')
					{
						Search_Pointer->showDetail();
					}
					if (Search_Pointer->getNext_Object() == nullptr)
						break;
					Search_Pointer = Search_Pointer->getNext_Object();
				}
				cout << "------------------------------------------------------------------------------------------" << endl << endl;
				check = false;
				break;
			case 4:
				Search_Pointer = *Employee_Pointer;
				cout << setw(8) << "Type" << setw(22) << "Name" << setw(10) << "Number" << setw(10) << "Pay" << endl;
				cout << "-------------------------------------------------------" << endl;
				for (int i = 0; i < List_Length; i++)
				{
					Search_Pointer->showCommon();
					if (Search_Pointer->getNext_Object() == nullptr)
						break;
					Search_Pointer = Search_Pointer->getNext_Object();
				}
				cout << "-------------------------------------------------------" << endl << endl;
				check = false;
				break;
			case -1:
				check = false;
				break;
			default:
				cout << "Wrong Menu" << endl << endl;
				break;
			}
		}
	}
}