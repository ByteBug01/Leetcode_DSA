class Solution {
public:
//bruteforce----------------
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        int target_time = times[targetFriend][0]; //remember this 2d idx concept

        sort(times.begin(), times.end());

        vector<int> chairs(n, -1);

        for(auto & v: times){
            int a = v[0];
            int d = v[1];

            for(int i = 0; i<n; i++){
                if(chairs[i] <= a){
                    chairs[i] = d;

                    if(a == target_time) return i;
                    
                    break;
                }
            }
            
        }

return -1;
    }
};