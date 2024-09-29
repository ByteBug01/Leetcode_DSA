// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         int n = nums.size();
        
//         long long ans = 0;

//         for(int i =0; i<n; i++){
//             int maxi = nums[i], mini = nums[i];
//           for(int j = i; j<n; j++){
//               maxi = max(maxi, nums[j]);
//               mini = min(mini, nums[j]);

//               ans += (maxi - mini);
//           }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();
        long long totsum = 0;
     
     vector<int> nextgreater(n, n), prevgreater(n, -1);
     stack<int> st;

     for(int i=0; i<n;i++){
        while(!st.empty() && nums[st.top()] < nums[i]){
            nextgreater[st.top()] = i;
            st.pop();
        }
        st.push(i);
     }


     while(!st.empty()) st.pop(); //reuse

     for(int i=n-1; i>=0;i--){
        while(!st.empty() && nums[st.top()] <= nums[i]){
            prevgreater[st.top()] = i;
            st.pop();
        }
        st.push(i);
     }

     for(int i = 0; i<n; i++){
        totsum += (long long)(i - prevgreater[i])* (nextgreater[i] - i) * nums[i];
     }
     
     vector<int> nextsmaller(n, n), prevsmaller(n, -1);
  //   stack<int> st;
     while(!st.empty()) st.pop(); //reuse

     for(int i=0; i<n;i++){
        while(!st.empty() && nums[st.top()] > nums[i]){
            nextsmaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
     }


     while(!st.empty()) st.pop(); //reuse

     for(int i=n-1; i>=0;i--){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            prevsmaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
     }

     for(int i = 0; i<n; i++){
        totsum -= (long long)(i - prevsmaller[i])* (nextsmaller[i] - i) * nums[i];
     }


return totsum;
    }
};