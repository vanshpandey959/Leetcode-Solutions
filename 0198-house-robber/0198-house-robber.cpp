class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        if(n == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for(int i=2;i<n;i++) {
            int take = nums[i] + prev2;
            int nottake = 0 + prev1;
            int curr = max(take, nottake);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};