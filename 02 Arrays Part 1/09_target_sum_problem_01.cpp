// find the total numbers of pairs in the given array whose sum is equal to the given value x
#include<iostream>
using namespace std;
int main(){
    int arr[]={3,4,6,7,1};
    int targetsum = 7;
    int count =0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]+arr[j]==targetsum){
                count++;
            }
            else{
            }
        
        }
    }
    cout<<"the no of pairs is "<<count;
return 0;
}
