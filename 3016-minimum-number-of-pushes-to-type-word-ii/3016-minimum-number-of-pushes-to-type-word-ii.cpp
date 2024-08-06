class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> cnt;
        
        for (char c : word) {
            cnt[c]++;
        }
        
        const int n = word.size();
        set<pair<int, int>> s;
        
        for (int i = 0; i < n; ++i) {
            s.insert({cnt[word[i]], word[i]});
        }
        
        vector<pair<int, int>> v(s.begin(), s.end());
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int curr_num = 2;
        int times = 1;
        int ans = 0;
        
        for (auto [k, _] : v) {
            if (curr_num == 10) {
                curr_num = 2;
                times++;
            }
            ans += k*times;
            curr_num++;
        }
        
        return ans;
    }
};