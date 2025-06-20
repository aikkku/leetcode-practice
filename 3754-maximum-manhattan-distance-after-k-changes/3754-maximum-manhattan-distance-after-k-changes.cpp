class Solution {
public:
    int maxDistance(string st, int k) {
        int n = 0, w = 0, s = 0, e = 0;
        int maxs = 0;
        for(int i = 0; i < st.length(); i++) {
            if(st[i] == 'N') n++;
            else if(st[i] == 'W') w++;
            else if(st[i] == 'S') s++;
            else e++;
            int curr = abs(n - s) + abs(e-w);

            int cut = min(n, s) + min(w, e);
            curr+=2*min(cut, k);
            maxs = max(curr, maxs);
        }

        return maxs;
    }
};