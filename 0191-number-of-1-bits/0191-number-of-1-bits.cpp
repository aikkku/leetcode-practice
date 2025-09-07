class Solution {
public:
    int hammingWeight(uint32_t x) {
        int mask1, mask2, mask4, mask8, mask16;

    // 0x55555555 = 0101... pattern
    mask1 = 0x55 | (0x55 << 8);
    mask1 = mask1 | (mask1 << 16);

    // 0x33333333 = 0011... pattern
    mask2 = 0x33 | (0x33 << 8);
    mask2 = mask2 | (mask2 << 16);

    // 0x0f0f0f0f = 00001111... pattern
    mask4 = 0x0f | (0x0f << 8);
    mask4 = mask4 | (mask4 << 16);

    // 0x00ff00ff = byte-level mask
    mask8 = 0xff | (0xff << 16);

    // 0x0000ffff = halfword mask
    mask16 = 0xff | (0xff << 8);

    // Stage 1: sum in pairs of bits
    x = (x & mask1) + ((x >> 1) & mask1);

    // Stage 2: sum in nibbles
    x = (x & mask2) + ((x >> 2) & mask2);

    // Stage 3: sum in bytes
    x = (x & mask4) + ((x >> 4) & mask4);

    // Stage 4: sum in 16-bit halves
    x = (x & mask8) + ((x >> 8) & mask8);

    // Stage 5: sum across full 32 bits
    x = (x & mask16) + ((x >> 16) & mask16);

    return x;
    }
};
