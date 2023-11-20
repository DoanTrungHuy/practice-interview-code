class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        const int n = garbage.size();
        unordered_map<char, int> last_index;
        unordered_map<char, int> cnt_garbage;
        
        for (int i = 0; i < n; ++i) {
            for (char c : garbage[i]) {
                last_index[c] = i;
                cnt_garbage[c]++;
            }
        }
        
        vector<int> pref(n + 1);
        
        for (int i = 0; i < n - 1; ++i) {
            pref[i + 1] = pref[i] + travel[i];
        }
        
        string type_garbage = "MPG";
        int ans = 0;
        
        for (char c : type_garbage) {
            ans += pref[last_index[c]] + cnt_garbage[c];
        }
        
        return ans;
    }
};