#define INSERT 0
#define DELETE 1

using ll = long long;
const ll MOD = 1e9 + 7;

class Solution {
public:
    ll calc(multiset<pair<ll, ll>> &line, ll width) {
        ll prev = INT_MIN;
        ll total = 0LL;
        
        for (auto [bottom, up] : line) {
            prev = max(prev, bottom);
            total = (total + max(0LL, (up - prev)*width)%MOD)%MOD;
            prev = max(prev, up);
        }
        
        return total;
    }
    
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<vector<ll>> events;
        
        for (vector<int> rectangle : rectangles) {
            ll x1 = rectangle[0]*1LL;
            ll y1 = rectangle[1]*1LL;
            ll x2 = rectangle[2]*1LL;
            ll y2 = rectangle[3]*1LL;
            
            events.push_back({x1, INSERT, y1, y2});
            events.push_back({x2, DELETE, y1, y2});
        }
        
        sort(events.begin(), events.end(), [&](vector<ll> a, vector<ll> b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        
        multiset<pair<ll, ll>> line;
        ll prev = INT_MIN;
        ll ans = 0LL;
        
        for (vector<ll> event : events) {
            ll curr = event[0];
            ll choose = event[1];
            ll y1 = event[2], y2 = event[3];
            
            if (prev != INT_MIN) {
                ans = (ans + calc(line, curr - prev)) % MOD;
            }
            
            if (choose == INSERT) {
                line.insert({y1, y2});
            }
            else {
                line.erase(line.find({y1, y2}));
            }
            
            prev = curr;
        }
        
        return (int)ans;
    }
};