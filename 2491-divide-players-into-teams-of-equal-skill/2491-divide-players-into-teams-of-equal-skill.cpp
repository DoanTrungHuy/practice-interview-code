class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        const int n = skill.size();
        
        long long mi = LLONG_MAX, ma = LLONG_MIN;
        
        for (int i = 0; i < n; ++i) {
            mi = min(mi, 1LL*skill[i]);
            ma = max(ma, 1LL*skill[i]);
        }
        
        long long target = ma + mi;
        long long s = 0;
        int cnt[1001] = {};
        int np = 0;
        
        for (int i = 0; i < n; ++i) {
            if (cnt[target - skill[i]]) {
                s += skill[i] * (target - skill[i]);
                cnt[target - skill[i]]--;
                np++;
            }
            else {
                cnt[skill[i]]++;
            }
        }
        
        if (np != n / 2) {
            return -1;
        }
        
        return s;
    }
};