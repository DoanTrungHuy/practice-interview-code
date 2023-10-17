class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> has_node;
        for (int child : leftChild) {
            if (child != -1) {
                has_node.insert(child);
            }
        }
        
        for (int child : rightChild) {
            if (child != -1) {
                has_node.insert(child);
            }
        }
        
        if (has_node.size() == n) {
            return false;
        }
        
        int root = 0;
        for (int i = 0; i < n; ++i) {
            if (!has_node.count(i)) {
                root = i;
                break;
            }
        }
        
        queue<int> mq;
        unordered_set<int> visited;
        mq.push(root);
        visited.insert(root);
        
        while (!mq.empty()) {
            int node = mq.front();
            mq.pop();
            
            int left_node = leftChild[node];
            int right_node = rightChild[node];
            
            if (left_node != -1 and visited.count(left_node)) {
                return false;
            }
            
            if (right_node != -1 and visited.count(right_node)) {
                return false;
            }
            
            if (left_node != -1) {
                mq.push(left_node);
                visited.insert(left_node);
            }
            if (right_node != -1) {
                mq.push(right_node);
                visited.insert(right_node);
            }
        }
        
        return visited.size() == n;
    }
};