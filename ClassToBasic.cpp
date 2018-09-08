#include<iostream>
using namespace std;
class time1
{
 int min,hr;
public:
time1(){ hr=0;min=0;}
time1(int a, int b){hr=a;min=b;}
void show()
{cout<<"\nHours: "<<hr<<" Minutes :"<<min<<endl;}
operator int()
{ return ( hr*60+min);}
void main()
{
int minutes;
 cout<<"\n===Type Conversion From Class To Basic Type==="<<endl;
time1 t1(2,40);
t1.show();
minutes= t1;
minutes.show();

}

    
