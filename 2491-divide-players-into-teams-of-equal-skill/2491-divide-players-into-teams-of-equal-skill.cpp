class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        const int n = skill.size();
        long long s = 0;
        unordered_set<int> us;
        
        for (int i = 0; i < n / 2; ++i) {
            s += 1LL*skill[i]*skill[n - i - 1];
            us.insert(skill[i] + skill[n - i - 1]);
            if (us.size() > 1) {
                return -1;
            }
        }
        
        return s;
    }
};