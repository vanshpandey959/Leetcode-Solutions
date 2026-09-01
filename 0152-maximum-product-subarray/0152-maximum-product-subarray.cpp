class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = INT_MIN;
        int maxPrefix = 1, maxSuffix = 1;
        for(int i=0;i<n;i++) {
            if(maxPrefix==0) maxPrefix = 1;
            if(maxSuffix==0) maxSuffix = 1;
            maxPrefix = maxPrefix * nums[i];
            maxSuffix = maxSuffix * nums[n-i-1];
            maxProduct = max({maxProduct,maxPrefix, maxSuffix});
            
        }
        return maxProduct;
    }
};