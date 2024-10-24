#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> target_sum_pair(vector<int> &v , int target_sum){
unordered_map<int, int> m;
vector<int> ans(2,-1);
for(int i =0;i<v.size();i++){
    if(m.find(target_sum-v[i]) != m.end()){
        ans[0] =  m[target_sum-v[i]];
        ans[1] = i;
    }
    else{
        m[v[i]] = i;
    }
}
return ans;
}
int main(){
    int n;
    cout<<"enter the size of vector: ";
    cin>>n;
    cout<<"enter the elements of vector "<<endl;
    vector<int> v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }

    int target_sum;
    cout<<"enter the target sum: ";
    cin>>target_sum;
    vector<int> ans = target_sum_pair(v,target_sum);
    cout<<ans[0]<<"  "<< ans[1]<<endl;
return 0;
}