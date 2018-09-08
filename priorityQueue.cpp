#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
	//int *right,*left;
	double freq;
	char ch;
	node(double fre,char chr) : freq(fre),ch(chr){}
};

 
int main()
{
  vector<node> data;
  struct node nod(22.23,'g');
  data.push_back(nod);   
  cout<<data[0].freq;
  return 0;
}