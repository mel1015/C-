#pragma once
#include"Employee.h"

class Temporary :public Employee
{
private:
	int hourlyPay;
	int time;

public:
	Temporary();
	Temporary(char type, char* name, int number, int hourlyPay, int time);
	Temporary(const Temporary& other);
	~Temporary();

	int getHourlyPay();
	void setHourlyPay(int hourlyPay);
	int getTime();
	void setTime(int time);

	void showCommon();
	void showDetail();
	int getWage();
};