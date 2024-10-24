// Given an integer, find out the sum of digits using recursion
#include<iostream>
using namespace std;
int sum_digits(int n){
    if(n>=0 && n<=9){
        return n;
    }
    int ans;
    ans = sum_digits(n/10)+n%10;
    return ans;
}
int main(){
    int n;
    cout<<"enter a integer: ";
    cin>>n;
    int result=sum_digits(n);
    cout<<result;
return 0;
}
