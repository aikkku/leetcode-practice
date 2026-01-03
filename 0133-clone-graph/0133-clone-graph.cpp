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
    unordered_map<int, Node*> exists;
    Node* cloneGraph(Node* node) {
        Node* ans = new Node();
        if(!node) return node;

        ans->val = node->val;
        exists[ans->val] = ans;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();

            for(int i = 0; i < cur->neighbors.size(); i++) {
                if(exists.count(cur->neighbors[i]->val) == 0){
                    Node* temp = new Node(cur->neighbors[i]->val);
                    exists[cur->neighbors[i]->val] = temp;
                    q.push(cur->neighbors[i]);
                }

                exists[cur->val]->neighbors.push_back(exists[cur->neighbors[i]->val]);
            }
        }

        return ans;
    }
};
