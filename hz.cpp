#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{ int a, b,c;
SetConsoleOutputCP(1251);
cout<<" Операция на +"<<endl;
cout<<"Введите значение А "<<endl;
cin>> a;
cout<<"Введите значение B "<<endl;
cin>> b;
c=a+b;
cout<<"Ответ"<<c<<endl;
cout<<" Операция на *"<<endl;
cout<<"Введите значение A "<<endl;
cin>>a;
cout<<"Введите значение B "<<endl;
cin>>b;
c=a*b;
cout<<"Ответ"<<c<<endl;
cout<<"Операция на - "<<endl;
cout<<"Введите значение A "<<endl;
cin>> a;
cout<<"Введите значение B "<<endl;
cin>> b;
c=a-b;
cout<<"Ответ"<<c<<endl;
return 0;
}
