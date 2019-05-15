// Laboratornaya1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Complex.h"



using namespace std;


  


int main()
{
	Complex A, B, C, D, E, F;
	//Массивы комплексных чисел 
	Complex Mas[5], mas[15];
	setlocale(LC_ALL, "Russian");

	cout << "Введите первое комплексное число." << endl;
	
	A.InD();
	cout << "Первое комплексное число: ";
	A.OutD();
	cout << endl;
	A.WriteInFile();
	B = B.ReadFromFile();
	cout << "Первое комплексное число, считанное из двоичного файла: ";
	B.OutD();
	cout << endl;

	cout << "Введите второе комплексное число" << endl;
	A.InD();
	cout << "Второе комплексное число:";
	A.OutD();
	cout << endl;
	A.WriteInFile();
	D=D.ReadFromFile();
	cout << "Второе комплексное число, считанное из двоичного файла: ";
	D.OutD();
	cout << endl;
	Mas[0] = B;
	Mas[1] = D;
	
	//деление комплексного на комплекное
	cout << "Деление первого комплексного числа на второе" << endl;
	A = B / D;
	A.OutD();
	Mas[2] = A;
	//вычитание комплексного на комплекное
	cout << "Разность чисел" << endl;
	E = B - D;
	Mas[3] = E;
	E.OutD();

	//слолжение комплексного на комплекное
	cout << "Cумма чисел" << endl;
	F = B + D;
	Mas[4] = F;
	F.OutD();
	cout << "Полученный массив из комплексных чисел:" << endl;
	for (int k = 0; k < 5; k++)
	{
		Mas[k].OutD();
	}
	//Запись массива в двоичный файл
	ofstream f_bin("binIn.txt", ios::binary);
	f_bin.write((char*)&Mas,sizeof(Complex[5]));
	f_bin.close();
	//Считывание массива из файла
	ifstream f("binIn.txt", ios::binary);
	f.read((char*)&mas, sizeof(Complex[15]));
	f.close();
	//Вывод массива на экран
	cout << "Массив из комплексных чисел, считанный из двоичного файла: " << endl;
	for (int p = 0; p < 15; p++)
	{
		mas[p].OutD();
	}
	
	system("pause");
}
