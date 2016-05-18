//Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

//For example,

//MovingAverage m = new MovingAverage(3);
//m.next(1) = 1
//m.next(10) = (1 + 10) / 2
//m.next(3) = (1 + 10 + 3) / 3
//m.next(5) = (10 + 3 + 5) / 3

class MovingAverage 
{
    queue<int>q;
    int win_size;
    int sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) 
    {
       win_size = size;
       sum = 0;
       q = queue<int>();
    }
    
    double next(int val) 
    {
        if( win_size == 0)
        {
            return 0.0f;
        }
        if( q.size() == win_size)
        {
            int t = q.front();
            q.pop();
            sum -= t;
            q.push(val);
            sum += val;
        }
        else
        {
            q.push(val);
            sum += val;
        }
        
        return (double)sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
