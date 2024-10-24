#include<iostream>
using namespace std;
void f(int num, int k){
     // base case 
     if(k==0) return;
     // assumption
     f(num,k-1); // the function correctly print the first k-1 multiples
     // self work
     cout<<num*k<<" ";

    }
int main(){
    int n =5;
    f(5,4);
return 0;
}