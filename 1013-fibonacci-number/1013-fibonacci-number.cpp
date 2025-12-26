class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1;
        if(n == 1) return b;
        if(n == 0) return a;

        for(int i = 1; i < n; i++) {
            int temp = b;
            b += a;
            a = temp;
        }

        return b;
    }
};