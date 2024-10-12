class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        priority_queue<int, vector<int>, greater<int>> pq;

        sort(intervals.begin(), intervals.end());

        for(int i= 0; i<n; i++){
            int s = intervals[i][0];
            int e = intervals[i][1];

         if(!pq.empty()&& pq.top() < s){
            pq.pop();
         }

         pq.push(e);
            
        }

        return pq.size();
    }
};