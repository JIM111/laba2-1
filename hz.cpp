// hz.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "pr1.h"

// Вычисление и выдача результата
int TClc::show ()
{
	try  // начало блока слежения за ошибками
	{
		Clc();
	
	} // конец блока слежения за ошибками

	// Обработка исключительных ситуаций
	catch(char* v )  // исключения типа char* со значением v
	{
		cout << "\n В нашей программе ошибка!";
		cout << v << CONTINUE << endl;
	}
	catch(...) // Абсолютный обработчик - перехват ВСЕХ исключений
	{
		cout << "\n Неожиданная ошибка" << endl;
		throw;
	}

	// продолжение работы функции show
	return (_getch());
}

// Проверка диапазона для вещественных данных ( float – по умолчанию, double)
int CheckFlt(long double t, const double MIN=-FLT_MIN, const double MAX=FLT_MAX)
{
	if (fabsl(t)>MAX)
	{
		cout << Error_Limits;
		cout << Explanation	<< MIN << To << MAX << endl;
		return 1;
	}
	return 0;
}



// Проверка диапазона для вещественных данных ( int – по умолчанию, double)
int Checkint(long double t, const double MIN=INT_MIN, const double MAX=INT_MAX)
{
	if (fabsl(t)>MAX)
	{
		cout << Error_Limits;
		cout << Explanation	<< MIN << To << MAX << endl;
		return 1;
	}
	return 0;
}


// Проверка диапазона для вещественных данных ( double – по умолчанию, double)
int Checkdbl(long double t, const double MIN=-DBL_MIN, const double MAX=DBL_MAX)
{
	if (fabsl(t)>MAX)
	{
		cout << Error_Limits;
		cout << Explanation	<< MIN << To << MAX << endl;
		return 1;
	}
	return 0;
}


// Функция "всепогодного" ввода в переменную k с приглашением INVITE
template <class T>
int input (T& k, const char INVITE)
{  // Открытие своего входного потока с консоли
	ifstream my_inp ("CON");
	long double t;
	cout << "\n Введите значение переменной " << INVITE
		<< "  типа  " << typeid(k).name() << " ===> ";
	if (typeid(T)==typeid (float) || typeid(T)==typeid (int) || typeid(T)==typeid (double))
		my_inp >> t;
	else 
		my_inp >> k;  // ввод целочисленных переменных и типа double       

	switch (my_inp.rdstate()) 
	{ case ios::goodbit:    
	case ios::eofbit :

		// контроль диапазонов
		if (typeid(T)==typeid (float))
			if(CheckFlt(t)) return 1;
		if (typeid(T)==typeid (float)) k=(T)t;
		// контроль диапазонов
		if (typeid(T)==typeid (int))
			if(Checkint(t)) return 1;
		if (typeid(T)==typeid (int)) k=(T)t;
		// контроль диапазонов
		if (typeid(T)==typeid (double))
			if(Checkdbl(t)) return 1;
		if (typeid(T)==typeid (double)) k=(T)t;
		return 0;    // Все в порядке!
	case ios::failbit:             // Есть ошибки ввода символов
	case ios::badbit :
		cout << "\nВведен символ вместо цифры ";
		cout << "\nПопробуйте еще раз..." << endl;
		return 1;
	};
	cout << "\nОшибка во время ввода" << endl;
	return 1;
}

template <class Ta,  class Tc, class Td>
void inputData(Ta& a,  Tc& c, Td& d)
{

	while (input(a, 'A'));//пользоват.
	cout <<"Введите значение A = " << a << endl;
	while (input(d, 'D'));
	cout <<"Введите значение D = " << d << endl;
	while (input(c, 'C'));
	cout <<"Введите значение C = " << c << endl;

}


int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleOutputCP(1251); 
	int ESC=27, tt, t=0;
	int c;
	float a;
	double d;
	cout<<setprecision(16);
#ifdef _DEBUG
	cout << "--- DEBUGGING ---" << endl;
#endif
	do    // работать будем в цыкле до выхода по ESC
	{
		cout << "\n--- Тест №" << ++t << " ---" << endl;
		cout << "\n Вариант 4" << endl;
		cout << "        log(2*c-a)+d-152  " << endl;
		cout << "   y= -----------" << endl;
		cout << "       a/4+с" << endl;
		inputData(a, c, d);
		TClc Object(a, c, d);
		tt=Object.show();
	} while (tt!=ESC);// конец цикла
#ifdef _DEBUG
	system ("PAUSE");
#endif
	return 0;
}

