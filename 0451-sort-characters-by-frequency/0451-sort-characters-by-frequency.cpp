class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        vector<pair<char, int>> arr;
        for (auto p : freq) {
            arr.push_back(p);
        }
        sort(arr.begin(), arr.end(),
             [](auto& a, auto& b) { return a.second > b.second; });
        string ans;
        for (auto p : arr) {
            ans.append(p.second, p.first);
        }
        return ans;
    }
};