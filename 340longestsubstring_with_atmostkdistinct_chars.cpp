//Given a string, find the length of the longest substring T that contains at most k distinct characters. 

//For example, Given s = ¡°eceba¡± and k = 2, 

//T is "ece" which its length is 3. 



class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        unordered_map<char, int>hash_map;
        int start = 0, end = 0, n = s.length();
        int maxlen = 0;
 
        while (end < n)
        {
            while (hash_map.size() <= k && end < n)
            {
                hash_map[s[end]]++;
                if (hash_map.size() > k)
                {
                    break;
                }
                end++;
            }
            maxlen = max(maxlen, end - start);
            
            while (hash_map.size() > k && start < n)
            {
                hash_map[s[start]]--;
                if (hash_map[s[start]] == 0)
                {
                    hash_map.erase(s[start]);
                }
                start++;
            }
            end++;
        }
        return maxlen;
    }
};
