// count the no of triplets whose sum is equal to the given value x
#include<iostream>
using namespace std;
int main(){
    int arr[]={3,1,2,4,0,6};
    int targetsum = 5;
    int count =0;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=j+1;k<6;k++){
            if(arr[i]+arr[j]+arr[k]==targetsum){
                count++;
            }
            else{
            }
            }
        }
    }
    cout<<"the no of triplets is "<<count;
return 0;
}