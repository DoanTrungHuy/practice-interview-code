#include <vector>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
private:
    unordered_map<int, int> reqs;
    unordered_map<int, unordered_map<int, int>> memo;

public:
    int dp(int i, int inv) {
        if (i == -1) {
            return inv == 0 ? 1 : 0;
        }

        if (memo.count(i) && memo[i].count(inv)) {
            return memo[i][inv];
        }

        int ans = 0;

        if (reqs.count(i)) {
            if (reqs[i] != inv) {
                return memo[i][inv] = 0;
            } else {
                for (int k = 0; k <= i; ++k) {
                    int new_inv = inv - (i - k);
                    if (new_inv >= 0) {
                        ans = (ans + dp(i - 1, new_inv)) % MOD;
                    }
                }
            }
        } else {
            for (int k = 0; k <= i; ++k) {
                int new_inv = inv - (i - k);
                if (new_inv >= 0) {
                    ans = (ans + dp(i - 1, new_inv)) % MOD;
                }
            }
        }

        return memo[i][inv] = ans;
    }

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        for (const auto& r : requirements) {
            reqs[r[0]] = r[1];
        }

        int max_inv = (n * (n - 1)) / 2;
        for (const auto& r : requirements) {
            if (r[1] > max_inv) {
                return 0;
            }
        }

        int last_req = reqs[n - 1];
        return dp(n - 1, last_req);
    }
};