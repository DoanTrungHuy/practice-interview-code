class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int p = values[0];
        int a = 0;
        
        for (int i = 1; i < n; ++i) {
            a = max(a, values[i] - i + p);
            p = max(p, values[i] + i);
        }
        
        return a;
    }
};