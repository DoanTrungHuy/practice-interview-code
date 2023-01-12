class SegmentTree {
private:
    vector<int> tree;

public:
    SegmentTree(int maxVal) {
        tree.resize(4 * maxVal);
    }
        
    void update(int node, int left, int right, int index) {
        if (!(left <= index and index <= right)) {
            return;   
        }
        if (left == right) {
            tree[node]++;
            return;
        }
        int mid = (left + right) >> 1;
        update(node * 2, left, mid, index);
        update(node * 2 + 1, mid + 1, right, index);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
        
    int sumRange(int node, int left, int right, int qleft, int qright) {
        if (right < qleft or qright < left) {
            return 0;
        }
        if (qleft <= left and right <= qright) {
            return tree[node];   
        }
        int mid = (left + right) >> 1;
        int sumLeft = sumRange(node * 2, left, mid, qleft, qright);
        int sumRight = sumRange(node * 2 + 1, mid + 1, right, qleft, qright);
        return sumLeft + sumRight;  
    }   
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int maxVal = *max_element(instructions.begin(), instructions.end());
        SegmentTree it(maxVal);
        int ans = 0;
        const int mod = 1e9 + 7;
        for (int num : instructions) {
            int less = it.sumRange(1, 1, maxVal, 1, num - 1);
            int greater = it.sumRange(1, 1, maxVal, num + 1, maxVal);
            ans = (ans + min(less, greater)) % mod;
            it.update(1, 1, maxVal, num);
        }
        return ans;
    }
};