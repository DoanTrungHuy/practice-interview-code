class Solution {
private:
    unordered_map<string, int> compress;
    int m, n;
    vector<long long> pMask;
    
public:
    long long memo[61][1 << 16];
    
    long long dp(int i, int mask) {
        if (mask == ((1 << m) - 1)) {
            return 0LL;
        }
        
        if (i == n) {
            return (1LL << n) - 1;
        }
        
        if (memo[i][mask] != -1) {
            return memo[i][mask];
        }
        
        long long not_take = dp(i + 1, mask);
        long long take = (1LL << n) - 1;
        
        if ((mask | pMask[i]) != mask) {
            take = (1LL << i) | dp(i + 1, mask | pMask[i]);
        }
        
        if (__builtin_popcountll(take) <= __builtin_popcountll(not_take)) {
            return memo[i][mask] = take;
        }
        
        return memo[i][mask] = not_take;
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        m = req_skills.size();
        n = people.size();
        memset(memo, -1, sizeof(memo));
        
        for (int i = 0; i < m; ++i) {
            compress[req_skills[i]] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            long long mask = 0;
            for (int j = 0; j < people[i].size(); ++j) {
                mask |= (1LL << compress[people[i][j]]);
            } 
            pMask.push_back(mask);
        }
        
        long long mask = dp(0, 0);
        
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (mask & (1LL << i)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};