class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int> pq; //max heap

        for(int i = 0; i<n; i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
          int y = pq.top();
          pq.pop();
          int x = pq.top();
          pq.pop();

            int z = abs(y - x);
            pq.push(z);
    
        }

int ans = pq.top();
return ans;

    }
};