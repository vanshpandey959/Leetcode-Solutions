class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int minIndex = 0;
        int maxIndex = 0;
        int mn = s[0], mx = s[0];
        bool isSorted = true;

        for(int i=1;i<n;i++) {
            if(s[i-1] > s[i]) isSorted = false;
            if(s[i] < mn) {
                minIndex = i;
                mn = s[i];
            }
            if(s[i] >= mx) {
                maxIndex = i;
                mx = s[i];
            }
        }

        if(isSorted) return 0;
        if(n==2) return -1;

        if(minIndex == 0 || maxIndex == n-1) {
            return 1;
        }
        if(minIndex == n-1 && maxIndex == 0) return 3;
        
        return 2;
    }
};