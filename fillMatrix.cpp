#include <iostream>
#include <cstring>

using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=0 ;i<t; i++)
	{
		int n,q;
		cin>>n;
		cin>>q;
		int matrix[n][q],k,l,j,ind;
		int array[n*q];int temp=q,value;
		// set -1 for all ind of array[] and set all diagnol elements to 0 	
		for(k=1; k<=n; k++)
		{
		    for(l=1; l<=q; l++)
		    {
		        if(k==l) {array[q*(k-1)+l]=0;matrix[k][l]=0;}
		        else  {array[k]=-1;matrix[k][l]=-1;}
		    }
		}
		while(temp)
		{
			cin>>k>>l>>value;
			matrix[k][l]=value;
			ind =q*(k-1)+l;
			array[ind] =value;
			//cout<<k<<" "<<l<<" "<<matrix[k][l]<<" "<<array[ind]<<endl;
			temp--;	
		}
		cout<<endl;
		for(k=1; k<=n; k++)
		{
		    for(l=1; l<=q; l++)
		    {
		    	ind = q*(k-1)+l;
			cout<<k<<" "<<l<<" "<<matrix[k][l]<<" "<<array[ind]<<endl;
		    }
		}
	}
	return 0;
}