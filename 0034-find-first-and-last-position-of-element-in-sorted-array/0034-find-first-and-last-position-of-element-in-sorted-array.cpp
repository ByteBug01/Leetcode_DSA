class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
//      bool flag=false;

//       vector<int> ans;
//       long long n= a.size();
//         for(int i=0; i<n; i++){
//             if(a[i]==t)
//             ans.push_back(i);
//             flag = true;
//             break;
//         }
//         for(int j=n-1; j>=0; j--){
//             if(a[j]==t)
//             ans.push_back(j);
//             flag = true;
//             break;
//         }
//         if(flag)
//         return ans;
//          else
//         return {-1,-1};
        
          vector<int> ans = {-1, -1}; // Initialize the result vector with default values.

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == t) {
                ans[0] = i; // Update the first occurrence.
                break; // Exit the loop after finding the first occurrence.
            }
        }

        for (int j = a.size() - 1; j >= 0; j--) {
            if (a[j] == t) {
                ans[1] = j; // Update the last occurrence.
                break; // Exit the loop after finding the last occurrence.
            }
        }

        return ans;
    }
};