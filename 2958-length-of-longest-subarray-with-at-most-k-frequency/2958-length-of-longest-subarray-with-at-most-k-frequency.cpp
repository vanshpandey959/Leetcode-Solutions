class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int left = 0, right = 0;
        int maxlen = 0;
        
        while(right < n) {
            mpp[nums[right]]++;
            while(mpp[nums[right]] > k) {
                mpp[nums[left]]--;
                left++;
            }
            maxlen = max(maxlen, right-left+1);
            right++;
        }

        return maxlen;
    }
};