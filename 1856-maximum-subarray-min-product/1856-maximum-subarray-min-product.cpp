using ll = long long;
const int mod = 1e9 + 7;

class SegmentTree {
private:
    vector<int> tree, nums;
    
public:
    SegmentTree(int n, vector<int> nums) {
        tree.resize(4 * n, INT_MAX);
        this->nums = nums;
        build(1, 0, n - 1);
    }
    
    void build(int id, int left, int right) {
        if (left == right) {
            tree[id] = left;
            return;
        }
        
        int mid = (left + right) / 2;
        build(id * 2, left, mid);
        build(id * 2 + 1, mid + 1, right);
        tree[id] = nums[tree[id * 2 + 1]] < nums[tree[id * 2]] ? tree[id * 2 + 1] : tree[id * 2];
    }
    
    int getMin(int id, int left, int right, int qLeft, int qRight) {
        if (qRight < left or right < qLeft) {
            return INT_MAX;
        }
        
        if (qLeft <= left and right <= qRight) {
            return tree[id];
        }
        
        int mid = (left + right) / 2;
        int l = getMin(id * 2, left, mid, qLeft, qRight);
        int r = getMin(id * 2 + 1, mid + 1, right, qLeft, qRight);
        if (l == INT_MAX) {
            return r;
        }
        else if (r == INT_MAX) {
            return l;
        }
        return nums[l] < nums[r] ? l : r;
    }
};

class Solution {
private:
    vector<ll> prefSum;
    vector<int> nums;
    int n;
    ll ans;
    
public:
    void discardMin(SegmentTree &it, int l, int r) {
        if (l > r) {
            return;
        }
        
        int idxMin = it.getMin(1, 0, n - 1, l, r);
        ll getSum = !l ? prefSum[r] : prefSum[r] - prefSum[l - 1];
        
        ans = max(ans, (1LL * nums[idxMin] * getSum));
        
        discardMin(it, l, idxMin - 1);
        discardMin(it, idxMin + 1, r);
    }
    
    int maxSumMinProduct(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        
        SegmentTree it(n, nums);
        prefSum.resize(n);
        prefSum[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        ans = 0;
        discardMin(it, 0, n - 1);
        
        return (int)(ans % mod);
    }
};