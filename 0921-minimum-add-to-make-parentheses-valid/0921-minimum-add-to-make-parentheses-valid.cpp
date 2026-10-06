class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        int add = 0;
        int brac = 0;

        for(int i=0;i<n;i++) {
            if(s[i] == '(') {
                brac++;
            } else {
                if(brac <= 0) {
                    add++;
                } else {
                    brac--;
                }
            }
        }
        if(brac > 0) {
            add += brac;
        }
        return add;
    }
};