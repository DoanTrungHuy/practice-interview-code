class Solution {
public:
    using ll = long long;
    long long totalCost(vector<int>& costs, int k, int c) {
        int n = costs.size();
        priority_queue<ll,vector<ll>,greater<ll>> pq1, pq2;
        int i = 0, j = n - 1;
        while (i < c) {
            pq1.push(costs[i++]);
        }
        if (c > n - c) {
            c = n - c;
        }
        int cnt = 0;
        while (cnt < c) {
            pq2.push(costs[j--]);
            cnt++;
        }
        ll res = 0;
        while (k--) {
            if (pq1.size() == 0) {
                res += pq2.top();
                pq2.pop();
                if (i <= j) {
                    pq2.push(costs[j--]);
                }
            }
            else if (pq2.size() == 0) {
                res += pq1.top();
                pq1.pop();
                if (i <= j) {
                    pq1.push(costs[i++]);
                }
            }
            else if (pq1.top() <= pq2.top()) {
                res += pq1.top();
                pq1.pop();
                if (i <= j) {
                    pq1.push(costs[i++]);
                }
            }
            else {
                res += pq2.top();
                pq2.pop();
                if (i <= j) {
                    pq2.push(costs[j--]);
                }
            }
        }
        return res;
    }
};