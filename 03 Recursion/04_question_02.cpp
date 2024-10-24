// Given two numbers p and q ,find the value of p to power q
// method 1
/* #include<iostream>
using namespace std;
int exp(int base,int power){
    if(power==0){
        return 1;
    }
    int ans =exp(base,power-1)*base;
    return ans;
}
int main(){
    int base,power;
    cout<<"enter te base: ";
    cin>>base;
    cout<<"enter te power: ";
    cin>>power;
    int result =exp(base,power);
    cout<<result;
return 0;
}   */
// method 2
#include<iostream>
using namespace std;
int f(int base,int power){
    // base case
    if(power ==0) return 1;
    if(power%2==0){
        // power is even
        int result= f(base,power/2);
        return result*result;
    }
    else{
        int result=f(base,(power-1)/2);
        return base*result*result;
    }
    
}
int main(){
    int res=f(2,8);
    cout<<res;
return 0;
}