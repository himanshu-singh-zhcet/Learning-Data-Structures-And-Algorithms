#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int sum =0 ;
    int n, m;
    cin>>n>>m;
    vector<int> v1(n);
    vector<int> v2(m);
    cout<<"enter the element of vector v1"<<endl;
    for(int i=0;i<n;i++){
    cin>>v1[i];
    }
    cout<<"enter the element of vector v2"<<endl;
    for(int i=0;i<m;i++){
    cin>>v2[i];
    }
    set<int> s1;
    for(auto ele : v1){
    s1.insert(ele);
    }
    for(auto ele: v2){
        if(s1.find(ele) != s1.end()){
            sum = sum+ele;
        }
    }
    cout<<"ans:"<<sum<<endl;
return 0;
}