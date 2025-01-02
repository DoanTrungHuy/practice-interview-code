class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const int n = words.size();
        vector<int> pref(n + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < n; ++i) {
            char first = words[i][0];
            char last = words[i].back();
            pref[i + 1] = pref[i] + (vowels.count(first) && vowels.count(last));
        }

        vector<int> ans;
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            ans.push_back(pref[r + 1] - pref[l]);
        }

        return ans;
    }
};
