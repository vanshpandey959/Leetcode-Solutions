class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()==0) return 0;
        int count = 1;
        int maxCount = 1;

        for(int i=1; i<nums.size(); i++) {
            if((nums[i]-1) == nums[i-1]) {
                count++;
                maxCount = max(maxCount, count);
            } else if(nums[i] == nums[i-1]) {
                continue;
            } else {
                count = 1;
            }
        }

        return maxCount;
    }
};