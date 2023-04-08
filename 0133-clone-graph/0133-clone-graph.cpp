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
private:
    unordered_map<Node *, Node *> hash;
    
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        Node *newNode = new Node(node->val);
        hash[node] = newNode;
        for (Node *neighbor : node->neighbors) {
            if (hash.find(neighbor) != hash.end()) {
                newNode->neighbors.push_back(hash[neighbor]);
            }
            else {
                newNode->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return newNode;
    }
};