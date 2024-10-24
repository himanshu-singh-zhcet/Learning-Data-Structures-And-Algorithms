#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of vector :";
    cin>>n;
    vector<int> v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }
    set<int> s1;
    for(int i =0;i<n;i++){
        s1.insert(v[i]);
    }
    auto itr  = s1.begin();
    itr++;
    cout<<"the second element is: "<<*itr;

return 0;
}