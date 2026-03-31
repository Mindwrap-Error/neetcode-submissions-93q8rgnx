class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; i++)
        {
            if(n % 2 == 1)
            {
                result += pow(2, 31 - i);
            }
            n /= 2;
        }
        return result;
    }
};
