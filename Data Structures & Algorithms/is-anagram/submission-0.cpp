class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> frequency;
        for(char character: s)
        {
            frequency.insert(character);
        }
        for(char character: t)
        {
            auto i = frequency.find(character);
            if(i != frequency.end())
            {
                frequency.erase(i);
            }
            else
            {
                return false;
            }
        }
        if(frequency.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
