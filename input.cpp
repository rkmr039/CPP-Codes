
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
class student{
char *name;
private:
void getdata()
{
 // getline(cin>>ws,name);
// cin.getline(name,size);take input with white spaces and terminates when pressed enter 
//cin.read(name,size); take input of size specified  with white and enter 
cin>>name;
//cin.get(); input of one character only
}
};

int main()
{
       // string name;
student s;
s.getdata();
        cout<<"Name: ";
        //getline(cin>>ws,name);
        // fgets(s.name, 10, stdin); // this would limit your input to 10 characters.

        
    //    fgets(s.name, 20, stdin);
        cout<<"\nYou Entered: \n\n";
// cout.write(name,size);

        cout<<name<<endl;
}
