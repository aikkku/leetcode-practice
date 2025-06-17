class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX = 200005;
    vector<long long> fact, inv_fact;

    void init_factorials() {
        fact.resize(MAX);
        inv_fact.resize(MAX);
        fact[0] = inv_fact[0] = 1;
        for(int i = 1; i < MAX; ++i) {
            fact[i] = fact[i-1]*i%MOD;
        }
        inv_fact[MAX-1] = mod_pow(fact[MAX-1], MOD-2, MOD);
        for(int i = MAX - 2; i >= 1; --i)
            inv_fact[i] = inv_fact[i+1]*(i+1)%MOD;
    }

    int c(int n, int r) {
        if(r < 0 or r > n) return 0;
        return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
    }

    long long mod_pow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) { 
            if(exp % 2) result = result * base % mod;
            base = base * base % mod;
            exp /= 2;
        }

        return result;
    }
    
    int countGoodArrays(int n, int m, int k) {
        init_factorials();
        long long res = c(n - 1, k);
        res = res * mod_pow(m - 1, n - 1 - k, MOD) % MOD;
        res = res * m % MOD;
        return res;
    }
};