class Solution {
public:
    unordered_set<string> st;
    int n;
    int maxLen = 0;

    void solve(int i, string& curr, int count, string& s) {
        if(count < 0) return;
        if(i == n) {
            if(count == 0) {
                if(curr.length() > maxLen) {
                    maxLen = curr.length();
                    st.clear();
                } 
                if(curr.length() == maxLen) {
                    st.insert(curr);
                }
            }
            return;
        }

        if(s[i]!='(' && s[i]!=')') {
            curr.push_back(s[i]);
            solve(i+1,curr,count,s);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);
        solve(i+1,curr,count+(s[i]=='(' ? 1 : -1),s);
        curr.pop_back();
        solve(i+1,curr,count,s);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        st.clear();
        string curr = "";
        
        solve(0, curr, 0, s);
        return vector<string>(st.begin(), st.end());
    }
};