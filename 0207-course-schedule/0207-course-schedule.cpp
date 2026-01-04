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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++) {
            Node* temp = new Node();
            temp->val = i;
            v.push_back(temp);
        }

        for(const vector<int>& p : prerequisites) {
            v[p[0]]->ns.push_back(v[p[1]]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i)) return false;
            visited.insert(i);
            path.erase(i);
        }

        return true;
    }

    bool dfs(int i) {
        if(path.count(i)) return false;
        if(visited.count(i)) return true;
        Node* temp = v[i];
        path.insert(i);

        for(int i = 0; i < temp->ns.size(); i++) {
            if(!dfs(temp->ns[i]->val)) return false;
        }

        visited.insert(i);
        path.erase(i);

        return true;
    }
};
