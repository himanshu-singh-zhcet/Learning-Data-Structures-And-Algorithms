#include<iostream>
#include<vector>
using namespace std;

void smallest_no(int d,int s){
    if(9*d<s){
        cout<<"-1";
        return;
    }
    vector<char> v(d,'0');
    int i;
    for(i =d-1;i>=0;i--){
        if(s<=9) break;
        v[i]='9';
        s-= 9;
        if(s<9){
            i--;
            break;
        } 
    }
    
    if(i==0) v[i]=char(s+'0');
    else{
    v[i]=char(s-1+'0');
    v[0]='1';
    }
    for(int i =0;i<v.size();i++){
        cout<<v[i];
    }
   
}
int main(){
    int d,s;
    cout<<"enter the value of d  and s "<<endl;
    cin>>d>>s;
    smallest_no(d,s);
return 0;
}