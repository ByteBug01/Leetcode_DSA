class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int> pq;

        for(auto it: nums){
            pq.push(it);
        }

        long long sum = 0;

        while(k--){
            int x = pq.top();
            cout<<x<<endl;
            sum += x;
            pq.pop();

            // pq.push(ceil(x/3));  //this will not work as x/3 will be come as int so do (x+2/3) to get ceil val
            pq.push((x+2)/3);
        }

        return sum;
    }
};