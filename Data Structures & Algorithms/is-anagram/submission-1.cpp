class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }

        int arr[26] = {0};
        for(char characters: s)
        {
            arr[characters - 97]++;
        }
        for(char characters: t)
        {
            if(arr[characters-97] == 0)
            {
                return false;
            }
            arr[characters-97]--;
        }

        for(int x: arr)
        {
            if(x != 0)
            {
                return false;
            }

        }
        return true;
    }
};
