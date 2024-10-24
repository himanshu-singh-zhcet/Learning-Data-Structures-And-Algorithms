// count the occurence of an particular element x element 
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v(6);
    for(int i =0;i<6;i++){
    cout<<"enter the elements of vector: ";
    cin>>v[i];
    }
    int x;
    cout<<"enter the value of x";
    cin>>x;
    int count =0;
    for(int i=0;i<6;i++){
        if(v[i]==x){
            count++;
        }
    }
    cout<<count;
    ;


return 0;
}