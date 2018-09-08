#include<iostream.h>
#include<conio.h>
 
int main()
 {
  int a,b,x,y,t,hcf,lcm;
 
  cout<<"Enter 1st number"<<endl;
  cin>>x;
  cout<<"Enter 2nd number"<<endl;
  cin>>y;
 
  a=x;
  b=y;
 
  while(b!=0)
  {
    t=b;
    b=a%b;
    a=t;
  }
 
  hcf=a;
  lcm=(x*y)/hcf;
 
  cout<<"HCF : "<<hcf<<endl;
  cout<<"LCM :"<<lcm;
 getch();
  return 0;
}
