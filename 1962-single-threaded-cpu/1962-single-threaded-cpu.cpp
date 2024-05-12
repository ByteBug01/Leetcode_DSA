// typedef pair<int, int> P;

// // struct  beta{
// //    operator()(P& p1, P&p2){
// //        return p1 > p2;
// //    }
// // };

// class Solution {
// public:

//     vector<int> getOrder(vector<vector<int>>& tasks) {
//         int n = tasks.size();

//         // sort(tasks.begin(), tasks.end());

//         vector<array<int, 3>> arr_tasks;

//         for(int i =0; i<n; i++){
//             int curr_time = tasks[i][0];
//             int process_time = tasks[i][1];

//             arr_tasks.push_back({curr_time, process_time, i});
//         }

//         sort(arr_tasks.begin(), arr_tasks.end());

//         priority_queue<P, vector<P>, greater<>> pq; //min_heap
//         vector<int> ans;

//         // for(int i = 0; i<n; i++){
//         //     pq.push({task[i][1], i});
//         // }

//         //   sort(tasks.begin(), tasks.end());

//         long long curr_time = 0;
//         int  i = 0;

//            //imp while loop
//          while( i<n  || !pq.empty() ){
           
//             if(pq.empty() && curr_time <= arr_tasks[i][0]){
//                 curr_time = arr_tasks[i][0];
//             }

//              while(i<n && arr_tasks[i][0] <= curr_time){
//                   pq.push({arr_tasks[i][0], arr_tasks[i][2]});
//                   i++;
//              }

//              P curr_task = pq.top();
//              pq.top();

//              curr_time += curr_task.first;

//              ans.push_back(curr_task.second);

//          }

//          return ans;
//     }
// };


class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        vector<array<int, 3>> sortedTasks;
        
        for(int i = 0; i<n; i++) {
            int start_time = tasks[i][0];
            int processing_time = tasks[i][1];
            
            sortedTasks.push_back({start_time, processing_time, i});
        }
        
        sort(begin(sortedTasks), end(sortedTasks)); //O(nlogn)

        //------------------
        vector<int> result;
        
        long long curr_time = 0;
                  int idx   = 0;
        
        //------------------

        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<> > pq; //min_heap
        
        //imp while loop
        while(idx < n || !pq.empty()) {
            
            if(pq.empty() && curr_time < sortedTasks[idx][0]) {
                curr_time = sortedTasks[idx][0];
            }
            
            
            while(idx < n && sortedTasks[idx][0] <= curr_time) {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]}); //log(n)
                idx++;
            }
            
            pair<int, int> curr_task = pq.top();
            pq.pop();
            
            curr_time += curr_task.first; //processing time
            result.push_back(curr_task.second);
        }
      
        return result;
    }
};


