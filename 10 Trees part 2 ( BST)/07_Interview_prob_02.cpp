#include<iostream>
#include<vector>
using namespace std;

bool checkIdenticalBSTHelper(vector<int> &v1, vector<int> &v2, int a1 ,int a2, int minvalue, int maxvalue){
    // find the first element in v1 within range 
    int i;
    for(i=a1;i<v1.size();i++){
        if(v1[i]>minvalue && v1[i]<maxvalue) break;
    }
    
    // finding the first element in v2 with in range
    int j;
    for(j=a2;j<v2.size();j++){
        if(v2[j]>minvalue && v2[j]<maxvalue) break;
    }

    // if no element found with in range  (leaf nodes)
    if(i == v1.size() && j== v2.size()) return true;

    // if only one vector does not have element with in range
    if((i==v1.size() && j != v2.size()) or (i!=v1.size() && j ==v2.size())){
        return false;
    } 

    // checking if both elemnets are equal 
    if(v1[i]!=v2[j]) return false;

    return checkIdenticalBSTHelper(v1,v2,a1+1,a2+1,minvalue,v1[i]) && checkIdenticalBSTHelper(v1,v2,a1+1,a2+1,v2[j],maxvalue);

   
    
}
bool checkIdenticalBSTs(vector<int> &v1, vector<int> &v2){
    return checkIdenticalBSTHelper(v1,v2,0,0,-1 ,100);
}
int main(){
    int n;
    cout<<"enter the size of vectors: ";
    cin>>n;
    vector<int> v1(n),v2(n);
    cout<<"enter the values of vector 1"<<endl;
    for(int i =0;i<n;i++){
        cin>>v1[i];
    }
    cout<<"enter the values of vector 2"<<endl;
    for(int i =0;i<n;i++){
        cin>>v2[i];
    }

    cout<<checkIdenticalBSTs(v1,v2);
return 0;
}