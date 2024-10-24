
// sort an array consisiting of 0s and 1s
// method 1
/* here we r tracing the array 2 times
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,1,0,0,1,0,1,0};
    int count=0;
    for(int i=0;i<8;i++){
        if(arr[i]==0){
            count++;
        }
    }
    for(int i=0;i<8;i++){
        if(i<count){
            arr[i]=0;
        }
        else{
            arr[i]=1;
        }
    }
    for(int i=0;i<8;i++){
        cout<<arr[i];
    }
return 0;
} */

// method 2
#include<iostream>
#include<vector>
using namespace std;
void sort_zeroes_and_ones(vector<int> &v1){
    int left =0;
    int right =v1.size()-1;
    while(left<right){
        if(v1[left]==1 && v1[right]==0){
            v1[left++]=0;
            v1[right--]=1;
        }
        if(v1[left]==0){
            left++;
        }
        if(v1[right]==1){
            right--;
        }
    }
    
}
int main(){
    vector<int> v;
    v={1,1,0,0,1,0,1,0};
    cout<<v.size()<<endl;
    sort_zeroes_and_ones(v);
    for(int i=0;i<8;i++){
        cout<<v[i];
    }
return 0;
}
