class Solution {
public:
    long long numTrip(vector<int>& time, long long totalTime) {
        long long trip = 0;
        for (int t : time) {
            trip += totalTime / t;
        }
        return trip;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        const int n = time.size();
        long long l = 1, r = 1e14;
        long long ans = r;
        while (l <= r) {
            long long m = (l + r) >> 1;
            if (numTrip(time, m) >= totalTrips) {
                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};