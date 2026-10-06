class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        int add = 0;

        for(int i=0;i<n;i++) {
            if(s[i] == '(') {
                st.push('(');
            } else {
                if(st.empty()) {
                    add++;
                } else {
                    st.pop();
                }
            }
        }
        if(!st.empty()) {
            while(!st.empty()) {
                add++;
                st.pop();
            }
        }
        return add;
    }
};