class Solution {
public:
    void f(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int ind){
        if(ind >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        f(nums, temp, ans, ind+1);
        temp.pop_back();

        f(nums, temp, ans, ind+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        f(nums,temp,ans,0);
        return ans;
    }
};