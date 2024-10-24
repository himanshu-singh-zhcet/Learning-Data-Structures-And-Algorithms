#include<iostream>
#include<map>
using namespace std;
int main(){
    multimap<string,int> record;
    record.insert(make_pair("Ria",8171));
    record.insert(make_pair("Ritik",8292));
    record.insert(make_pair("Ria",9008));
    
    for(auto pair: record){
        cout<<"Name: "<<pair.first<<endl;;
        cout<<"Mobile No: "<<pair.second<<endl;
    }
    cout<<record.count("Ria");
return 0;

return 0;
}