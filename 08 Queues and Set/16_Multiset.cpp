#include<iostream>
#include<set>
using namespace std;
int main(){
    multiset<int> s1;
    s1.insert(3);
    s1.insert(2);
    s1.insert(1);
    s1.insert(2);
    for(auto value:s1){
        cout<<value<<" ";
    }
return 0;
}