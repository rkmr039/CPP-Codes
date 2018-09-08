#include <iostream>
#include<string.h>
#include<conio.h>

class string1
{
    int length;
    char *text;

    public:

     string1()
      {
	length=0;
	text=new char[length+1];
      }

     string1(char *s)
      {
	 length=strlen(s);
	 text=new char[length+1];
	 strcpy(text,s);
      }

  friend string1 operator +(string1 s1, string1 s2);
     void show()
     {
      cout<<text<<endl;
     }

};
string1 operator +(string1 s1, string1 s2)
     {
	  string1 s3;
	  s3.length=s1.length+s2.length;
	  s3.text= new char [s3.length+1];
	  s3.text= strcpy(s3.text,s1.text);
	  s3.text= strcat(s3.text,s2.text);
	  return (s3);
     }
int main()
{
 clrscr();
 string1 s1("Hello"),s2("World"),s3;
 s3=s1+s2;
 cout<<"\nConcatenated String :"<<endl;
 s3.show();
 getch();
 return (0);
}
