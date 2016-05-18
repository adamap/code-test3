//Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome. 

//Example 1:
// Given words = ["bat", "tab", "cat"]
// Return [[0, 1], [1, 0]]
// The palindromes are ["battab", "tabbat"]


//Example 2:
// Given words = ["abcd", "dcba", "lls", "s", "sssll"]
// Return [[0, 1], [1, 0], [3, 2], [2, 4]]
// The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
//
int ispalindrome_str(string s)
{
	if (s.length() == 0)
	{
		return 1;
	}

	int start = 0, end = s.length() - 1;

	while (start < end)
	{
		if (s[start] == s[end])
		{
			start++;
			end--;
		}
		else
		{
			return 0;
		}
	}

	return 1;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        vector<vector<int>> result;
	    if (0 == words.size())
	    {
		    return result;
	    }

	    unordered_map<string, int>hash_map;

	    for (int i = 0; i < words.size(); i++)
	    {
		    hash_map[words[i]] = i;
	    }

	    for (int i = 0; i < words.size(); i++)
	    {
		    string str_cur = words[i];

		    if (str_cur.length() == 0)
		    {
			    continue;
		    }
		    int start = 0, end = 0;
		
		    while (end < str_cur.length())
		    {
			    string str1 = str_cur.substr(start, end-start);
			    string str2 = str_cur.substr(end);

			    reverse(str1.begin(), str1.end());
			    if (str1 == str_cur)
			    {
				    end++;
				    continue;
			    }
			    if (1 == ispalindrome_str(str2) && hash_map.find(str1) != hash_map.end())
			    {
				    vector<int> t;
				    t.push_back(i);
				    t.push_back(hash_map[str1]);
				    result.push_back(t);
			    }
			    end++;
		    }

		    while (end == str_cur.length() && start <= end)
		    {
			    string str1 = str_cur.substr(start, end - start);
			    string str2 = str_cur.substr(0, start);

			    reverse(str1.begin(), str1.end());
			    if (str1 == str_cur)
			    {
				    start++;
				    continue;
			    }
			    if (1 == ispalindrome_str(str2) && hash_map.find(str1) != hash_map.end())
			    {
				    vector<int> t;
				    t.push_back(hash_map[str1]);
				    t.push_back(i);
				    result.push_back(t);
			    }
			    start++;
		    }
	    }

	    return result;
    }
};
