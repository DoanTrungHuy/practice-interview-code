int memo[11][2][2];

class Solution {
private:
    set<int> set_digits;
    string s;
    int sz;

public:
    int dp(int i, int is_zero, int state) {
        if (i == sz) {
            return !is_zero;
        }
        if (memo[i][is_zero][state] != -1) {
            return memo[i][is_zero][state];
        }
        int ans = 0;
        int lm = (state ? (s[i] - '0') : 9);
        for (int d = 0; d <= lm; ++d) {
            if (set_digits.count(d) || (is_zero && (d == 0))) {
                ans += dp(i + 1, is_zero && (d == 0), state && (d == lm));
            }
        }
        return memo[i][is_zero][state] = ans;
    }

    // 01

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // dp(i, state)
        s = to_string(n);
        sz = s.size();

        for (string d : digits) {
            set_digits.insert(stoi(d));
        }

        memset(memo, -1, sizeof(memo));

        return dp(0, 1, 1);
    }
};