#pragma once
#include"Permanent.h"

class Sales : public Permanent
{
private:
	int sales;

public:
	Sales();
	Sales(char type, char* name, int number, int monthlyPay, int sales);
	Sales(const Sales& other);
	~Sales();

	int getSales();
	void setSales(int sales);

	void showCommon();
	void showDetail();
	int getWage();
};