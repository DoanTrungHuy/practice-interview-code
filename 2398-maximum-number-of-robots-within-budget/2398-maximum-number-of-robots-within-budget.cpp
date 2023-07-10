using ll = long long;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        multiset<ll> ms;
        ll j = 0, s = 0, ans = 0;
        ll n = chargeTimes.size();
        
        for (int i = 0; i < n; ++i) {
            ms.insert(chargeTimes[i]);
            s += runningCosts[i];
            while (j < n and ms.size() and *ms.rbegin() + (i - j + 1)*s > budget) {
                s -= runningCosts[j];
                ms.erase(ms.lower_bound(chargeTimes[j]));
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};