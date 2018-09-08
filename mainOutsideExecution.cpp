#include <iostream>
using namespace std;


class World 
{
    public:

    World() { cout << "Hello World!!!" << endl; }

    ~World() { cout << "Goodbye World!!!" << endl; }
};

World world;

int main()
{
	cout<<"This is main"<<endl;
	return 0;
}
