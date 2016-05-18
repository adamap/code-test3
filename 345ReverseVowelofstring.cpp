//Write a function that takes a string as input and reverse only the vowels of a string.

//Example 1:
// Given s = "hello", return "holle". 

//Example 2:
// Given s = "leetcode", return "leotcede". 

class Solution {
public:
    string reverseVowels(string s) 
    {
        vector<int>pos;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u'
              || s[i] == 'A' || s[i] == 'O' || s[i] == 'E' || s[i] == 'I' || s[i] == 'U')
            {
                pos.push_back(i);
            }
        }
        int start = 0, end = (int)pos.size() - 1;
        while (start < end)
        {
            char temp = s[pos[start]];
            s[pos[start]] = s[pos[end]];
            s[pos[end]] = temp;
            start++;
            end--;
        }
        return s;
        
    }
};
