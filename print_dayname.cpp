 #include <iostream>
 #include<conio.h>
 using namespace std;
 int main() {
    int d,m,y,status = 1,od,temp;
    cout<<"\n Should be +ve integer \n Day: 1 - 31\n Month: 1 - 12\n Year: 1900 - 2018\n : ";
    do{od = 0;
    cout<<"\nEnter Date(DD/MM/YYYY) \n" ;
    cin>> d >> m >> y;
    if(d >=1 && d <=31 && m>=1 && m <= 12 && y >= 1700 && y<=2018){
    if( (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)) )
            od++;
    temp = y % 400;
    od+= (5*(temp/100));
    temp = temp % 100;
    temp--;
    od+= (2*(temp /4 ))+(temp - (temp / 4))+(d);
    switch(m-2){
        case 0:
        case 1: od+=  3; break;
        case 2: od+=  6; break;
        case 3: od+=  8; break;
        case 4: od+=  11;break;
        case 5: od+=  13;break;
        case 6: od+=  16;break;
        case 7: od+=  19;break;
        case 8: od+=  21;break;
        case 9: od+=  24;break;
        case 10:od+=  26;break;
        case 11:od+=  29;break;}
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
