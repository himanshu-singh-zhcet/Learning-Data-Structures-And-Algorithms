#include<iostream>
using namespace std;
int main(){
    int arr[]={4,6,8,9,11,12,2};
    int a=0;
    int length=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<=length;i++){
        if(arr[i]==11){
        cout<<i<<endl;
        a=1;
        break;
        }
        else{}
    }
    if(a!=1){
        cout<<"-1";
    }
return 0;
}
