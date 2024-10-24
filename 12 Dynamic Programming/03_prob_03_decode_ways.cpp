class Solution {
public: 
     
    // recursion approch
    // int string_to_int(string s){
    //     if(s.size()==1) return s[0]-'0';
    //     return (s[0]-'0')*10+(s[1]-'0');
    // }
    
    // int f(string str, int idx){
    //     // base case 
    //     if(str[idx]=='0') return 0;
    //     if(idx>=str.size()) return 0;
    //     if(idx== str.size()-1){
    //         if(str[idx]=='0') return 0;
    //         else return 1;
    //     }
    //     // case for two digit no 
    //     if(idx == str.size()-2){
    //     bool can_form_2_digits = string_to_int(str.substr(idx,2))<=26;
    //     return can_form_2_digits+f(str,idx+1);
    //     }
    //     // case for more than two digit no
    //     bool can_form_2_digits = string_to_int(str.substr(idx,2))<=26;
    //     return f(str,idx+1) + ((can_form_2_digits) ? f(str,idx+2):0);
    // }

    
    // memoziation
    // int string_to_int(string s){
    //     if(s.size()==1) return s[0]-'0';
    //     return (s[0]-'0')*10+(s[1]-'0');
    // }
    // vector<int> dp;
    // int f(string str, int idx){
    //     // base case 
    //     if(str[idx]=='0') return 0;
    //     if(idx>=str.size()) return 0;
    //     if(idx== str.size()-1){
    //         if(str[idx]=='0') return 0;
    //         else return 1;
    //     }
    //     // case for two digit no 
    //     if(idx == str.size()-2){
    //     bool can_form_2_digits = string_to_int(str.substr(idx,2))<=26;
    //     return can_form_2_digits+f(str,idx+1);
    //     }
    //     if(dp[idx] != -1) return dp[idx];
    //     bool can_form_2_digits = string_to_int(str.substr(idx,2))<=26;
    //     return dp[idx] = f(str,idx+1) + ((can_form_2_digits) ? f(str,idx+2):0);
    // }

    // tabulation
    int string_to_int(string s){
        if(s.size()==1) return s[0]-'0';
        return (s[0]-'0')*10+(s[1]-'0');
    }
    vector<int> dp;
    int fbu(string str){
        dp.clear();
        dp.resize(105,-1);
        int n = str.size();
        dp[n-1] = (str[n-1]=='0') ? 0:1;
        bool can_form = string_to_int(str.substr(n-2,2))<=26;
        if(str[n-2]=='0') dp[n-2]=0;
        else dp[n-2] = dp[n-1]+can_form;
        for(int i = n-3;i>=0;i--){
            if(str[i]=='0'){
                dp[i]=0;
                continue;
            }
            bool can_form_2_digits = string_to_int(str.substr(i,2))<=26;
            dp[i] = dp[i+1] + ((can_form_2_digits)?dp[i+2]:0);
        }
        return dp[0];
    }
    int numDecodings(string s) {
        int n =s.size();
        if(n==1){
            if(s[n-1]=='0') return 0;
            else return 1;
        }
        return fbu(s);
    }
};