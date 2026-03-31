class KthLargest {
public:
    priority_queue<int> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
       for(int i = 0; i < nums.size(); i++)
       {
        pq.push(nums[i]);
       } 
    }
    
    int add(int val) {
        pq.push(val);

        priority_queue<int> temp(pq);

        for(int i = 0; i < K - 1; i++)
        {
            temp.pop();
        }

        return temp.top();
    }
};
