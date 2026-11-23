class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 1;
        int maxlen = 2;

        while(left < n && right < n) {
            int i = left;
            int j = right;
            while(j < n-1 && nums[i]+nums[j] == nums[j+1]) {
                i++;
                j++;
            }
            maxlen = max(maxlen, j - left + 1);
            left = j;
            right = j+1;
        }

        return maxlen;
    }
};