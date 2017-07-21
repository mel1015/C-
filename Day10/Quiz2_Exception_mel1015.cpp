#include <iostream>
#include "Exception.h"
using namespace std;

Exception::Exception(int lineNum, string func, string msg)
{
	this->lineNum = lineNum;
	this->func = func;
	this->msg = msg;
}

void Exception::printError()
{
	cout << func << " : " << lineNum << ", " << msg << endl;
}

DataTypeException::DataTypeException(int lineNum, string func, string msg)
	: Exception(lineNum, func, msg)
{

}

FileException::FileException(int lineNum, string func, string msg)
	: Exception(lineNum, func, msg)
{

}