/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        unordered_map<Node*, Node*> hash;
        queue<Node *> mq;
        mq.push(node);
        hash[node] = new Node(node->val);
        
        while (!mq.empty()) {
            Node *curr = mq.front();
            mq.pop();
            for (Node * neighbor : curr->neighbors) {
                if (!hash.count(neighbor)) {
                    hash[neighbor] = new Node(neighbor->val);
                    mq.push(neighbor);
                }
                hash[curr]->neighbors.push_back(hash[neighbor]);
            }
        }
        
        return hash[node];
    }
};