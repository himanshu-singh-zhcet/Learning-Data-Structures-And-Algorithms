#include<iostream>
#include<set>
using namespace std;
int main(){
    set<string> invite_list;
    int n;
    cin>>n;
    while(n--){
        string name;
        cin>>name;
        invite_list.insert(name);
    }
    cout<<"printing invite list"<<endl; 
    for(auto name: invite_list){
        cout<<name<<endl;
    }
return 0;
}