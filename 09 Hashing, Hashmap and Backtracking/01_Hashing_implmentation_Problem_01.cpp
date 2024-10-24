// problem 01 Implement hash table with closed addressing 
#include<iostream>
#include<vector>
#include<list>
using namespace std;
class hashing{
    vector<list> hashtable;
    int buckets;
    public:
    hashing(int size){
        hashtable.resize(size);
        buckets = size;
    }
    int hashvalue(int key){
        return key%buckets;
    }
    void add(int key){
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);
    }
    list<int>:: iterator search(int key){   // this function returns a iterator 
    int idx = hashvalue(key);
    return find(hashtable[idx].begin(), hashtable[idx].end(),key);
    }
    void delete(int key){
       int idx  = hashvalue(key);
       if(serach(key) != hashtable[idx].end()){
        hashtable[idx].erase(search(key));
        cout<<key<<"key is deleted "<<endl;
       }
       else{
        cout<<"the key is not deleted"<<endl;
       }
    }
};
int main(){
    hashing h(10);
    h.add(6);
    h.add(5);
    h.add(3);
    h.delete(3);
    h.delete(3);


return 0;

}