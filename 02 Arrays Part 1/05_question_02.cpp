// find the last occurence of an element in a array 
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
    int index =0;
    for(int i=0;i<6;i++){
        if(v[i]==x){
            index =i;
        }
    }
    cout<<index;


return 0;
}