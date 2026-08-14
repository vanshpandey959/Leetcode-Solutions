class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        unordered_map<char, int> mpp;
        int maxlen = 0;

        while(right < n) {
            mpp[s[right]]++;

            while(mpp[s[right]] > 2) {
                mpp[s[left]]--;
                left++;
            }
            maxlen = max(maxlen, right-left+1);
            
            right++;
        }

        return maxlen;
    }
};