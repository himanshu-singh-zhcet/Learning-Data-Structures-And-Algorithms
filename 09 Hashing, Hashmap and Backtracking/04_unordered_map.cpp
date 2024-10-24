#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int, string> record;     // pair-> roll no , name
    record.insert(make_pair(1,"Ria"));
    record.insert(make_pair(2,"Ritik"));
    record.insert(make_pair(3,"Rohit"));
    
    for(auto pair: record){
        cout<<"Roll No: "<<pair.first<<endl;;
        cout<<"Name: "<<pair.second<<endl;
    }
return 0;

}