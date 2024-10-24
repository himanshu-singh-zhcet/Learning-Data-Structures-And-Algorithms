#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> set1;
 
    // inserting into a set
    set1.insert(3);
    set1.insert(2);
    set1.insert(1);
    set1.insert(5);
    set1.insert(8);
    set1.insert(4);
    cout<<set1.size()<<endl;

    // traversing a set
    set<int>:: iterator itr;
    for(itr = set1.begin();itr != set1.end();itr++){
        cout<<*itr<<endl;
    }
    
    
    // deletion of element
    auto itr1 = set1.begin();
    advance(itr1,3);     // moving iterator by three position   
    set1.erase(8);       
    set1.erase(itr1);

    for(itr = set1.begin();itr != set1.end();itr++){
        cout<<*itr<<endl;
    }

    // search operation
    if(set1.find(5)!=set1.end()){
        cout<<"value is present"<<endl;
    }
    else{
        cout<<"value is not present"<<endl;
    }
return 0;

}