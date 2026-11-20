class Solution {
public:
    void help(int ind, vector<vector<int>>& ans, vector<int>& temp,vector<int>& arr){
        ans.push_back(temp);
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            temp.push_back(arr[i]);
            help(i+1,ans,temp,arr);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& candidates) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        help(0,ans,temp,candidates);
        return ans;
    }
};