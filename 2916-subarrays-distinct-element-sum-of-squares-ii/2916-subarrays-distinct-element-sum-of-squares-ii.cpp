using ll = long long;
const ll MOD = 1e9 + 7;

class SegmentTree {
private:
    vector<ll> summ, lazy, sumq;
    
public:
    SegmentTree() {
        
    }
    
    SegmentTree(ll n) {
        summ.resize(4*n);
        sumq.resize(4*n);
        lazy.resize(4*n);
    }
    
    /*
        a*a + b*b (State transition) -> (a + x)*(a + x) + (b + x)*(b + x)
        <-> a*a + 2*a*x + x + b*b + 2*b*x + x
        <-> (a*a) + (b*b) + 2*x*(a + b) + 2*x
        <-> summ[node] = a + b = summ[node] + lazy[node]*(right - left + 1)
        <-> prev_sumq[node] = a*a + b*b = 0*0 + 0*0 = 0
        <-> sumq[node] = (a + x)*(a + x) + (b + x)*(b + x) 
                       = prev_sumq[node] + 2*lazy[node]*summ[node] + lazy[node]*lazy[node]*(right - left + 1)
    */
    
    void down(ll node, ll left, ll right) {
        if (left > right || lazy[node] == 0) {
            return;
        }
        
        (sumq[node] += 2*lazy[node]*summ[node] + lazy[node]*lazy[node]*(right - left + 1)) % MOD;
        (summ[node] += lazy[node]*(right - left + 1)) % MOD;
        if (left != right) {
            (lazy[node*2] += lazy[node]) %= MOD;
            (lazy[node*2 + 1] += lazy[node]) %= MOD;
        }
        lazy[node] = 0;
    }
    
    void update(ll node, ll left, ll right, ll q_left, ll q_right) {
        down(node, left, right);
        if (left > q_right || q_left > right) {
            return;
        }
        if (q_left <= left && right <= q_right) {
            lazy[node]++;
            down(node, left, right);
            return;
        }
        ll mid = (left + right) >> 1;
        update(node*2, left, mid, q_left, q_right);
        update(node*2 + 1, mid + 1, right, q_left, q_right);
        summ[node] = (summ[node*2] + summ[node*2 + 1]) % MOD;
        sumq[node] = (sumq[node*2] + sumq[node*2 + 1]) % MOD;
    }
    
    ll get_sumq(ll node, ll left, ll right, ll q_left, ll q_right) {
        down(node, left, right);
        if (left > q_right || q_left > right) {
            return 0;
        }
        if (q_left <= left && right <= q_right) {
            down(node, left, right);
            return sumq[node];
        }
        ll mid = (left + right) >> 1;
        ll left_node = get_sumq(node*2, left, mid, q_left, q_right);
        ll right_node = get_sumq(node*2 + 1, mid + 1, right, q_left, q_right);
        return left_node + right_node;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const ll n = nums.size();

        // 2 2 5 5
        // 1
        // 1 1
        // 2 2 1
        // 2 2 1 1
        
        SegmentTree st(n);
        unordered_map<ll, ll> last_idx;
        ll ans = 0;
        
        for (ll i = 0; i < n; ++i) {
            if (last_idx.count(nums[i])) {
                st.update(1, 0, n - 1, last_idx[nums[i]] + 1, i);
            }
            else {
                st.update(1, 0, n - 1, 0, i);
            }
            ans = (ans + st.get_sumq(1, 0, n - 1, 0, i)) % MOD;
            last_idx[nums[i]] = i;
        }

        return ans;
    }
};