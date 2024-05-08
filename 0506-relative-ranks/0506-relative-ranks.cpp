class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // we can solve it by sorting the copied score, creating the vector of strings medals, then mapping it with sorted sccore
        // but i will solve it by priority queue

        int n = score.size();

        priority_queue<pair<int, int>> heap;

        for(int i = 0; i<n; i++){
            heap.push({score[i], i});
        }


        vector<string> ans(n);
        int rank = 1; //heap is sorted with the topmost value at the top, there rank = 1 will lead to max score[i]
        while(!heap.empty()){
            int origidx = heap.top().second;
            heap.pop();

            if(rank == 1){
                ans[origidx] = "Gold Medal";
            }else if(rank == 2){
                ans[origidx] = "Silver Medal";
            }else if(rank == 3){
                ans[origidx] = "Bronze Medal";
            }else{
                ans[origidx] = to_string(rank);
            }
            rank++;
        }

        return ans;
    }
};