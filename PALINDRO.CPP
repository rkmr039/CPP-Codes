#include<iostream.h>
#include<conio.h>
int main()
{

int n,rev=0,r,num;
cout<<"Enter a number ";
cin>>n;
num=n;
while (n!=0)
{
r=n%10;
rev=(rev*10)+r;
n=n/10;
}
if (rev==num)
cout<<"Palindrome number ";
else
cout<<"Not a palindrome number ";
getch();
return 0;
}
