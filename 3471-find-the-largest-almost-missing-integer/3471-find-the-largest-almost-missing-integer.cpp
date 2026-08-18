class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = -1;
        vector<int> f(51, 0);

        for(int i=0;i<n;i++) {
            f[nums[i]]++;
            maxi = max(maxi, nums[i]);
        }

        if(k==n) return maxi;

        maxi = -1;
        int num0 = false;
        int numl = false;
        for(int i=0;i<51;i++) {
            if(f[i] == 1) {
                maxi = max(maxi, i);
                if(i == nums[0]) num0 = true;
                if(i == nums[n-1]) numl = true;
            }
        }

        if(k==1) return maxi;

        if(1<k && k<n) {
            if(num0 && numl) return max(nums[0], nums[n-1]);
            else if (num0) return nums[0];
            else if(numl) return nums[n-1];
            else return -1;
        }

        return -1;
    }
};