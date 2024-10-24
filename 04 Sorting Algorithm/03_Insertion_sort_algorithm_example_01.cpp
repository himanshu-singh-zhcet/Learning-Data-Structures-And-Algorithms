#include<iostream>
#include<vector>
using namespace std;
void insertion_sort(vector<int> &v1){
    int n =v1.size();
    for(int i=1;i<n;i++){
        int current =v1[i];
        int j =i-1;
        while(j>=0 && v1[j]>current){
            v1[j+1]=v1[j];
            j--;
        }
        v1[j+1]=current;
    }

}
int main(){
    int n;
    cout<<"enter te size of vector: ";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i<<"th elemnet of vector: ";
        cin>>v[i];
    }
    insertion_sort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
return 0;
}