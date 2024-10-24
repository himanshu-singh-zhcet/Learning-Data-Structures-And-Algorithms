class Solution {
public:
    // int f(int n){
    //     if(n==0 or n==1){
    //         return 1;
    //     }
    //     if(n==2){
    //         return 2;
    //     }
    //     int sum =0;
    //     for(int k=1;k<=n;k++){
    //         // k--> potential root
    //         sum+= f(k-1)*f(n-k);
    //     }
    //     return sum;
    // }

    vector<int> dp;
    int f(int n){
        if(n==0 or n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(dp[n] != -1) return dp[n];
        int sum =0;
        for(int k=1;k<=n;k++){
            // k--> potential root
            sum+= f(k-1)*f(n-k);
        }
        return dp[n] = sum;
    }
    int numTrees(int n) {
        dp.clear();
        dp.resize(30,-1);
        return f(n);
        /* bottom up solution 
        dp.resize(30,0);
        dp[0]=dp[1] =1;
        dp[2] = 2;
        for(int i =3;i<=n;i++){
            // f(i)
            for(int k=1;k<=i;k++){
                // k- potential root
                dp[i] += dp[k-1]*dp[i-k];
            }
        }
        return dp[n];   */
    }
}; 