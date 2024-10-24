#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool checking_one_to_many(string s1, string s2){
  unordered_map<char,char> m; 
    for(int i =0;i<s1.length();i++){
       if(m.find(s1[i])!= m.end()){ 
          if(m[s1[i]] != s2[i]){
            return false;
          }
       }
       else{
        m[s1[i]] = s2[i];
       }
    }
    return true;
}
bool checkisomorphic(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }  

    // checking one to many mapping from s1-->s2
    bool c1 = checking_one_to_many(s1,s2);

    // checking one to many mapping from s1-->s2
    bool c2 = checking_one_to_many(s2,s1);

    return c1&&c2;
}
int main()
{
    string s1, s2;
    cout<<"enter the strings"<<endl;
    cin >> s1 >> s2;
    cout << (checkisomorphic(s1, s2) ? "is isomorphic" : "is not isomorphic");
    return 0;
}