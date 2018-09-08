// simple c++ program to show the use of cin and cout
#include<iostream.h>
#include<conio.h>
void main()
{
   clrscr();
   int value1,value2,sum;
   cout<<"Enter 1st digit:";
   cin>>value1;
   cout<<"Enter 2nd digit:";
   cin>>value2;
   sum=value1+value2;
   cout<<"Sum of Entered digits:";
   cout<<sum;
   //Cascading of I/O operators
   cout<<"\nEnter Two Numbers:";
   cin>>value1>>value2;
   cout<<"\nThe Sum of "<<value1<<" and "<<value2<<" is "<<sum;
   getch();
}