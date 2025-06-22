class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        for(int i = 0; i < points.size(); i++) {
            pq.push(points[i]);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }

private:
    class Compare {
    public:
        bool operator()(vector<int> a, vector<int> b)
        {
            long long d1 = (pow(a[0],2) + pow(a[1],2)), d2 =(pow(b[0],2) + pow(b[1],2));
            if (d1 < d2) {
                return true;
            }
            return false;
        }
    };
};