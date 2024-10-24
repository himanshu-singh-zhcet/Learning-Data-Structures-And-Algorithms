// given Q queries, check if the given no is present in array or not
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of n: ";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    const int N= 1e5+10;
    vector<int> freq(N, 0);
    for(int i =0;i<n;i++){
        freq[v[i]]++;
    }
    cout<<"enter queries: "<<endl;
    int q;
    cin>>q;
    while(q--){
        int queryelement;
        cin>>queryelement;
        cout<<freq[queryelement]<<endl;
    }
return 0;
}