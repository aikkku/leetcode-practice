class Solution {
    struct Node {
        unordered_map<Node*, double> ns;
        string val;

        Node() {}
    };
public:
    unordered_map<string, Node*> nodes;
    set<string> visited;

    vector<double> ans;

    bool dfs(Node* src, string dst, double d) {
        if (src->val == dst) {
            ans.push_back(d);
            return true;
        }
        if (visited.count(src->val)) return false;

        visited.insert(src->val);
        for(auto& [node, value] : src->ns) {
            double temp_d = d * value;
            if(dfs(node, dst, temp_d)) return true;
        }
        visited.erase(src->val);
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); i++) {
            Node *a, *b;
            if(nodes.find(equations[i][0]) != nodes.end()) {
                a = nodes[equations[i][0]];
            } else {
                a = new Node();
                a->val = equations[i][0];
                nodes[equations[i][0]] = a;
            }

            if(nodes.find(equations[i][1]) != nodes.end()) {
                b = nodes[equations[i][1]];
            } else {
                b = new Node();
                b->val = equations[i][1];
                nodes[equations[i][1]] = b;
            }

            a->ns[b] = values[i];
            b->ns[a] = 1.0/values[i];
        }

        for(const vector<string>& q : queries) {
            if(nodes.count(q[0]) and nodes.count(q[1])) {
                if(!dfs(nodes[q[0]], q[1], 1)) ans.push_back(-1);
                visited.clear();
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};