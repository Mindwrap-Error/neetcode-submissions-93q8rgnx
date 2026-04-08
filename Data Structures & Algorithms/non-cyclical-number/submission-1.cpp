class Solution {
public:
    int sumSq(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = (n % 10);
            sum += (digit * digit);
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        set<int> seen;
        if(n == 1)
        {
            return true;
        }

        seen.insert(n);
        
        while(true)
        {
            n = sumSq(n);
            if(n == 1) return true;
            else if(seen.find(n) != seen.end()) return false;
            else seen.insert(n);
        }

        return false;
    }
};
