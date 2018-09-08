#include<iostream.h>
#include<conio.h>
int main()
{

int a[50][50],i,j,n,m,l=1;
cout<<"Enter the order of matrix (must be n*n) "<<endl;
cin>>n;
cout<<" * ";
cin>>m;
if (n==m)
{
cout<<"\nTranspose possible "<<endl;
}
else
{
cout<<"Transpose not possible ";
l=0;
}
if (l)
{
cout<<"\nEnter the elements of matrix "<<endl;
for (i=1;i<=n;i++)
{
for (j=1;j<=n;j++)
cin>>a[i][j];
}
cout<<"\nElements of matrix 1 are ";
for (i=1;i<=n;i++)
{
cout<<endl;
for (j=1;j<=n;j++)
cout<<a[i][j]<<" ";
}
cout<<"\nTranspose of matrix  ";
for (i=1;i<=n;i++)
{
cout<<endl;
for (j=1;j<=n;j++)
cout<<a[j][i]<<" ";
}
}
getch();
return 0;
}
