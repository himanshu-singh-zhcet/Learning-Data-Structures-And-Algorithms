#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int max_length_zero_sum_subarray(vector<int> &v){
    int n = v.size();
    int subarray_length=0;
    unordered_map<int,int> m;
    int prefix_sum = 0;

    for(int i =0;i<n;i++){
        prefix_sum = prefix_sum+v[i];
        if(m.find(prefix_sum)!= m.end()){
            subarray_length=max(subarray_length,i-m[prefix_sum]);
           
        }
        else{
            m[prefix_sum] =i;
           
        }
    }
    return subarray_length;
}
int main(){
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    vector<int> v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }
    cout<<max_length_zero_sum_subarray(v);


return 0;
}