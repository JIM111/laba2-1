// hz.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include "pr1.h"

// ���������� � ������ ����������
int TClc::получилось или нет? 

{
	try  // ������ ����� �������� �� ��������
	{
		Clc();
	
	} // ����� ����� �������� �� ��������

	// ��������� �������������� ��������
	catch(char* v )  // ���������� ���� char* �� ��������� v
	{
		cout << "\n � ����� ��������� ������!";
		cout << v << CONTINUE << endl;
	}
	catch(...) // ���������� ���������� - �������� ���� ����������
	{
		cout << "\n ����������� ������" << endl;
		throw;
	}

	// ����������� ������ ������� show
	return (_getch());
}

// �������� ��������� ��� ������������ ������ ( float � �� ���������, double)
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



// �������� ��������� ��� ������������ ������ ( int � �� ���������, double)
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


// �������� ��������� ��� ������������ ������ ( double � �� ���������, double)
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


// ������� "������������" ����� � ���������� k � ������������ INVITE
template <class T>
int input (T& k, const char INVITE)
{  // �������� ������ �������� ������ � �������
	ifstream my_inp ("CON");
	long double t;
	cout << "\n ������� �������� ���������� " << INVITE
		<< "  ����  " << typeid(k).name() << " ===> ";
	if (typeid(T)==typeid (float) || typeid(T)==typeid (int) || typeid(T)==typeid (double))
		my_inp >> t;
	else 
		my_inp >> k;  // ���� ������������� ���������� � ���� double       

	switch (my_inp.rdstate()) 
	{ case ios::goodbit:    
	case ios::eofbit :

		// �������� ����������
		if (typeid(T)==typeid (float))
			if(CheckFlt(t)) return 1;
		if (typeid(T)==typeid (float)) k=(T)t;
		// �������� ����������
		if (typeid(T)==typeid (int))
			if(Checkint(t)) return 1;
		if (typeid(T)==typeid (int)) k=(T)t;
		// �������� ����������
		if (typeid(T)==typeid (double))
			if(Checkdbl(t)) return 1;
		if (typeid(T)==typeid (double)) k=(T)t;
		return 0;    // ��� � �������!
	case ios::failbit:             // ���� ������ ����� ��������
	case ios::badbit :
		cout << "\n������ ������ ������ ����� ";
		cout << "\n���������� ��� ���..." << endl;
		return 1;
	};
	cout << "\n������ �� ����� �����" << endl;
	return 1;
}

template <class Ta,  class Tc, class Td>
void inputData(Ta& a,  Tc& c, Td& d)
{

	while (input(a, 'A'));//���������.
	cout <<"������� �������� A = " << a << endl;
	while (input(d, 'D'));
	cout <<"������� �������� D = " << d << endl;
	while (input(c, 'C'));
	cout <<"������� �������� C = " << c << endl;

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
	do    // �������� ����� � ����� �� ������ �� ESC
	{
		cout << "\n--- ���� �" << ++t << " ---" << endl;
		cout << "\n ������� 4" << endl;
		cout << "        log(2*c-a)+d-152  " << endl;
		cout << "   y= -----------" << endl;
		cout << "       a/4+�" << endl;
		inputData(a, c, d);
		TClc Object(a, c, d);
		tt=Object.show();
	} while (tt!=ESC);// ����� �����
#ifdef _DEBUG
	system ("PAUSE");
#endif
	return 0;
}

