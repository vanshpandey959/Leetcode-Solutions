class Solution {
public:
    vector<int> generateRow(int row) {
        vector<int> ans;
        long long num = 1;
        ans.push_back(num);

        for(int i=1;i<row;i++) {
            num = num * (row-i);
            num = num / i;
            ans.push_back(num);
        }

        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};