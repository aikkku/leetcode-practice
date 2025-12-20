class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        bool a = 0;
        int temp = 1, ans = 1;

        for(int i = 1; i < arr.size(); i++) {
            if(temp == 1 and arr[i] != arr[i - 1]) {
                temp ++;
                a = arr[i] < arr[i - 1];
            }else if((!a and arr[i] < arr[i - 1]) or (a and arr[i] > arr[i - 1])) {
                temp ++;
                a = !a;
            } else {
                ans = max(temp, ans);
                temp = 1;
                if(arr[i] != arr[i - 1]) i--;
            }
            cout<<arr[i]<<' '<<temp<<endl;
        }
        cout<<endl;

        return max(ans, temp);
    }
};