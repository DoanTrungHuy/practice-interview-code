class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        using tp = tuple<int, int, int>;
        
        priority_queue<tp, vector<tp>, greater<tp>> pq;
        const int n = times.size();
        
        for (int i = 0; i < n; ++i) {
            pq.push({times[i][0], 1, i});
            pq.push({times[i][1], 0, i});
        }
        
        priority_queue<int, vector<int>, greater<int>> leave_;
        int chair = 0;
        unordered_map<int, int> mp;
        
        while (pq.size()) {
            auto [_, is_arrive, i] = pq.top();
            pq.pop();
            
            if (is_arrive) {
                if (leave_.size()) {
                    mp[i] = leave_.top();
                    leave_.pop();
                }
                else {
                    mp[i] = chair;
                    chair++;
                }
                
                if (i == targetFriend) {
                    return mp[i];
                }
            }
            else {
                leave_.push(mp[i]);
            }
        }
        
        return -1;
    }
};