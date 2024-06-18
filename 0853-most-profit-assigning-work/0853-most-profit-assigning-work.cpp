// class Solution {
// public:
//     int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//          int n = profit.size();
//         vector<pair<int, int>> pd(n);

//         for(int i = 0; i < n; i++) {
//             pd[i] = {difficulty[i], profit[i]};
//         }

//         sort(pd.begin(), pd.end());

//         vector<int> maxProfit(n);
//         maxProfit[0] = pd[0].second;

//         for(int i = 1; i < n; i++) {
//             maxProfit[i] = max(maxProfit[i-1], pd[i].second);
//         }

//         sort(worker.begin(), worker.end());

//         int ans = 0;
//         int j = 0;

//         for(int i = 0; i < worker.size(); i++) {
//             while(j < n && worker[i] >= pd[j].first) {
//                 j++;
//             }
//             if(j > 0) {
//                 ans += maxProfit[j-1];
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
      int n = profit.size();
      int m  =worker.size();

      priority_queue<pair<int, int>> pd;

      for(int i =0; i<n; i++){
        pd.push({ profit[i], difficulty[i]});
      }

      sort(worker.begin(), worker.end(), greater<int>()); //desc order

      int ans = 0;
      int i = 0;

      while(i < m && !pd.empty()){
        if(pd.top().second > worker[i]){
            pd.pop();
        }else{
            ans += pd.top().first;
            i++;
        }
      }
return ans;

    }
};