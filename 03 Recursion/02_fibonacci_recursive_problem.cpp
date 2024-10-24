// program to find n_th fibonacci number
#include<iostream>
using namespace std;
int fib(int n){
    // base case
    if(n==0 || n==1){
        return n;
    }
    int ans=fib(n-1)+fib(n-2);
    return ans;
}
int main(){
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    int result=fib(n);
    cout<<result<<endl;
    

return 0;
}
