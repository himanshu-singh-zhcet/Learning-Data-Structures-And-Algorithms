#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_multimap< string , int > fruitcount;
    fruitcount.insert(make_pair("apple",8));
    fruitcount.insert(make_pair("banana",9));
    fruitcount.insert(make_pair("apple",7));

    for(auto pair: fruitcount){
        cout<<"fruit name: "<<pair.first<<endl;;
        cout<<"count No: "<<pair.second<<endl;
    }
    
    
    
    
    
    
    
    

return 0;
}