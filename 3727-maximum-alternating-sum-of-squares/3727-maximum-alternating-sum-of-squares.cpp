class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // vector<long long> a(n);
        for (int i = 0; i < n; i++)
            nums[i] = 1LL * nums[i] * nums[i];

        nth_element(nums.begin(), nums.begin() + n/2, nums.end());

        long long ans = 0;
        int k = n / 2;   

        for (int i = 0; i < k; i++)
            ans -= nums[i];

        for (int i = k; i < n; i++)
            ans += nums[i];

        return ans;
    }
};