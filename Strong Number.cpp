
#include<iostream.h>
#include<conio.h>
int main()
{
  int n,i,f,r,sum=0,temp;

  cout<<"Enter a number: ";
  cin>>n;
 
  temp=n;
  while(n)
  {
      i=1,f=1;
      r=n%10;

      while(i<=r)
      {
         f=f*i;
        i++;
      }
      sum=sum+f;
      n=n/10;
  }
  if(sum==temp)
      cout<<" is a strong number";
  else
      cout<<" is not a strong number";
  getch();
  return 0;
}
