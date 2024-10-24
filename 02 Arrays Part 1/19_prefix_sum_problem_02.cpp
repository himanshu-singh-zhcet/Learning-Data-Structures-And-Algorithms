/* check if we can partition thhe array into two subarrays with equal sum. more formally,
chechk that thhe prefix sum of a part of the array is equal to the suffix sum of the rest of  array  */
#include<iostream>
#include<vector>
using namespace std;
bool check_prefix_sufix_sum(vector<int> &v1){
    int total_sum=0;
    for(int i=0;i<v1.size();i++){
        total_sum=total_sum+v1[i];
    }
    int prefix_sum=0;
    int suffix_sum=0;
    for(int i=0;i<v1.size();i++){
        prefix_sum =prefix_sum+v1[i];
        suffix_sum=total_sum-prefix_sum;
        if(prefix_sum==suffix_sum){
            return true;
        }
    }
    return false;
    }
int main(){
    cout<<"enter the size of array: ";
    int n;
    cin>>n;
    vector<int> v;   // 6,2,4,3,1
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    cout<<check_prefix_sufix_sum(v);
return 0;
}
