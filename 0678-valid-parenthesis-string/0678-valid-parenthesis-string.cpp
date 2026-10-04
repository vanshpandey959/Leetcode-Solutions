class Solution {
public:
    bool solve(string s, int ind, int open,vector<vector<int>>& dp) {
        if(ind==s.size()) {
            return open==0;
        }

        bool isValid = false;
        if(dp[ind][open] != -1){
            return dp[ind][open];
        }

        if(s[ind] == '(') {
            isValid |= solve(s, ind+1, open+1,dp);
        } else if(s[ind] == '*') {
            isValid |= solve(s, ind+1, open+1,dp);
            isValid |= solve(s, ind+1, open,dp);
            if(open>0) {
                isValid |= solve(s, ind+1, open-1,dp);
            }
        } else {
            if(open > 0) {
                isValid |= solve(s, ind + 1, open - 1, dp);
            }
        }

        return dp[ind][open] = isValid;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(s,0,0,dp);
    }
};