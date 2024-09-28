class Solution {
public:
    long long maximumTotalSum(vector<int>& h) {
        sort(h.begin(), h.end(), greater<int>());
        
        long long ans = 0;
        int ch = INT_MAX;

        for (int height : h) {
            if (ch <= height) {
                ch--;
            } 
            else {
                ch = height;
            }

            if (ch <= 0) {
                return -1;
            }

            ans += ch;
        }

        return ans;
    }
};
