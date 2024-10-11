// class Solution {
// public:
// //bruteforce----------------
//     int smallestChair(vector<vector<int>>& times, int targetFriend) {
//         int n = times.size();

//         int target_time = times[targetFriend][0]; //remember this 2d idx concept

//         sort(times.begin(), times.end());

//         vector<int> chairs(n, -1);

//         for(auto & v: times){
//             int a = v[0];
//             int d = v[1];

//             for(int i = 0; i<n; i++){
//                 if(chairs[i] <= a){
//                     chairs[i] = d;

//                     if(a == target_time) return i;
                    
//                     break;
//                 }
//             }
            
//         }
// return -1;
//     }
// };

class Solution {
public:

typedef pair<int, int> P;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n  = times.size();

        priority_queue<P, vector<P>, greater<P>> occup;
        priority_queue<int, vector<int>, greater<int>> free;

        int chair  = 0;

        int targetar = times[targetFriend][0];

        sort(times.begin(), times.end());

        for(int i = 0; i<n; i++){
            int a = times[i][0];
            int d = times[i][1];

            while(!occup.empty() && occup.top().first <= a){
                free.push(occup.top().second);
                    occup.pop();
                
            }


            if(free.empty()){
                occup.push({d, chair});

                if(a == targetar)
                    return chair;
                
                    chair++;
                
            }
            else{
                int leastavail = free.top();
                free.pop();

                if(a == targetar){
                    return leastavail;
                }

                occup.push({d, leastavail});
            }
        }

return -1;
    }
};