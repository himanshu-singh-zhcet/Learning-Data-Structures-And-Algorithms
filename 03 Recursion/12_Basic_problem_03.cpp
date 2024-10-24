#include<iostream>
int f(int n ){
    // base case
    if(n==0){
        return 0;
    }
    // assumption 
    return f(n-1)+((n%2==0)?(-n):(n));
}
using namespace std;
int main(){
    cout<<f(5);
return 0;
}