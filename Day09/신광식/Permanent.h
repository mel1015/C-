#pragma once
#include "Employee.h"

class Permanent : public Employee	//정규직
{
private:
	int monthlyPay;

public:
	Permanent();
	Permanent(char type, char* name, int number, int mothlyPay);
	Permanent(const Permanent& other);
	~Permanent();

	int getMonthlyPay();
	void setMonthlyPay(int mothlyPay);

	void showCommon();
	void showDetail();
	int getWage();
};