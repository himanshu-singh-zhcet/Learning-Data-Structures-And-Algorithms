#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_multiset<int> s1;
    s1.insert(5);
    s1.insert(6);
    s1.insert(7);
    s1.insert(6);
    s1.insert(5);
    for(auto value :s1){
        cout<<value<<" ";
    }
return 0;
}