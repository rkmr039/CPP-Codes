#include<iostream.h>
#include<conio.h>
int main()
{

int swap(int a,int b);
int a=4,b=7;
cout<<"Original values "<<endl<<"a= "<<a<<endl<<"b= "<<b;
swap(a,b);
getch();
return 0;
}
int swap(int a,int b)
{
a=a+b;
b=a-b;
a=a-b;
cout<<"\nAfter swapping "<<endl<<"a= "<<a<<endl<<"b= "<<b;
return 0;
}
