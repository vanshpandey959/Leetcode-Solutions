class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        int equal = 0;

        for(int i=0;i<n;i++) {
            if(nums[i] < target) {
                count++;
            }
            if(nums[i] == target) {
                equal++;
            }
        }

        vector<int> ans;
        for(int i=0;i<equal;i++) {
            ans.push_back(count+i);
        }

        return ans;
    }
};