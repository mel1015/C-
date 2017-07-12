#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

void Print_Menu();
void Add_Employee(Employee** Employee_Pointer);
void Delete_Employee(Employee** Employee_Pointer);
void Change_Employee_Data(Employee** Employee_Pointer);
void Search_Employee(Employee** Employee_Pointer);
void Print_All_Employee(Employee** Employee_Pointer);

static int Employee_Number = 0;

int main()
{
	int cmd;

	bool flag = true;
	Employee* Employee_Array[10];
	for (int i = 0; i < 10; i++)
		Employee_Array[i] = nullptr;

	while (flag)
	{
		Print_Menu();
		cin >> cmd;
		cin.ignore(1, '\n');
		cout << endl;
		switch (cmd)
		{
		case 1:
			Add_Employee(Employee_Array);
			break;
		case 2:
			Delete_Employee(Employee_Array);
			break;
		case 3:
			Change_Employee_Data(Employee_Array);
			break;
		case 4:
			Search_Employee(Employee_Array);
			break;
		case 5:
			Print_All_Employee(Employee_Array);
			break;
		case -1:
			flag = false;
			break;
		default:
			cout << "Wrong Menu Number." << endl << endl;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (Employee_Array[i] != nullptr)
		{
			delete Employee_Array[i];
			Employee_Array[i] = nullptr;
		}
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
		<< "5. Print All Employee" << endl
		<< "-1. Exit" << endl
		<< "------------------------" << endl
		<< "Select Menu Number : ";
}
void Add_Employee(Employee** Employee_Pointer)
{
	if (Employee_Number < 10)
	{
		char* name = new char[21];
		int number, pay;
		cout << "Employee name : ";
		cin.getline(name, 21);
		cout << "Employee number : ";
		cin >> number;
		cout << "Employee pay : ";
		cin >> pay;
		cin.ignore(1, '\n');
		for (int i = 0; i < 10; i++)
		{
			if (Employee_Pointer[i] == nullptr)
			{
				Employee_Pointer[i] = new Employee(name, number, pay);
				break;
			}
		}
		delete[] name;
		name = nullptr;
		Employee_Number++;
	}
	else
		cout << "Exceeded the number of eligible employees." << endl << endl;

	cout << "Employee registration is complete." << endl << endl;
}
void Delete_Employee(Employee** Employee_Pointer)
{
	if (Employee_Number == 0)
	{
		cout << "No registered employees." << endl << endl;
	}
	else
	{
		bool check = true;
		char* name = new char[21];
		int number;
		cout << "Employee name to delete : ";
		cin.getline(name, 21);
		cout << "Employee number to delete : ";
		cin >> number;
		cin.ignore(1, '\n');
		for (int i = 0; i < 10; i++)
		{
			if (Employee_Pointer[i] != nullptr
				&& !strcmp(name, Employee_Pointer[i]->getName())
				&& (number == Employee_Pointer[i]->getNumber()))
			{
				delete Employee_Pointer[i];
				Employee_Pointer[i] = nullptr;
				cout << "Employee deleted" << endl << endl;
				Employee_Number--;
				check = false;
				break;
			}
		}
		if (check == true)
		{
			cout << "No such employee" << endl << endl;
		}
		delete[] name;
		name = nullptr;
	}
}
void Change_Employee_Data(Employee** Employee_Pointer)
{
	if (Employee_Number == 0)
	{
		cout << "No registered employees." << endl << endl;
	}
	else
	{
		bool check = true;
		char* name = new char[21];
		int number;
		cout << "Employee name to change : ";
		cin.getline(name, 21);
		cout << "Employee number to change : ";
		cin >> number;
		cin.ignore(1, '\n');
		for (int i = 0; i < 10; i++)
		{
			if (Employee_Pointer[i] != nullptr
				&& !strcmp(name, Employee_Pointer[i]->getName())
				&& (number == Employee_Pointer[i]->getNumber()))
			{
				delete[] name;
				number = 0;
				int pay = 0;
				name = new char[21];
				cout << endl << "Changed name : ";
				cin.getline(name, 21);
				cout << "Changed number : ";
				cin >> number;
				cout << "Changed pay : ";
				cin >> pay;
				cin.ignore(1, '\n');
				Employee_Pointer[i]->setName(name);
				Employee_Pointer[i]->setNumber(number);
				Employee_Pointer[i]->setPay(pay);
				check = false;
				break;
			}
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
void Search_Employee(Employee** Employee_Pointer)
{
	if (Employee_Number == 0)
	{
		cout << "No registered employees." << endl << endl;
	}
	else
	{
		bool check = true;
		char* name = new char[21];
		int number;
		cout << "Employee name to search : ";
		cin.getline(name, 21);
		cout << "Employee number to search : ";
		cin >> number;
		cin.ignore(1, '\n');
		for (int i = 0; i < 10; i++)
		{
			if (Employee_Pointer[i] != nullptr
				&& !strcmp(name, Employee_Pointer[i]->getName())
				&& (number == Employee_Pointer[i]->getNumber()))
			{
				cout << setw(22) << "Name" << setw(10) << "Number" << setw(8) << "Pay" << endl;
				cout << "---------------------------------------------" << endl;
				Employee_Pointer[i]->showDetail();
				cout << "---------------------------------------------" << endl << endl;
				check = false;
				break;
			}
		}
		if (check == true)
		{
			cout << "No such employee" << endl << endl;
		}
		delete[] name;
		name = nullptr;
	}
}
void Print_All_Employee(Employee** Employee_Pointer)
{
	if (Employee_Number == 0)
	{
		cout << "No registered employees." << endl << endl;
	}
	else
	{
		cout << setw(22) << "Name" << setw(10) << "Number" << setw(8) << "Pay" << endl;
		cout << "---------------------------------------------" << endl;
		for (int i = 0; i < 10; i++)
		{
			if (Employee_Pointer[i] != nullptr)
			{

				Employee_Pointer[i]->showDetail();
			}
		}
		cout << "---------------------------------------------" << endl << endl;
	}
}