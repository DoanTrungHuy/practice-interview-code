class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;

        gaps.push_back(startTime[0]);

        const int n = startTime.size();

        for (int i = 1; i < n; ++i) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }

        gaps.push_back(eventTime - endTime[n - 1]);

        const int m = gaps.size();

        int k_for_free = k + 1;
        int ans = 0;
        int s = 0;

        for (int i = 0, j = 0; i < m; ++i) {
            s += gaps[i];
            if (i - j + 1 == k_for_free) {
                ans = max(ans, s);
                s -= gaps[j];
                j++;
            }
        }

        return ans;
    }
};