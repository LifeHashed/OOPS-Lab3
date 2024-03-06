#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main(){
   double a,b,s;
   char c;
   cout << "Enter the value of starting angle, ending angle, step length and fill character: ";
   cin >> a >> b >> s >> c;
   for(double i=a;i<=b;i+=s){
       int x=floor(sin(i*3.14/180)*50);
       if (x>=0){
           cout << setw(55) << setfill(' ')<<"|"<<setw(x)<<setfill(c)<<"+"<<endl;
       }
       else{
           x=abs(x);
           cout << setw(55-x) << setfill(' ')<<"+"<< setw(x) <<setfill(c)<<"|"<<endl;
       }


   }
}
