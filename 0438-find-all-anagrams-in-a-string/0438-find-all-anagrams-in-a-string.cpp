class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> cntS(26, 0), cntP(26, 0);
        int n = s.size();
        int m = p.size();
        if (m > n) {
            return {};
        }
        for (int i = 0; i < m; ++i) {
            cntS[s[i] - 'a']++;
            cntP[p[i] - 'a']++;
        }
        vector<int> ans;
        if (cntS == cntP) {
            ans.push_back(0);
        }
        for (int i = m; i < n; ++i) {
            cntS[s[i] - 'a']++;
            cntS[s[i - m] - 'a']--;
            if (cntS == cntP) {
                ans.push_back(i - m + 1);
            }
        }
        return ans;
    }
};