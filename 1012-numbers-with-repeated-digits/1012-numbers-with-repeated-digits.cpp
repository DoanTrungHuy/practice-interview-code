// string tmp;
int memo[11][2][2][1025];

class Solution {
private: 
    string s;
    int sz;

public:
    int dp(int i, int is_zero_at_head, int state, int mask) {
        if (i == sz) {
            return mask != 0;
        }
        if (memo[i][is_zero_at_head][state][mask] != -1) {
            return memo[i][is_zero_at_head][state][mask];
        }
        int limit_number = state ? (s[i] - '0') : 9;
        int ans = 0;
        for (int d = 0; d <= limit_number; ++d) {
            if ((1 << d) & mask) {
                continue;
            }
            int new_state = state && d == limit_number;
            int new_bitmask = mask;
            if (!is_zero_at_head || (d != 0)) {
                new_bitmask = mask | (1 << d);
            }
            int new_is_zero_at_head = is_zero_at_head && d == 0;
            // tmp += (d + '0');
            ans += dp(i + 1, new_is_zero_at_head, new_state, new_bitmask);
            // tmp.pop_back();
        }
        return memo[i][is_zero_at_head][state][mask] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        // dp(i, is_zero_at_head, state, bitmask)
        // Coi như là xuất hiện ít nhất 2 lần
        // Phủ định lại thì xuất hiện nhiều nhất 1 lần
        // 2 <= number, 2 > number -> 1 >= number >= 0
        // sử dụng bitmask
        s = to_string(n);
        sz = s.size();
        memset(memo, -1, sizeof(memo));

        return n - dp(0, 1, 1, 0);
    }
};