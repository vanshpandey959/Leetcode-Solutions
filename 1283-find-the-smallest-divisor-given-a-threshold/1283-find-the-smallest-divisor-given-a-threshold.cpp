class Solution {
public:
    int getSum(vector<int>& nums, int div) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0;i<n;i++) {
            int summ = ceil((double)nums[i]/div);
            sum += summ;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int low = 1, high = maxi;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            int sum = getSum(nums, mid);
            if(sum <= threshold) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};