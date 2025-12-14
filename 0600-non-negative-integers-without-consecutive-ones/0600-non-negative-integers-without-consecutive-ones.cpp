int memo[32][2][2];
string tmp;

class Solution {
private:
    string s;
    int sz;

public:
    int dp(int i, int state, int is_one) {
        if (i == sz) {
            // cout << tmp << '\n';
            return 1;
        }

        if (memo[i][state][is_one] != -1) {
            return memo[i][state][is_one];
        }

        int ans = 0;

        int limit_number = state ? (s[i] - '0') : 1;
        
        for (int d = 0; d <= limit_number; ++d) {
            if (is_one && d == 1) {
                continue;
            }
            // tmp += (d + '0');
            ans += dp(i + 1, state && (d == limit_number), d == 1);
            // tmp.pop_back();
        }

        return memo[i][state][is_one] = ans;
    }

    int findIntegers(int n) {
        // dp(i_current, state, is_one)

        while (n) {
            s += (n & 1) + '0';
            n >>= 1;
        }

        reverse(s.begin(), s.end());

        sz = s.size();

        memset(memo, -1, sizeof(memo));

        // cout << s << '\n';

        return dp(0, 1, 0);
    }
};