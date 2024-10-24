class Solution {
public:
    // brute force approch
    // int f(int i, vector<int> &arr){
    //     if(i>=arr.size()){
    //         return 0;
    //     }
    //     return max(arr[i]+f(i+2,arr),f(i+1,arr));
    // }

    // dp memoziation approch
    // vector<int> dp;
    // int f(int i, vector<int> &arr){
    //     if(i>=arr.size()){
    //         return 0;
    //     }
    //     if(dp[i]!= -1){
    //         return dp[i];
    //     }

    //     return dp[i]=max(arr[i]+f(i+2,arr),f(i+1,arr));
    // }

    // dp tabulation
    vector<int> dp;
    int f(int i, vector<int> &arr){
        int n =arr.size();
        dp[n-1] = arr[n-1];
        dp[n-2] = max(arr[n-1],arr[n-2]);
        for(int i =n-3;i>=0;i--){
            dp[i] = max(arr[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        dp.resize(nums.size()+10,-1);
        return f(0,nums); 
    }
};