class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cnt = 1;
        int candidate = nums[0];

        for(int i=1; i<n; i++) {
            if(cnt == 0) {
                candidate = nums[i];
            }
            if(nums[i] == candidate) {
                cnt++;
            } else {
                cnt--;
            }
        }

        return candidate;
    }
};