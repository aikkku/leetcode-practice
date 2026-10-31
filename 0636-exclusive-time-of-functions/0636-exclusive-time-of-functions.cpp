class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> tracker(n);
        stack<pair<int, int>> st;

        int previousTime = 0;

        for (int i = 0; i < logs.size(); i++) {
            // id
            int idIterator = logs[i].find(":");
            cout << logs[i].substr(0, idIterator) << " ";
            int id = stoi(logs[i].substr(0, idIterator));
            logs[i][idIterator] = '#';

            // s/e
            cout << logs[i][idIterator + 1] << " ";
            bool start = logs[i][idIterator + 1] == 's';

            // timestamp
            int timeIterator = logs[i].find(":");
            cout << logs[i].substr(timeIterator + 1) << " ";
            int time = stoi(logs[i].substr(timeIterator + 1));

            // string manipulation is done

            if (start) {
                if (!st.empty())
                    tracker[st.top().first] += time - previousTime;
                previousTime = time;
                st.push({id, time});
            } else {
                if (!st.empty() && st.top().first == id) {
                    tracker[st.top().first] += time - previousTime + 1;
                    previousTime = time + 1;
                    st.pop();
                } else {
                    return {};
                }
            }
        }

        return tracker;
    }
};