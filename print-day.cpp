 // Print Dayname for Given date using Zeller's Formula
 #include <iostream>
 #include<conio.h>
 using namespace std;
 int main() {
    int d,m,y,status = 1,od=0;
    cout<<"\n Should be +ve integer \n Day: 1 - 31\n Month: 1 - 12\n Year: 1900 - 2018\n : ";
    do{od = 0;
    cout<<"\nEnter Date(DD/MM/YYYY) \n" ;
    cin>> d >> m >> y;
    if(d >=1 && d <=31 && m>=1 && m <= 12 && y >= 1900 && y<=2018){
    if(m == 1 || m == 2) y-=1;
    if(m == 1) m=11;
    else if(m == 2) m=12;
    else m = m-2;
    od = d + (((13*m)-1)/5) + (y%100) + ((y%100)/4) + ((y/100)/4) - (2 * (y/100));
    if(od < 0 )
    {
        od = 7 - ((od*(-1)) % 7);
    }
    od = od % 7;
 	switch(od){
        case 0: cout<<"\n Sunday";   break;
        case 1: cout<<"\n Monday";   break;
        case 2: cout<<"\n Tuesday";  break;
        case 3: cout<<"\n Wednesday";break;
        case 4: cout<<"\n Thursday"; break;
        case 5: cout<<"\n Friday";   break;
        case 6: cout<<"\n Monday";   break; }}
    else cout<<"\nInvalid Input";
    cout<<"\nWant to continue...?[1/0]\n";
    cin>>status;
    }while(status == 1);
  return 0;
 }
