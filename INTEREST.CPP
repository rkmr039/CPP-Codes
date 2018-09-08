// Simple C++ Program to calculate total interest amount
#include<iostream.h>
#include<conio.h>
void main()
{
    float roi,pa,d,ti;
    clrscr();
    cout<<"Enter the Principle Amount:Rs.";
    cin>>pa;
    cout<<"Enter the Rate of Interest per meonth:";
    cin>>roi;
    cout<<"\nEnter the Duration In Months:";
    cin>>d;
    ti=(pa*roi*d)/100;
    cout<<"\nTotal Interest after "<< d <<" Monthe is Rs. "<< ti;
    getch();
}