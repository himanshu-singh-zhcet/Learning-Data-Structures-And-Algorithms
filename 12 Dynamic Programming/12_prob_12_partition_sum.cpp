class Solution {
public:
    // bool f(vector<int> &arr, int i, int k){
    //     if(k==0){
    //         return true;
    //     }
    //     if(i == arr.size()) return false;
    //     if(arr[i]<=k){  
    //         // we can include or exclude
    //         return f(arr,i+1,k-arr[i])  or f(arr,i+1,k);
    //     }
    //     else{
    //         // always execlude
    //         return f(arr,i+1,k);
    //     }
    // }

    vector<vector<int>> dp;
    bool f(vector<int> &arr, int i, int k){
        if(k==0){
            return true;
        }
        if(i == arr.size()) return false;
        if(dp[i][k] != -1) return dp[i][k];
        if(arr[i]<=k){  
            // we can include or exclude
            return dp[i][k] = f(arr,i+1,k-arr[i])  or f(arr,i+1,k);
        }
        else{
            // always execlude
            return dp[i][k] = f(arr,i+1,k);
        }
    }
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(int i =0;i<nums.size();i++){
            s+= nums[i];
        }
        if(s%2 != 0){
            return false;
        }
        dp.clear();
        dp.resize(205,vector<int>(20005,-1));
        return f(nums,0,s/2);
    }
};