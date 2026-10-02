class Solution {
public:
    void solve(int open, int close, string& curr, vector<string>& ans) {
        if(close==0 && open==0) {
            ans.push_back(curr);
            return;
        }
        if(open > 0) {
            curr.push_back('(');
            solve(open-1,close,curr,ans);
            curr.pop_back();
        }
        if(close > open) {
            curr.push_back(')');
            solve(open,close-1,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        solve(n,n,curr,ans);
        return ans;
    }
};