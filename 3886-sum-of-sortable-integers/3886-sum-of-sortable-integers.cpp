class Solution {
public:
    bool isRotationPossible(vector<int>& vec1, vector<int>& vec2) {
        int k = vec1.size();
        int decreasingPoints = 0, position = -1;
        for(int j=0;j<k;j++) {
            int a = vec1[j];
            int b = vec1[(j+1) % k];

            if(a > b) {
                decreasingPoints++;
                position = j;
            }
            if(decreasingPoints > 1) break;
        }
        if(decreasingPoints > 1) return false;
        int startRotationPostion = (decreasingPoints == 0) ? 0 : (position + 1) %k;

        for(int j=0;j<k;j++) {
            if(vec1[(startRotationPostion + j) % k] != vec2[j]) {
                return false;
            }
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        vector<int> divs;
        for(int i=1;i<=n;i++) {
            if(n % i == 0) {
                divs.push_back(i);
            }
        }

        int ans = 0;
        for(int k: divs) {
            bool isSortable = true;
            for(int s=0;s<n;s+=k) {
                vector<int> vec1(nums.begin() + s, nums.begin() + s + k);
                vector<int> vec2(sorted.begin() + s, sorted.begin() + s + k);

                if(!isRotationPossible(vec1, vec2)) {
                    isSortable = false;
                }
            }
            if(isSortable) {
                ans += k;
            }
        }

        return ans;
    }
};