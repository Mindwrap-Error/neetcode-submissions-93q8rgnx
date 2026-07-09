class Solution {
public:
    string largestGoodInteger(string num) {
       int prev = num[0];
       int count = 1;

       vector<int> arr(10, 0);
       for(int i = 1; i < num.size(); i++)
       {
        if(num[i] == prev)
        {
            count++;
            prev = num[i];
        }
        else
        {
            count = 1;
            prev = num[i];
        }

        if(count == 3)
        {
            arr[num[i] - '0'] = 1;   
        }
       }

       for(int i = 9; i >= 0; i--)
       {
        if(arr[i] == 1)
        {
            return string(3, '0' + i);
        }
       }

       return "";
    }
};