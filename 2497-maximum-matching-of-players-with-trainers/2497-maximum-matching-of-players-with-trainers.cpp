class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());

        int pi = 0, ti = 0, pn = p.size(), tn = t.size(), ans = 0;
        while(pi < pn and ti < tn) {
            if(p[pi] <= t[ti]) {
                pi++;
            }

            ti++;
        }

        return pi;

    }
};