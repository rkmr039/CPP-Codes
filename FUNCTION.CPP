#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int change(int);
int orig=10;
cout<<"\nThe original value is"<<orig<<"\n";
cout<<"\nReturn value of function change() is"<<change(orig)<<"\n";
getch();
}
int change(int a)
{
a=20;
return a;
}