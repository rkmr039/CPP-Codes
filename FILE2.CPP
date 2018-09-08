// File2.cpp
// Function that uses global variable declared in other file
// A global variable is declared here.
extern int commonVariable; // Declaration of global variable
#include <iostream.h>
#include <iomanip.h>
void sample()
{
	cout << endl << "Value of global variable in sample function = "
		<< commonVariable;
}
