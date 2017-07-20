#pragma once

struct Student
{
	char name[20];
	char number[11] = { '\0', };
	int Korean;
	int English;
	int Mathematics;
	double ave;
	char grade;
};

void insertScore(Student* pstu, int pcount);
void changeScore(Student* pstu, int pcount);
void showScore(Student* pstu, int ptotal);
void showAverage(Student* pstu, int ptotal);
void studentInform(Student* pstu, int pwho);
void Menu();
void subMenu();
void student();