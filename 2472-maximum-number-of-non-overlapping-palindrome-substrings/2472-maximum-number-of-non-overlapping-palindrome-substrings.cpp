class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) {
                return false;
            }
            r--;
            l++;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int start = 0;
        int n = s.size();
        int ans = 0;

        for(int r=k-1; r < n; r++) {

            for(int len = k; len <= r-start+1; len++) {

                int l = r - len + 1;
                if(isPalindrome(s, l, r)) {
                    ans+=1;
                    start = r+1;
                    break;
                }
            }
        }
        return ans;
    }
};