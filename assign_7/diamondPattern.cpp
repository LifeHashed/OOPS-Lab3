#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    int n;
    cin>>n;
   int s1=0,s2=2*n-2;
   for(int i=n+1;i>1;i--,s1+=2){
       if(i!=n+1)
       cout << setw(i) << '$' << setw(s1) << '$' << endl;
       else
       cout << setw(i) << '$' <<endl;
   }
   while(s1+1>0){
       cout<<"*";
       s1--;
   }
   cout<<endl;
   for(int i=2;i<n+2;i++,s2-=2){
       if(i!=n+1)
       cout << setw(i) << '&' << setw(s2) << '&' << endl;
       else
       cout << setw(i) << '&' << endl;
   }
}
