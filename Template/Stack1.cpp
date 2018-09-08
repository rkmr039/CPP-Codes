
#include <iostream>

using namespace std;
const int m =100;

template <class t>
class mystack
{
  private:
      t arr[m];
      int top;
 public:
    mystack()
    {top=-1;}
    void push( t value)
    {
        arr[++top]=value;
        cout<<endl<<value<<" inserted at index "<<top<<endl;
    }
    void pop()
    {
      cout<<arr[top]<<" Poped Out from index "<<top<<endl;
       top--;
       //cout<<temp;
    }
    void show()
    {
    	int num=top;
       while(num>=0)
       {
         cout<<endl<<num<<":"<<arr[num]<<" ";
         num--;
       }
       cout<<endl<<endl;
    }
};

int main()
{
    cout << "=====Stack Using Template Function=====" << endl;
    // Stack for int data type
     mystack<int> s1;
     s1.push(5);
     s1.push(6);
     s1.push(7);
     cout<< "Stack of Int: ";
      s1.show();
     cout<<"Pop Out :";
     s1.pop();
     mystack<float> s2;
     s2.push(3L);
     s2.push(4L);
     s2.push(5l);
     cout<<"\nStack of Float : ";
     s2.show();
     cout<<"Pop up: ";
     s2.pop();
    return 0;
}
