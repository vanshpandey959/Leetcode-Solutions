class Solution {
public:
    // bool solve(string s, int ind, int open,vector<vector<int>>& dp) {
    //     if(ind==s.size()) {
    //         return open==0;
    //     }

    //     bool isValid = false;
    //     if(dp[ind][open] != -1){
    //         return dp[ind][open];
    //     }

    //     if(s[ind] == '(') {
    //         isValid |= solve(s, ind+1, open+1,dp);
    //     } else if(s[ind] == '*') {
    //         isValid |= solve(s, ind+1, open+1,dp);
    //         isValid |= solve(s, ind+1, open,dp);
    //         if(open>0) {
    //             isValid |= solve(s, ind+1, open-1,dp);
    //         }
    //     } else {
    //         if(open > 0) {
    //             isValid |= solve(s, ind + 1, open - 1, dp);
    //         }
    //     }

    //     return dp[ind][open] = isValid;
    // }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        dp[n][0] = true;

        for(int ind = n-1; ind >=0; ind--) {
            for(int open = 0; open<n; open++) {
                bool isValid = false;
                if(s[ind] == '(') {
                    isValid |= dp[ind+1][open+1];
                } else if(s[ind] == '*') {
                    isValid |= dp[ind+1][open+1];
                    isValid |= dp[ind+1][open];
                    if(open>0) {
                        isValid |= dp[ind+1][open-1];
                    }
                } else {
                    if(open > 0) {
                        isValid |= dp[ind + 1][open - 1];
                    }
                }   
                dp[ind][open] = isValid;            
            }
        }
        return dp[0][0];
    }
};