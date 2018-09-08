#include <iostream.h>
#include<conio.h>
#include<math.h>
int main()
{
int n,p,m,s=0,b,count=0;
clrscr();
cout<<"Enter the number to find: ";
cin>>n;
b=n;
p=n;
 while(p)
  {
      p=p/10;
      count++;
  }
 while(n>0)
  {
    m=n%10;
    s=s+pow(m,count);
    n=n/10;
   }
if(b==s)
  cout<<" Amstrong Number is "<<b;
else
  cout<<" Not Amstrong Number";
getch();
return 0;
}
