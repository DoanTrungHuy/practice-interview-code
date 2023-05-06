int memo[8][1 << 9];

class Solution {
private:
    vector<vector<char>> seats;
    int m, n;
    vector<int> masks;
    
public:
    int countBit(int num) {
        int res = 0;
        while (num) {
            res += num & 1;
            num >>= 1;
        }
        return res;
    }
    int dp(int i, int prev) {
        if (i == m) {
            return 0;
        }
        if (memo[i][prev] != -1) {
            return memo[i][prev];
        }
        for (int curr = 0; curr < (1 << n); ++curr) {
            if ((curr & masks[i]) == curr and !(curr & (curr >> 1))) {
                if (!((curr >> 1) & prev) and !((prev >> 1) & curr)) {
                    memo[i][prev] = max(memo[i][prev], countBit(curr) + dp(i + 1, curr));
                }
            }
        }
        return memo[i][prev];
    }
    int maxStudents(vector<vector<char>>& seats) {
        memset(memo, -1, sizeof(memo));
        m = seats.size(), n = seats[0].size();
        masks.resize(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                masks[i] |= seats[i][j] == '.' ? 1 << j : 0;
            }
        }
        return dp(0, 0);
    }
};