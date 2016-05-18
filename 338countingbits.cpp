//Given a non negative integer number num. For every numbers i in the range 0 ¡Ü i ¡Ü num calculate the number of 1's in their binary representation and return them as an array. 

//Example:
// For num = 5 you should return [0,1,1,2,1,2]. 

//Follow up: 
//It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
//Space complexity should be O(n).
//Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.




vector<int> countBits1(int num) 
{
    vector<int> result;
    result.push_back(0);
    
    for ( int i = 1; i <= num; i++)
    {
        int temp = i;
        int count = 0;
        while( temp > 0)
        {
            if ( temp &0x01 > 0)
            {
                count++;
            }
            temp>>=1;
        }
        result.push_back(count);
    }
    
    return result;
}

vector<int> countBits2(int num) 
{
    vector<int> result;
    result.push_back(0);
    for ( int i = 1; i <= num; i++)
    {
        int temp = i;
        int count = 0;
        
        for ( ; temp; count++)
        {
            temp = temp&(temp-1);
        }
        result.push_back(count);
    }

    return result;
}

vector<int> countBits3(int num) 
{
    vector<int> result(num+1, 0);
    
    for ( int i = 1; i <= num; i++)
    {
        if (i %2 == 0)
        {
            result[i] = result[i/2];
        }
        else
        {
            result[i] = result[i/2]+1;
        }
    }
    return result;
}

int BitCount4(unsigned int n) 
{ 
    n = (n &0x55555555) + ((n >>1) &0x55555555) ; 
    n = (n &0x33333333) + ((n >>2) &0x33333333) ; 
    n = (n &0x0f0f0f0f) + ((n >>4) &0x0f0f0f0f) ; 
    n = (n &0x00ff00ff) + ((n >>8) &0x00ff00ff) ; 
    n = (n &0x0000ffff) + ((n >>16) &0x0000ffff) ; 

    return n ; 
}

vector<int> countBits4(int num) 
{
    vector<int> result;
    for ( int i = 0; i <= num; i++)
    {
        result.push_back(BitCount4(i));
    }
    return result;
}

class Solution {
public:
    vector<int> countBits(int num) 
    {
        //return countBits1(num);
        //return countBits2(num);
        //return countBits3(num);
        return countBits4(num);
    }
};
