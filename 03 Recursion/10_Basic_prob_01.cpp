#include<iostream>
using namespace std;
void priting(int i,int n){
    // base case 
    if(i==n){
        cout<<i;
        return;
    }
    cout<<i<<" ";
    priting(i+1,n);
    return;
}

void f(int n){
    // base case 
    if(n<1) return;
    f(n-1);
    cout<<n<<" ";
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
   // priting(1,n);
    cout<<endl;
    f(n);
    
return 0;
}