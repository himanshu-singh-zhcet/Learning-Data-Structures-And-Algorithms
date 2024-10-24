// given an array of integers, move all the even elements at the begining of thhe array folleowed by odd elements 
#include<iostream>
#include<vector>
using namespace std;
void sort_even_and_odds(vector<int> &v1){
    int left =0;
    int right =v1.size()-1;
    while(left<right){
        if(v1[left]%2!= 0 && v1[right]%2 ==0){
            int temp;
            temp =v1[left];
            v1[left]=v1[right];
            v1[right]=temp;
            left++;
            right--;
        }
        if(v1[left]%2==0){
            left++;
        }
        if(v1[right]%2 !=0){
            right--;
        }
    }
    }
int main(){
    vector<int> v;
    v={1,2,3,4,5,6,7,8};
    cout<<v.size()<<endl;
    sort_even_and_odds(v);
    for(int i=0;i<8;i++){
        cout<<v[i];
    }
return 0;
}