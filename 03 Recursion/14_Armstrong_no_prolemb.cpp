#include<iostream>
#include<algorithm>
using namespace std;

int pow(int base,int power){
    // base case
    if(power ==0) return 1;
    if(power%2==0){
        // power is even
        int result= pow(base,power/2);
        return result*result;
    }
    else{
        int result=pow(base,(power-1)/2);
        return base*result*result;
    }
    
}


int f(int n ,int d){
    // base case 
    if(n==0){
        return 0;
    }
    return f(n/10,d) + pow(n%10,d);
}
int main(){
    int n;
    cout<<"Enter the no: ";
    cin>>n;
    int no_of_digits = 0;
    int temp = n;
    while(temp>0){
        temp = temp/10;
        no_of_digits++;
    }
    int result = f(n,no_of_digits);
    if(result == n){
        cout<<"it is a armstrong no";
    }
    else{
        cout<<"it is not a armstrong no ";
    }

return 0;
}