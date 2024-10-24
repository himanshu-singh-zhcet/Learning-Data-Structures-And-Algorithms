#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// method 1
// bool checkanagrams(vector<string> &v){
//     int n = v.size();
//     unordered_map<char,int> m;
//     for(auto ele: v){
//         for(auto chr: ele){
//           m[chr]++;
//         }
//     }
    
//     for(auto ele:m){
//         if(ele.second%n != 0){
//             return false;
//         }
//     }
//     return true;

// }
// int main(){
//     vector<string> v(2);
//     for(int i= 0;i<2;i++){
//         cin>>v[i];
//     }
//     cout<<(checkanagrams(v)? "yes" :"No")<<endl;
// return 0;
// }

// method 2

bool checkanagram(string s1, string s2){
    unordered_map<char,int> m;
    for(auto c1: s1){
        m[c1]++;
    }
    for(auto c2: s2){
        if(m.find(c2)== m.end()){
            return false;
        }
        else{
            m[c2]--;
        }
    }
    for(auto ele: m){
        if(ele.second != 0){
            return false;
        }
    }
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<(checkanagram(s1,s2)? "anagram" : "not anagram");
    return 0;
}