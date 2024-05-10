
class Solution {
public:
// problem has k "smallest" fractn to find , so we can apply "maximum"" prioriy queue

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
         priority_queue<vector<double>> pq;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i+1; j < arr.size(); j++) {

                double div = (double) arr[i] / arr[j];
                pq.push(vector<double>{div, (double)arr[i], (double)arr[j]});//vector bna k dalna h

                if(pq.size() > k)
                    pq.pop();
            }
        }

        auto v  = pq.top();
        vector<int> ans(2);
        ans[0] = v[1];
        ans[1] = v[2];

        return ans;
    }
};