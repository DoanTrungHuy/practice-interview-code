class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        const int n = costs.size();
        int i = 0, j = n - 1;
        long long res = 0;
        while (k--) {
            while (pq1.size() < candidates and i <= j) {
                pq1.push(costs[i++]);
            }
            while (pq2.size() < candidates and i <= j) {
                pq2.push(costs[j--]);
            }
            int a = pq1.size() == 0 ? INT_MAX : pq1.top();
            int b = pq2.size() == 0 ? INT_MAX : pq2.top();
            if (a <= b) {
                pq1.pop();
                res += a;
            } else {
                pq2.pop();
                res += b;
            }
        }
        return res;
    }
};