using ll = long long;

struct SegmentTree {
    unordered_map<ll, ll> tree_sum, tree_max;
    
    SegmentTree() {
        
    }
    
    void update_sum(ll node, ll left, ll right, ll index, ll value) {
        if (index < left || index > right) {
            return;
        }
        if (left == right) {
            tree_sum[node] = value;
            return;
        }
        ll mid = (left + right) >> 1;
        update_sum(node*2, left, mid, index, value);
        update_sum(node*2 + 1, mid + 1, right, index, value);
        tree_sum[node] = tree_sum[node*2] + tree_sum[node*2 + 1];
    }
    
    void update_max(ll node, ll left, ll right, ll index, ll value) {
        if (index < left || index > right) {
            return;
        }
        if (left == right) {
            tree_max[node] = value;
            return;
        }
        ll mid = (left + right) >> 1;
        update_max(node*2, left, mid, index, value);
        update_max(node*2 + 1, mid + 1, right, index, value);
        tree_max[node] = max(tree_max[node*2], tree_max[node*2 + 1]);
    }
    
    ll get_max(ll node, ll left, ll right, ll q_left, ll q_right) {
        if (q_left > right || q_right < left) {
            return 0;
        }
        if (q_left <= left && right <= q_right) {
            return tree_max[node];
        }
        ll mid = (left + right) >> 1;
        ll left_node = get_max(node*2, left, mid, q_left, q_right);
        ll right_node = get_max(node*2 + 1, mid + 1, right, q_left, q_right);
        return max(left_node, right_node);
    }
    
    ll get_sum(ll node, ll left, ll right, ll q_left, ll q_right) {
        if (q_left > right || q_right < left) {
            return 0;
        }
        if (q_left <= left && right <= q_right) {
            return tree_sum[node];
        }
        ll mid = (left + right) >> 1;
        ll left_node = get_sum(node*2, left, mid, q_left, q_right);
        ll right_node = get_sum(node*2 + 1, mid + 1, right, q_left, q_right);
        return left_node + right_node;
    }
};

class BookMyShow {
private:
    SegmentTree st;
    ll n, m;
    ll j;
    
public:
    BookMyShow(ll n, ll m) {
        this->n = n;
        this->m = m;
        this->j = 0;
        
        for (ll i = 0; i < n; ++i) {
            st.update_max(1, 0, n - 1, i, m);
            st.update_sum(1, 0, n - 1, i, m);
        }
    }
    
    vector<ll> gather(ll k, ll maxRow) {
        ll left = 0, right = n - 1;
        ll index = n;
        
        while (left <= right) {
            ll mid = (left + right) >> 1;
            if (st.get_max(1, 0, n - 1, 0, mid) >= k) {
                index = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        if (index > maxRow) {
            return {};
        }
        
        ll curr = st.get_max(1, 0, n - 1, index, index);
        
        st.update_max(1, 0, n - 1, index, curr - k);
        st.update_sum(1, 0, n - 1, index, curr - k);
        
        return {index, m - curr};
    }
    
    bool scatter(ll k, ll maxRow) {
        ll cnt_seat = st.get_sum(1, 0, n - 1, 0, maxRow);
        
        if (cnt_seat < k) {
            return false;
        }
        
        while (j < n && k) {
            ll curr = st.get_sum(1, 0, n - 1, j, j);
            ll cnt_can_seat = min(curr, k);
            
            st.update_sum(1, 0, n - 1, j, curr - cnt_can_seat);
            st.update_max(1, 0, n - 1, j, curr - cnt_can_seat);
            
            k -= cnt_can_seat;
            
            if (curr - cnt_can_seat == 0) {
                j++;
            }
        }
        
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<ll> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */