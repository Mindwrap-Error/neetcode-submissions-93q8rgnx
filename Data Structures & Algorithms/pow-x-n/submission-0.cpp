class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;

        if(n < 0)
        {
            return myPow(1/x, -n);
        }


        while(n > 0)
        {
            if(n & 1)
            {
                res *= x;
                x *= x;
            }
            else
            {
                x *= x;
            }
            n /= 2;
        }

        return res;
    }
};

/*
2 raised to 5

*/
