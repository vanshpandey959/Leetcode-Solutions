class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int> temp;
        // vector<int> frq(nums.size(), 0);
        help(0,nums,ans);
        return ans;
    }
    void help(int ind, vector<int>& nums, vector<vector<int>>& ans){
        if(ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++) {
            swap(nums[i], nums[ind]);
            help(ind+1,nums,ans);
            swap(nums[i], nums[ind]);
        }
    } 
};