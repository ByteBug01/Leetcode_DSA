typedef unsigned long long ll;

class Solution {
public:
    vector<int> nseL(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> nseR(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = nseL(arr, n); 
        vector<int> NSR = nseR(arr, n); 

        ll sum = 0;
        int M = 1e9+7;

        for(int i = 0; i < n; i++) {
            ll d1 = i - NSL[i]; 
            ll d2 = NSR[i] - i; 

            ll total_ways_for_i_min = d1 * d2;
            ll sum_i_in_total_ways  = arr[i] * total_ways_for_i_min;

            sum = (sum + sum_i_in_total_ways) % M;
        }

        return sum;
    }
};
