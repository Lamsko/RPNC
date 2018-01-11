#include "stdafx.h"
#include "RPNC.h"
#include <iostream>

using namespace std;

RPNC::RPNC()
{
}


RPNC::~RPNC()
{
}

void RPNC::push(double e)
{
	if (t >= SIZE)
	{
		cerr << "Przepelnienie stosu." << endl;
		return;
	}
	else
	{
		a[t] = e;
		t++;
	}
}

void RPNC::pop()
{
	if (t == 0)
	{
		cerr << "Stos jest pusty." << endl;
		return;
	}
	else
	{
		t--;
	}
}

bool RPNC::isEmpty()
{
	return (t == 0);
}

void RPNC::read(string str)
{
	double num;
	char c;

	if (istringstream(str) >> num)
	{
		push(num);
	}
}

void RPNC::print(string x, string i)
{
}

void RPNC::calculate(string x)
{
}

double RPNC::top()
{
	return a[t-1];
}

void Start::startCalculator()
{
}
