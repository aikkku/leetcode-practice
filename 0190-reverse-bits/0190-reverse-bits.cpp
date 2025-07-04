class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        ans += (n&1);
        n>>=1;
        int count = 0;
        while(n > 0){
            ans<<=1;
            ans += (n&1);
            // cout<<(n&1)<<' ';
            count++;
            n>>=1;
        }
// std::bitset<32> x(ans);
// std::cout << x << '\n';
        if(count < 31){
            count=31 - count;
            while(count--) ans<<=1;
        }
        
        
        return ans;
    }
};
