#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{ int a, b,c,q,w,e;
SetConsoleOutputCP(1251);
cout<<" Операция на +"<<endl;
cout<<"Введите значение А "<<endl;
cin>> a;
cout<<"Введите значение B "<<endl;
cin>> b;
c=a+b;
cout<<"Ответ"<<c<<endl;
cout<<" Операция на *"<<endl;
cout<<"Введите значение C "<<endl;
cin>>q;
cout<<"Введите значение D "<<endl;
cin>>w;
e=q*w;
cout<<"Ответ"<<e<<endl;
return 0;
}
