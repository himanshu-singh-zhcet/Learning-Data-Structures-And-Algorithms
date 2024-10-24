#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
for(int i =0;i<5;i++){
    int element;
    cout<<"enter the elements";
    cin>>element;
    v.push_back(element);
}
for (int i=0;i<v.size();i++){
    cout<<v[i]<<endl;
}
// for each loop
for(int element :v){
    cout<<element<<" ";
}
return 0;
}