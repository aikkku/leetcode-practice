class Solution {
    struct Node{
        int val;
        vector<Node*> ns;
        Node() {}
    };
public:
    vector<Node*> v;
    unordered_set<int> path;
    unordered_set<int> visited;
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++) {
            Node* temp = new Node();
            temp->val = i;
            v.push_back(temp);
        }

        for(const vector<int>& p : prerequisites) {
            v[p[1]]->ns.push_back(v[p[0]]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i)) return {};
        }

        
        reverse(ans.begin(), ans.end());

        return ans;
    }

    bool dfs(int i) {
        if(path.count(i)) return false;
        if(visited.count(i)) return true;

        path.insert(i);
        Node* temp = v[i];

        for (Node* nxt : temp->ns) {
            if (!dfs(nxt->val)) return false;
        }

        visited.insert(i);
        path.erase(i);
        ans.push_back(i);
        return true;
    }
};
