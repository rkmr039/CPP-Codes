// programe for sstring to int conversion
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int digits[5];
	char integers[]="12354"; 
	for(int x=0;x<sizeof(integers)-1; x++)
	{
		/*1 = '1'-'0'*/
		digits[x]=integers[x]-'0';
		cout<<digits[x];
	}

	return 0;
}