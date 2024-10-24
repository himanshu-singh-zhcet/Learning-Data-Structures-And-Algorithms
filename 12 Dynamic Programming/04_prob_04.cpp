#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

// memoization
int f(vector<int> &heights,int i,int k){
    if(i == heights.size()-1){
        return 0;
    }
    if(dp[i]!= -1){
        return dp[i];
    }
    int ans = INT8_MAX;
    for(int j =1;j<=k;j++){
        if(i+j>= heights.size()){
            break;
        }
        ans = min(ans,abs(heights[i]-heights[i+j])+f(heights,i+j,k));
    }
    return dp[i]=ans;
}

int fbu(vector<int> &heights,int k){   // for this approch intialize the dp vector with int_max
    int n = heights.size();
    dp[n-1] = 0;
    for(int i = n-2;i>=0;i--){
        for(int j= 1;j<=k;j++){
            if(i+j>=n) break;
            dp[i] = min(dp[i],abs(heights[i]-heights[i+j])+dp[i+j]);
        }
    }
    return dp[0];
}
int main(){
    dp.clear();
    dp.resize(100005,-1);
    cout<<"enter the value of n snd k:"<<endl;
    int n,k;
    cin>>n>>k;
    vector<int> v(n,0);
    cout<<"enter the element of the vector"<<endl;
    for(int  i =0;i<n;i++){
        cin>>v[i];
    }
    cout<<f(v,0,k);

return 0;
}