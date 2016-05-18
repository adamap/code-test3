//Given a non-empty array of integers, return the k most frequent elements.

//For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2]. 

//Note: 

//You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
//Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


struct comparator_top
{
    bool operator()(unordered_map<int, int>::iterator i1, unordered_map<int, int>::iterator it2)
    {
        return (i1->second < it2->second);
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int>hash_map;
        for (int i = 0; i < nums.size(); i++)
        {
            hash_map[nums[i]]++;
        }
 
        priority_queue<unordered_map<int, int>::iterator, vector<unordered_map<int, int>::iterator>, comparator_top >q;
        unordered_map<int, int>::iterator it;
        for (it = hash_map.begin(); it != hash_map.end(); it++)
        {
            q.push(it);
        }
        vector<int>result;
        while (!q.empty() && k > 0)
        {
            it = q.top();
            q.pop();
            result.push_back(it->first);
            k--;
        }
        return result;    
    }
};
