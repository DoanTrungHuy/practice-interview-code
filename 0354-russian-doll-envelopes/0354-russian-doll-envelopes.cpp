class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b){
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        const int n = envelopes.size();
        vector<int> dp;
        
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if (it == dp.end()) {
                cout << "push = " << envelopes[i][1] << '\n';
                dp.push_back(envelopes[i][1]);
            }
            else {
                *it = envelopes[i][1];
            }
        }
        
        return dp.size();
    }
};