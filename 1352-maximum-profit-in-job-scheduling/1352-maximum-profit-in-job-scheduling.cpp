// class Solution {
// public:
//     int rec( int idx , vector<vector<int>>&jobs , vector<int>&startTime , vector<int>&dp)
//     {
//         if( idx >= startTime.size())
//         {
//             return 0;
//         }
//         if(dp[idx] != -1)
//         {
//             return dp[idx];
//         }
//         int nextIndex = lower_bound(startTime.begin() , startTime.end() , jobs[idx][1])-startTime.begin();

//         int take = jobs[idx][2] + rec( nextIndex , jobs , startTime , dp);

//         int notTake = rec( idx + 1 , jobs , startTime , dp);

//         return dp[idx] = max( take , notTake);
//     }
    
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//           vector<vector<int>>jobs;
         
//          int n = startTime.size();

//          vector<int>dp( n , -1);

//          for( int i = 0 ; i < startTime.size() ; i++)
//          {
//              jobs.push_back({ startTime[i] , endTime[i] , profit[i]});
//          }

//          sort(jobs.begin() , jobs.end());

//          sort(startTime.begin() , startTime.end());

//          return rec( 0 , jobs , startTime , dp);
//     }
// };

// class Solution {
// public:
// int n ;
// int dp[50001]; //as only the idx is changing
// int getIdx(vector<vector<int>>& arr, int l, int currJobEnd){
//     int r = n-1;

//     int ansIdx = n+1;

//     while(l<=r){
//        int  mid = l + (r-l)/2;

//         if(arr[mid][0] >= currJobEnd){
//             ansIdx = mid;
//            r = mid - 1;
//         }else{
//             l = mid +1;
//         }
//     }
//     return ansIdx;
// }

// int solve(vector<vector<int>>& arr, int i){
//     if(i >= n) return 0;

// if(dp[i] != -1){
//     return dp[i];
// }
//    int nextidx = getIdx(arr, i+1, arr[i][1]);

//     int take = arr[i][2] + solve(arr, nextidx);

//     int not_take = solve(arr, i+1 );
    
//     return dp[i] = max(take, not_take);
// }

//  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//     n =  profit.size();

//     memset(dp, -1, sizeof(dp));
    
//     vector<vector<int>> arr(n, vector<int>(3, 0));

//     for(int i = 0; i<n; i++){
//        arr[i][0] = startTime[i];
//        arr[i][1] = endTime[i];
//        arr[i][2] = profit[i];
//     }

//     sort(arr.begin(), arr.end());

//     return solve(arr, 0);

//  }
// };


class Solution{
public:

int getNextIndex(vector<vector<int>>& arr, int l, int currJobEnd){
    int low = l;
    int n = arr.size();
    int high =  n-1;

    int nextIdx = -1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid][0] >= currJobEnd) {
            nextIdx =  mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return nextIdx;
}


int solve( vector<vector<int>>& arr, int n, int i,  vector<int>& dp){
      if(i >= n) return 0;

      if(dp[i] != -1) return dp[i];


      int nextIndex = getNextIndex(arr, i+1, arr[i][1]);

      int take = arr[i][2] + (nextIndex == -1 ? 0 : solve(arr, n, nextIndex, dp)) ;

      int not_take = solve(arr, n, i+1, dp);

      return dp[i] = max(take, not_take);
}


int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> arr(n, vector<int>(3, 0));


        for(int i=0; i<n; i++){
           arr[i][0] = startTime[i];
           arr[i][1] = endTime[i];
           arr[i][2] = profit[i];
        }

        //sort camparator

        // auto comp = [&](auto & vec1, auto & vec2 ){
        //     return vec1[0] <= vec2[0];
        // };


        sort(arr.begin(), arr.end());

        vector<int> dp(n, -1);

        return solve(arr, n, 0, dp);

}
};
