class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int s = 0;
        for (int g : gain) {
            s += g;
            ans = max(ans, s);
        }
        return ans;
    }
};