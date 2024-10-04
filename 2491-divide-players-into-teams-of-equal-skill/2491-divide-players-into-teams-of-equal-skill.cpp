class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        const int n = skill.size();
        long long s = 0;
        
        for (int i = 0; i < n / 2; ++i) {
            if (skill[i] + skill[n - i - 1] != skill[0] + skill[n - 1]) {
                return -1;
            }
            s += 1LL*skill[i]*skill[n - i - 1];
        }
        
        return s;
    }
};