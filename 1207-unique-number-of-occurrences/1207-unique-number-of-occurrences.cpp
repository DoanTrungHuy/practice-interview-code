class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> us;
        unordered_map<int, int> um;
        for (int x : arr) {
            um[x]++;
        }
        for (auto [val, cnt] : um) {
            if (!us.count(cnt)) {
                us.insert(cnt);
            }
            else {
                return false;
            }
        }
        return true;
    }
};