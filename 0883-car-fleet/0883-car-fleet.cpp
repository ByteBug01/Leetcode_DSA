class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n =  speed.size();
        vector<pair<int, double>> pos_time_array(n);

      
        // sort(pos_speed_array.begin(), pos_speed_array.end());

         vector<double> time(n);

        for(int i = 0; i<n; i++){
            time[i] = (target - position[i])/speed[i];
        }

          for(int i=0; i<n; i++){
          pos_time_array[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        sort(pos_time_array.begin(), pos_time_array.end());

        stack<int>st;

        for(int i = n-1; i>=0; i--){
            if(!st.empty() && pos_time_array[i].second <= pos_time_array[st.top()].second){
                continue;
            }else
               { st.push(i);}
            
        }

return st.size();
    }
};