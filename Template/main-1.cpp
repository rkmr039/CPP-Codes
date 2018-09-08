#include <iostream>

using namespace std;

template <class t>
t absolute( t n)
{
   return (n<0) ? -n: n;
}
/*int abs( int n)
{
    return (n<0) ? -n:n;
}*/
int main()
{
    cout << "Program to show use of template function." << endl;
    int a=-6;
    //double db= -6.6;
    cout<<"absolute("<<a<<")"<<absolute(a)<<endl;//<<"absolute("<<db<<")"<<absolute(db)<<endl;
     //cout<<"abs("<<a<<")"<<abs(a)<<endl;
    return 0;
}
