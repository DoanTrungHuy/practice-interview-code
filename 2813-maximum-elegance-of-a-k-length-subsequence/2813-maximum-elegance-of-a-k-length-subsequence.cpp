class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        const int n = items.size();
        using vi = vector<int>;
        
        sort(items.begin(), items.end(), [](vi a, vi b){
            return a[0] > b[0];
        });
        
        long long ans = 0;
        long long sum = 0;
        
        set<int> s;
        stack<int> lst_not_first;
        
        for (int i = 0; i < k; ++i) {
            long long p = items[i][0];
            long long c = items[i][1];
            
            sum += p;
            
            if (s.count(c)) {
                lst_not_first.push(p);
            }
            else {
                s.insert(c);
            }
        }
        
        long long sz = s.size();
        ans = max(ans, sum + sz*sz);
        
        for (int i = k; i < n; ++i) {
            long long p = items[i][0];
            long long c = items[i][1];
            
            if (s.count(c) == 0 && lst_not_first.size() > 0) {
                sum -= lst_not_first.top();
                lst_not_first.pop();
                sum += p;
                s.insert(c);
            }
            
            long long sz = s.size();
            ans = max(ans, sum + sz*sz);
        }
        
        return ans;
    }
};