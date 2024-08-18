class Solution {
private:
    vector<vector<long long>> memo;
    vector<int> energy_drink_a, energy_drink_b;
    
public:
    long long dp(int state, int i) {
        if (i >= energy_drink_a.size()) {
            return 0;
        }
        if (memo[state][i] != -1) {
            return memo[state][i];
        }
        if (state == 0) {
            return memo[state][i] = max(
                dp(state, i + 1) + energy_drink_a[i],
                dp(1, i + 1)
            );
        } 
        else {
            return memo[state][i] = max(
                dp(state, i + 1) + energy_drink_b[i],
                dp(0, i + 1)
            );
        }
    };
    
    long long maxEnergyBoost(vector<int>& energy_drink_a, vector<int>& energy_drink_b) {
        this->energy_drink_a = energy_drink_a;
        this->energy_drink_b = energy_drink_b;
        memo.resize(2, vector<long long>(energy_drink_a.size(), -1));
        return max(dp(1, 0), dp(0, 0));
    }
};
