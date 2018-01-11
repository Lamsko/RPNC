#pragma once
#include <iostream>

using namespace std;

const unsigned SIZE = 99;

class RPNC
{
public:
	RPNC();
	~RPNC();

	void push(double e);
	void pop();
	bool isEmpty();
	void read(string str);
	void print(string x, string i);
	void evaulate(string x);
	double top();

private:
	double a[SIZE];
	unsigned t = 0;
	int z = 0;
};

class Start : RPNC
{
public:
	void startCalculator();

private:
	RPNC stack;
	string txt;
};
