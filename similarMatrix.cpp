#include <iostream>
#include <cstring>

using namespace std;
int n,q;
	
	

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=0 ;i<t; i++)
	{
		
		cin>>n;
		cin>>q;
		int matrix[n][q],k,l,j,ind,value;
		int array[n*q];int temp=q;// temp: numer of inputs available
		// set -1 for all ind of array[] and set all diagnol elements to 0 	
		for(k=1; k<=n; k++)
		{
		    for(l=1; l<=q; l++)
		    {
		        if(k==l) {array[q*(k-1)+l]=0;matrix[k][l]=0;}
		        else  {array[q*(k-1)+l]=-1;matrix[k][l]=-1;}
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
		    	if(array[ind]==-1) // 
		    	{
		    		if(array[l] ==-1)
		    			array[l]=3;
		    		else if(array[k]==-1)
		    			array[k]=3;
		    		
				matrix[k][l]=abs(array[k]-array[l]);
				array[ind]=matrix[k][l];
		    	}
		    	
		    }
		}

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