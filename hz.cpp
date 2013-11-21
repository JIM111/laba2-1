#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{ int a, b,c,d;
SetConsoleOutputCP(1251);
cout<<"Введите значение А "<<endl;
cin>> a;
cout<<"Введите значение B "<<endl;
cin>> b;
c=a+b;
cout<<"Ответ"<<c<<endl;
if(c==10)
	d=c-2;
cout<<"Ответ"<<d<<endl;
return 0;
}
