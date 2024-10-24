#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int;
using namespace std;

bool cmp(int x, int y){
    return x>y;
}
int  min_cost_to_break_grid(int m, int n,vector<int> &x, vector<int> &y){
    sort(x.begin(),x.end(),cmp);
    sort(y.begin(),y.end(),cmp);
    int hz =1;    // represent the horizontal blocks
    int vr =1;    // reprsent the vertical blocks
    int h =0,v=0;
    int ans =0;
    while(h<y.size() and v<x.size()){
        if(x[v]>y[h]){
            ans += x[v]*vr;
            hz++;
            v++;
        }
        else{
            ans += y[h]*hz;
            vr++;
            h++;
        }

    }
    while(h<y.size()){
       ans += y[h]*hz;
            vr++;
            h++; 
    }
    while(v<x.size()){
        ans += x[v]*vr;
            hz++;
            v++;
    }

    return ans;

}
int main(){
    int m,n;
    cout<<"enter hte value of m and n"<<endl;
    cin>>m>>n;
    vector<int> x;
    vector<int> y;
    for(int i =0;i<m-1;i++){
        int a;
        cin>>a;
        x.push_back(a);
    }
    for(int i =0;i<n-1;i++){
        int b;
        cin>>b;
        y.push_back(b);
    }
    cout<<min_cost_to_break_grid(m,n,x,y);

return 0;
}