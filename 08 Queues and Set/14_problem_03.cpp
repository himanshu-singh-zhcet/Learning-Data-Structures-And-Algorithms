#include<iostream>
#include<set>
using namespace std;
bool check(string s1){
    if(s1.size()<26){
        return false;
    }
    // converting whole string in lowercase
    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    set<char> alphabets;
    for(auto ch: s1){
        alphabets.insert(ch);
    }
     
    return alphabets.size() == 26;

}   
int main(){
    string input;
    cin>>input;
    cout<<check(input);
return 0;
}