#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> tree, heights;

    void update(int node, int left, int right, int index) {
        if (index < left || index > right) {
            return;
        }
        if (left == right) {
            tree[node] = index;
            return;
        }
        int mid = (left + right) / 2;
        update(node*2, left, mid, index);
        update(node*2 + 1, mid + 1, right, index);
        if (heights[tree[node*2]] < heights[tree[node*2 + 1]]) {
            tree[node] = tree[node*2];
        }
        else {
            tree[node] = tree[node*2 + 1];
        }
    }

    int get_index(int node, int left, int right, int q_left, int q_right) {
        if (q_left > right || left > q_right) {
            return -1;
        }
        if (q_left <= left && right <= q_right) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_node = get_index(node*2, left, mid, q_left, q_right);
        int right_node = get_index(node*2 + 1, mid + 1, right, q_left, q_right);
        if (left_node == -1) return right_node;
        if (right_node == -1) return left_node;
        return (heights[left_node] < heights[right_node]) ? left_node : right_node;
    }

    int calculateMaxArea(int left, int right) {
        if (left > right) {
            return 0;
        }
        int mid = get_index(1, 0, heights.size() - 1, left, right);
        int area = heights[mid] * (right - left + 1);
        int left_area = calculateMaxArea(left, mid - 1);
        int right_area = calculateMaxArea(mid + 1, right);
        return max(area, max(left_area, right_area));
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        heights.resize(m);
        tree.resize(4 * (m + 1));
        int max_area = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                heights[j] = (matrix[i][j] == '0') ? 0 : heights[j] + 1;
                update(1, 0, m - 1, j);
            }
            max_area = max(max_area, calculateMaxArea(0, m - 1));
        }

        heights.clear();
        tree.clear();

        return max_area;
    }
};