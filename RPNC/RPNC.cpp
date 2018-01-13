#include "stdafx.h"
#include "RPNC.h"
#include <iostream>
#include <sstream>

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
	else if (istringstream(str) >> c)
	{
		calculate(str);
	}
	else
	{
		cerr << "Niepoprawna skladnia" << endl;
		return;
	}
}

void RPNC::print(string x, string i)
{
	RPNC calc;
	if (t == 1)
	{
		z++;
		cout << endl;
		cout << "Krok" << z << ' ' << i << " wynik: " << top() << endl;
		cout << endl;
	}
	else
	{
		while (t != 1)
		{
			z++;
			cout << "Krok" << z << ' ' << i << " wynik: " << top() << endl;
			calc.push(top());
			pop();
		}
		while (!calc.isEmpty())
		{
			push(calc.top());
			calc.pop();
		}
	}
}

void RPNC::calculate(string x)
{
	string s;

	double temp1, temp2;
	
	temp2 = top();
	pop();
	temp1 = top();
	pop();

	if (x == "+")
	{
		double result;
		result = temp1 + temp2;
		push(result);
		s = "dodawanie";
	}
	if (x == "-")
	{
		double result;
		result = temp1 - temp2;
		push(result);
		s = "odejmowanie";
	}
	if (x == "*")
	{
		double result;
		result = temp1 * temp2;
		push(result);
		s = "mnozenie";
	}
	if (x == "/")
	{
		double result;
		result = temp1 / temp2;
		push(result);
		s = "dzielenie";
	}

	print(x, s);
}

double RPNC::top()
{
	return a[t-1];
}

void Start::startCalculator()
{
	cout << "Kalkulator (odwrocona notacja polska)." << endl;
	cout << endl;
	cout << "Podaj dzialanie: " << endl;

	while (true)
	{
		cin >> txt;
		stack.read(txt);
	}
}
