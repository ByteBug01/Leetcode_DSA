// class Solution {
// public:
// //failed----------------------------------
//     double averageWaitingTime(vector<vector<int>>& customers) {
//         int n = customers.size();

//         int wtime = customers[0][0] + customers[0][1];
//         int sum = wtime - customers[0][0];

//         for(int i = 1; i<n; i++){
//             int arrival = customers[i][0];
//             int time = customers[i][1];

//             if(wtime >= arrival){
//                 sum += (wtime + time) - arrival;
//                 wtime = wtime + time;
//             }else{
//                 sum += (wtime+1) - arrival;
//             }
//         }

//         double avg = (sum)/n;

//         return avg;
//     }
// };

///---------------------------------------------------

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        int currTime = 0;
        long long totTime = 0;

        for(int i =0; i<n; i++){
            int arrival = customers[i][0];
             int time = customers[i][1];

             if(currTime < arrival){
                currTime = arrival;
             }

             currTime +=  time;
             totTime += currTime - arrival;
        }

        return (double) totTime/ n;
    }
};