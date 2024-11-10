// class Solution {
// public:
    
//     // revisit it
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
//         int  i = 0;
//         vector<vector<int>> result;
        
//         int n  = intervals.size();
        
//         while(i<n){
//             if(intervals[i][1] < newInterval[0]){
//                 result.push_back(intervals[i]);
//             }else if(intervals[i][0] > newInterval[1]){
//                 break;
//             }else{
//                 newInterval[0] =  min(newInterval[0], intervals[i][0]);
//                 newInterval[1] =  max(newInterval[1], intervals[i][1]);
//             }
            
//             i++;
//         }
        
//         result.push_back(newInterval);
//         while(i<n){
//             result.push_back(intervals[i]);
//             i++;
//         }
        
//         return result;
//     }
// };


class Solution {
public:
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

       int n =  intervals.size();
       vector<vector<int>> ans;

       int i =  0;

       while(i < n && intervals[i][1] < newInterval[0]){
           ans.push_back(intervals[i]);
           i++;
       }

    //vector<int> overlapInterval(2);
       while(i  < n && intervals[i][0] <= newInterval[1]){
           newInterval[0] = min(intervals[i][0] , newInterval[0]);
           newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
       }

           ans.push_back(newInterval);

           while(i < n){
            ans.push_back(intervals[i]);
            i++;
           }


           return ans;

    }
}; 