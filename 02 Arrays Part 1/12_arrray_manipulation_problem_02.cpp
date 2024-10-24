// Find the second largest element in the given array
#include<iostream>
using namespace std;
int main(){
    int arr[]={2,3,5,7,6,1};
    int max =0;
    int index=0;
    for(int i =0;i<6;i++){
        if(arr[i]>=max){
            max=arr[i];
            index=i;
        }
    }
    cout<<max<<endl;
    cout<<index<<endl;
    arr[index]=-1;
    for(int i =0;i<6;i++){
        cout<<arr[i];
    }
    int second_max=0;
    for(int i =0;i<6;i++){
        if(arr[i]>=second_max){
            second_max=arr[i];
        }
    }
    cout<<"the second largest element in the array is "<<second_max<<endl;
return 0;
}
