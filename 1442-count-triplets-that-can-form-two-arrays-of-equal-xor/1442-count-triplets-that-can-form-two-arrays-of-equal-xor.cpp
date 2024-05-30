class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int n = arr.size();
        int pref[n + 1];
        memset(pref, 0, sizeof(pref));
        
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] ^ arr[i];
        }
        
        int cnt = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j; k < n; ++k) {
                    if ((pref[j] ^ pref[i]) == (pref[k + 1] ^ pref[j])) {
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};