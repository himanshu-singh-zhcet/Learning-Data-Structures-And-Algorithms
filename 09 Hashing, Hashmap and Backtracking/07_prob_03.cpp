#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool canmakeequal(vector<string> &v){
    int n = v.size();
    unordered_map<char,int> m;
    for(auto ele: v){
        for(auto chr: ele){
          m[chr]++;
        }
    }
    
    for(auto ele:m){
        if(ele.second%n != 0){
            return false;
        }
    }
    return true;

}
int main(){
    int n;
    cout<<"enter the size of vector: ";
    cin>>n;
    vector<string> v(n);
    for(int i= 0;i<n;i++){
        cin>>v[i];
    }
    cout<<(canmakeequal(v)? "yes" :"No")<<endl;
return 0;
}