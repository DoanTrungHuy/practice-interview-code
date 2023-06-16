#define INSERT 1
#define DELETE 0

using ll = long long;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<vector<ll>> events;
        ll sum = 0;
        ll xMax = INT_MIN, yMax = INT_MIN;
        ll xMin = INT_MAX, yMin = INT_MAX;
        
        for (vector<int> rectangle : rectangles) {
            ll x1 = rectangle[0];
            ll y1 = rectangle[1];
            ll x2 = rectangle[2];
            ll y2 = rectangle[3];
            
            sum += 1LL*(y2 - y1)*(x2 - x1);
            
            xMin = min(xMin, x1);
            xMax = max(xMax, x2);
            yMin = min(yMin, y1);
            yMax = max(yMax, y2);
            
            events.push_back({x1, INSERT, y1, y2});
            events.push_back({x2, DELETE, y1, y2});
        }

        sort(events.begin(), events.end());
        
        multiset<pair<ll, ll>> line;
        
        for (vector<ll> event : events) {
            ll curr = event[0];
            ll choose = event[1];
            ll y1 = event[2], y2 = event[3];
            
            if (choose == INSERT) {
                auto it = line.lower_bound({y1, y2});
                
                if (it != line.end() and it->first < y2) {
                    return false;
                }
                
                if (it != line.begin() and (--it)->second > y1) {
                    return false;
                }
                
                line.insert({y1, y2});
            }
            else {
                line.erase(line.lower_bound({y1, y2}));
            }
        }
        
        return sum == 1LL*(yMax - yMin)*(xMax - xMin);
    }
};