#include "pch.h"
#include "Complex.h" 



using namespace std;


Complex::Complex()//�����������
{
	re = 0;
	im = 0;
}


Complex::~Complex()//����������
{
}

Complex::Complex(double x, double y)//�����������
{
	re = x;
	im = y;
}


float Complex::Re()
{
	
	return re;
}

float Complex::Im()
{
	
	return im;
}

Complex Complex::operator+(Complex B)//����� �����������
{
	return Complex(re+B.re,im+B.im);
}



Complex Complex::operator*(Complex B)//������������ ����������
{
	Complex X;
	X.re = (re*B.re) - (im*B.im);
	X.im = (re*B.im) + (B.re*im);
	return X;
}




int Complex::OutD()//����� ������������ 
{
	std::cout << re;
	if (im > 0) std::cout << "+";
	if (im!=0) std::cout << im << "i\n";
	return 0;
}

int Complex::InD()//���� ������������ 
{
	std::cout << "Real = ";
	std::cin >> re;
	std::cout << "Image = ";
	std::cin >> im;
	return 0;
}

Complex Complex::operator-(Complex y)//�������� ����������� 
{
	Complex x;
	x.re = re - y.re;
	x.im = im - y.im;
	return x;
}

Complex Complex::operator/(Complex y)//������� ������������ �� �����������
{
	Complex x;
	x.re = ((re*y.re) + (im*y.im)) / ((y.re*y.re) + (y.im*y.im));
	x.im = ((im*y.re) - (re*y.im)) / ((y.re*y.re) + (y.im*y.im));
	return x;
}

Complex Complex::operator/(float y)//������� ������������ �� ������������
{
	Complex x;
	x.re = (re*y) / (y*y);
	x.im = (im*y) / (y*y);
	return x;
}

Complex Complex::operator*(float B) // ��������� ������������ �� ������������
{
	Complex X;
	X.re = re * B;
	X.im = im * B;
	return X;
}

Complex Complex::operator^(int B) // ���������� ������������ � �������
{
	Complex X;
	X.re = re;
	X.im = im;
	while (B != 1)
	{
		X.re *= re;
		X.im *= im;
		B--;
	}
	return X;
}

//���������� ��������� ������ 

ostream& operator<<(ostream& os, const Complex &c)
{
	os << "complex number is " << c.re;
	if (c.im > 0) os << " + ";
	if (c.im != 0) os << c.im << "i";
	return os;
}


Complex Complex::operator+( float B)
{
	return Complex(re + B,im);
}
void Complex::WriteInFile()//������ � �������� ����� ������������ �����
{
	Complex C(this->Re(), this->Im());
	ofstream f_bin("binIn.txt", ios::binary);
	f_bin.write((char*)&C, sizeof(Complex));
	f_bin.close();
}
Complex Complex::ReadFromFile()//���������� �� ��������� ����� ������������ �����
{
	Complex C;
	ifstream f_bin("binIn.txt", ios::binary | ios::app);
	f_bin.read((char*)&C, sizeof(Complex));
	f_bin.close();
	return C;
}
