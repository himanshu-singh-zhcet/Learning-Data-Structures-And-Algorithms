#include<iostream>
using namespace std;
int gcd(int a ,int b){
    if(b>a) return gcd(b,a);
   //base case
   if(b==0){
    return a;
   }
   return gcd(b,a%b);
}
int main(){

int n,m;
cout<<"enter the two numbers"<<endl;
cin>>n>>m;
int x = gcd(n,m);
cout<<"the greatest common divisor is : "<<x;
return 0;
}