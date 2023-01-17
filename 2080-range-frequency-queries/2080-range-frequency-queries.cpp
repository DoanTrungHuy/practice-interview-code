class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> um;

public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < (int)arr.size(); ++i) {
            um[arr[i]].push_back(i);
        }
    }
    
    int lb(vector<int> &v, int target) {
        int n = v.size();
        int l = 0, r = n - 1;
        int res = n;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (v[m] < target) {
                l = m + 1;
            }
            else {
                res = m;
                r = m - 1;
            }
        }
        return res;
    }

    int ub(vector<int> &v, int target) {
        int n = v.size();
        int l = 0, r = n - 1;
        int res = n;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (v[m] <= target) {
                l = m + 1;
            }
            else {
                res = m;
                r = m - 1;
            }
        }
        return res;
    }
    
    int query(int left, int right, int value) {
        vector<int> &v = um[value];
        int idx1 = ub(v, right), idx2 = lb(v, left);
        return idx1 - idx2;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */