using ll = long long;
int n;

class SegmentTree {
private:
    vector<ll> tree;
    
public:
    SegmentTree(int n) {
        tree.resize(4 * n);
    }
    
    void update(int index, ll value, int node = 1, int left = 0, int right = n - 1) {
        if (index < left or index > right) {
            return;
        }
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = (left + right) >> 1;
        update(index, value, node << 1, left, mid);
        update(index, value, node << 1 | 1, mid + 1, right);
        tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }
    
    int query(int qLeft, int qRight, ll target, int node = 1, int left = 0, int right = n - 1) {
        if (qLeft > right or qRight < left) {
            return -1;
        }
        if (tree[node] < target) {
            return -1;
        }
        if (left == right) {
            if (tree[node] < target) {
                return -1;
            }
            return left;
        }
        int mid = (left + right) >> 1;
        int lNode = query(qLeft, qRight, target, node << 1, left, mid);
        if (lNode != -1) {
            return lNode;
        }
        int rNode = query(qLeft, qRight, target, node << 1 | 1, mid + 1, right);
        return rNode;
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        n = nums.size();
        
        vector<ll> prefSum(n);
        prefSum[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        SegmentTree it(n);
        
        for (int i = 0; i < n; ++i) {
            it.update(i, prefSum[i]);
        }
        
        int ans = INT_MAX;
        ll s = 0;
        
        for (int j = 0; j < n; ++j) {
            int i = it.query(j, n - 1, s + k);
            
            if (i != -1) {
                ans = min(ans, i - j + 1);
            }
            
            s = prefSum[j];
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};