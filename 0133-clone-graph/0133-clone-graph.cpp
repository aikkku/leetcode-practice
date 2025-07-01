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
    map<int, Node*> exists;
    Node* cloneGraph(Node* node) {
        Node* clone = new Node();
        if(!node) return node;
        clone->val = node->val;
        exists[clone->val] = clone;
        if(!node->neighbors.empty()) {
            for(Node* n : node->neighbors) {
                if(exists.find(n->val) == exists.end()) {
                    clone->neighbors.push_back(cloneGraph(n));
                } else{
                    clone->neighbors.push_back(exists[n->val]);
                }
            }
        }

        return clone;
    }
};
