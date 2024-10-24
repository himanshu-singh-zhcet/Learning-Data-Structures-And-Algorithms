#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of vector: ";
    cin>>n;
    vector<int> input(n);
    for(int i = 0;i<n;i++){
        cin>>input[i];
    }
    map<int, int > m;
    for(int i =0;i<n;i++){
        // storing ther frequency of every element
        m[input[i]]++;
    }

     int sum =0;
    // finding  the sum of repititve elements 
    // pair element - frequency 
    for(auto pair: m){
        if(pair.second>1){
            sum = sum+pair.first;
        }
    }
    cout<<"the ans is "<< sum <<endl;

return 0;
}