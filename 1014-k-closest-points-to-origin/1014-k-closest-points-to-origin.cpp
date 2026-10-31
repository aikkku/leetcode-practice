class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct {
            bool operator()(const vector<int> c1, const vector<int> c2) const {
                return sqrt(pow(c1[0], 2) + pow(c1[1], 2)) >
                       sqrt(pow(c2[0], 2) + pow(c2[1], 2));
            }
        } coordinatesCompare;

        priority_queue pq(points.begin(), points.end(), coordinatesCompare);

        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};