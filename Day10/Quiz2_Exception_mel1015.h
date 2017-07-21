#pragma once
#include<string>
using namespace std;

class Exception
{
private:
	int lineNum;
	string func, msg;

public:
	Exception(int lineNum, string func, string msg);
	void printError();
};

class DataTypeException :public Exception 
{
public:
	DataTypeException(int lineNum, string func, string msg);
};

class FileException :public Exception 
{
public:
	FileException(int lineNum, string func, string msg);
};