// class Solution {
// public:
// //---------------incorrect code ---(many errors)-----------------------------
//     vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
//         int n = positions.size();

//         vector<pair<int, int>> pp;

//         for(int i = 0; i<n; i++){
//             pp.push_back({positions[i], i});
//         }

//         sort(pp.begin(), pp.end());

//         stack<int> st;

//         for(int i= 0; i<n; i++){
//             if(st.empty()){
//               st.push(pp[i].second);
//             }
//             if((directions[st.top()] == 'R' && directions[pp[i].second] == 'L') || (directions[st.top()] == 'L' && directions[pp[i].second] == 'R')){
//                  if(healths[st.top()] > healths[pp[i].second]){
//                     i++;
//                     healths.erase(healths.begin() + i);
//                     healths[st.top()] -= 1;
//                  }else if(healths[st.top()] < healths[pp[i].second]){
//                      healths.erase(healths.begin() + st.top());
//                       st.pop();
//                      healths[pp[i].second] -= 1;
//                  }else{ //equal
//                      healths.erase(healths.begin() + i);
//                      healths.erase(healths.begin() + st.top());
//                      st.pop();
//                      i++;
//                  }
//             }
//             st.push(pp[i].second);
//         }

//         return healths;
//     }
// };

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, int>> pp;
        
        for(int i = 0; i < n; i++) {
            pp.push_back({positions[i], i});
        }

        sort(pp.begin(), pp.end());

        stack<int> st;

        for(int i = 0; i < n; i++) {
            int idx = pp[i].second;

            while (!st.empty() && directions[st.top()] == 'R' && directions[idx] == 'L') {
                int topIdx = st.top();
                if (healths[topIdx] > healths[idx]) {
                    healths[topIdx]--;
                    healths[idx] = 0;
                    break;
                } else if (healths[topIdx] < healths[idx]) {
                    healths[idx]--;
                    healths[topIdx] = 0;
                    st.pop();
                } else {
                    healths[idx] = 0;
                    healths[topIdx] = 0;
                    st.pop();
                    break;
                }
            }

           
            if (healths[idx] > 0) {
                st.push(idx);
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};