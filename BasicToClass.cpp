#include<iostream>
using namespace std;
class time1
{
 int min,hr;
public:
time1(){ hr=0;min=0;}
time1(int t){hr=t/60;min=t%60;}
void show()
{cout<<"\nHours: "<<hr<<" Minutes :"<<min<<endl;}

void main()
{
 cout<<"\n===Type Conversion From Basic to Class Type==="<<endl;
time1 t1(150);
t1.show();
}

    