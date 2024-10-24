#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dp;
int ftb(int i,int j,vector<int> &arr){
    if(i==j or i+1 =j){
        return 0;
    } 
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = INT16_MAX;
    for(int k =i+1;k<j;k++){
        ans = min(ans,ftb(i,k,arr)+ftb(k,j,arr)+arr[i]*arr[j]*arr[k]);
    }
    return dp[i][j] = ans;
   
}
int main(){
    dp.clear();
    dp.resize(1005,vector<int> (1005,-1));
    int n;
    cout<<"enter the size of n: "<<endl;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i++;i<n){
        cin>>v[i];
    }
    cout<<ftb(0,n-1,v);

    // bottom up approch
    dp.resize(1005,vector<int> (1005,-1));
    for(int len =3;len<=n;len++){
        for(int i =0;i+len-1<n;i++){
            int j = i+len-1;
            dp[i][j] = INT16_MAX;
            for(int k = i+1;k,j;k++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+v[i]*v[j]*v[k]);
            }
        }
    }
return 0;
}