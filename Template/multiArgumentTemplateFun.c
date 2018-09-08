
#include <iostream>

using namespace std;

template <class type>
int find(type* array, type value, int size )
{
    for ( int i=0; i<size; i++)
     {
         if(array[i]==value)
             return i;
         return -1;
     }
}

char charr[]={1,3,5,9,11,13};
char ch= 5 ;
int intarr[]={1,3,5,9,11,13};
int in=9;
long loarr[]={ 1L,3L,5L, 9L, 11L, 13L};
long lo=5L;
int main()
{
    cout<<"Find:"<<ch<<" In Character Array: "<<find(charr,ch,6)<<endl;
    cout<<"Find:"<<in<<" In Integer Array: "<<find(intarr,in,6)<<endl;
    cout<<"Find:"<<lo<<" In Long Integer Array: "<<find(loarr,lo,6)<<endl;
    return 0;
}
