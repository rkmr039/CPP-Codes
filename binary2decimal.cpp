#include<iostream.h>
#include<conio.h>
#include<math.h>
int main()
  {
  int x[10],count=0,n,sum=0,j,k=0;
  cout<<"Enter Binary Number: ";
  cin>>n;
  
  while(n>0)
  {
  x[count]=n%10;
  n=n/10;
  count++;
  }
  for(j=0;j<count;j++)
  {
      sum=sum+x[j]*pow(2,k);
      k++;
  }
  cout<<"Decimal Number: "<<sum;
  getch();
  return 0;
  }
