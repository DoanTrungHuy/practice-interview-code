class Solution {
public:
    unordered_map<int, int> um;
    string frequencySort(string s) {
        for (char c : s) {
            um[c]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (um[a] != um[b]) {
                return um[a] > um[b];
            }
            return a < b;
        });
        return s;
    }
};