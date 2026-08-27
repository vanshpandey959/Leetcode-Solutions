class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        long long n = grid.size();
        long long total = n * n;

        long long sum = total * (total + 1) / 2;
        long long sqsum = total * (total + 1) * (2 * total + 1) / 6;

        long long s = 0, sq = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                s += grid[i][j];
                sq += (long long)grid[i][j] * grid[i][j];
            }
        }

        long long diff = s - sum;                  // R - M
        long long sumRM = (sq - sqsum) / diff;    // R + M

        long long repeat = (diff + sumRM) / 2;
        long long missing = repeat - diff;

        return {(int)repeat, (int)missing};
    }
};