#pragma once
#include <iostream>
#include <fstream> 
#include <math.h>



using namespace std;

class Complex
{
	double re;
	double im;
public:
	Complex();
	Complex(double x, double y);
	~Complex();
	Complex operator+(Complex B);
	Complex operator*(Complex B);
	Complex operator-(Complex B);
	Complex operator/(Complex B);
	friend ostream & operator<<(ostream & os, const Complex & c);
	Complex operator/(float B);
	Complex operator*(float B);
	Complex operator^(int B);
	Complex  operator+(float B);
	void WriteInFile();
	Complex ReadFromFile();
	float Re();
	double Re(double x) { re = x; };
	float Im();
	int OutD();
	int InD();
};
