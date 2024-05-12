class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();

        priority_queue<int> pq;

        for(int i = 0; i<n; i++){
            pq.push(piles[i]);
        }

        for(int i = 0; i<k; i++){
            int x = pq.top();
            pq.pop();
        x -= x/2;
        pq.push(x);
        }

       int min_sum = 0;
        while(!pq.empty()){
          min_sum += pq.top();
          pq.pop();
        }

        return min_sum;
    }
};