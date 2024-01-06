class Solution {
private:
    vector<int> tree;
    
public:
    void update(int node, int left, int right, int index, int value) {
        if (index < left or index > right) {
            return;
        }
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, index, value);
        update(node*2 + 1, mid + 1, right, index, value);
        tree[node] = max(tree[node*2], tree[node*2 + 1]);
    }
    
    int get(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right or q_right < left) {
            return 0;
        }
        if (q_left <= left and right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get(node*2, left, mid, q_left, q_right);
        int right_node = get(node*2 + 1, mid + 1, right, q_left, q_right);
        return max(left_node, right_node);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int MAXN = 1e5;
        tree.resize(MAXN*4, 0);
        int n = startTime.size();
        using tp = tuple<int, int, int>;
        map<int, int> compress;
        vector<tp> events;
        
        for (int i = 0; i < n; ++i) {
            int s = startTime[i];
            int e = endTime[i];
            int w = profit[i];
            compress[s] = 0;
            compress[e] = 0;
            events.push_back({s, e, w});
        }
        
        int next_day = 0;
        
        for (const auto &[time, day] : compress) {
            compress[time] = ++next_day;
        }
        
        sort(events.begin(), events.end(), [&](tp a, tp b) {
             return get<1>(a) < get<1>(b);
        });
        
        for (int i = 0; i < n; ++i) {
            auto [s, e, w] = events[i];
            s = compress[s];
            e = compress[e];
            update(1, 1, MAXN, e, max({
                get(1, 1, MAXN, e, e),
                get(1, 1, MAXN, 1, s) + w
            }));
        }
        
        return get(1, 1, MAXN, 1, MAXN);
    }
};