#include <iostream>

using namespace std;

template <  class t>
void swap( t a, t b)
{
    cout<<" \n\nBefore Swapping :"<<a<<b<<endl;
    t temp=a;
    a=b;
    b=temp;
    cout<<" \n\nAfter Swapping :"<<a<<b<<endl;
}


int main()
{
    cout << "=====Program to Swap Two Numbers using template =====" << endl;
    int c = 5;
    int  d= 11;
    swap(c,d);
    float fc= 6.6;
    float fd= 5.5;
    swap(6.6,5.5);
    return 0;
}
