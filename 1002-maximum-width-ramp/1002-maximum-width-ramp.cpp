
// 70/101 TC passed------------

// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> leftmin(n), rightmax(n);
//         stack<int> st;

//         st.push(0);
//         leftmin[0] = 0;

//         for (int i = 1; i < n; i++) {
//             while (!st.empty() && nums[st.top()] > nums[i]) {
//                 st.pop();
//             }
//             leftmin[i] = (st.empty()) ? i : st.top();
//             if (st.empty() || nums[st.top()] > nums[i]) {
//                 st.push(i);
//             }
//         }

//         while (!st.empty()) st.pop();
        
//         st.push(n - 1);
//         rightmax[n - 1] = n - 1;

//         for (int i = n - 2; i >= 0; i--) {
//             while (!st.empty() && nums[st.top()] < nums[i]) {
//                 st.pop();
//             }
//             rightmax[i] = (st.empty()) ? i : st.top();
//             if (st.empty() || nums[st.top()] < nums[i]) {
//                 st.push(i);
//             }
//         }

//         int maxi = 0;

//         for (int i = 0; i < n; i++) {
//             if (rightmax[i] >= leftmin[i]) {
//                 maxi = max(maxi, rightmax[i] - leftmin[i]);
//             }
//         }

//         return maxi;
//     }
// };


class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmin(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        int maxWidth = 0;

        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - st.top());
                st.pop();
            }
        }

        return maxWidth;
    }
};

