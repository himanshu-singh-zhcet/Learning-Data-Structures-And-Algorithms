#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s1;
    cout<<"enter the values"<<endl;
    int n,p,q;
    cin>>n>>p>>q;
    for(int i = 0;i<=n;i++){
        for(int j =0;j<=n;j++){
           int correct =i;
           int incorrect =j;
           int unattempted = n-(i+j);
           if(unattempted>=0){
            int score = correct*p+incorrect*q;
            s1.insert(score);
           }
           else{
            break;
           }
        }
    }
    cout<<"Different possible mark"<<s1.size();
return 0;
}