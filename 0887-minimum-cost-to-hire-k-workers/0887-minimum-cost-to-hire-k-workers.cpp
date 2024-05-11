class Solution {
public:
    // double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
    //     int n = quality.size();

    //     double result = DBL_MAX; 
    //     for(int manager = 0; manager < n; manager++) {
            
    //         double managerRatio = (double)min_wage[manager]/quality[manager];

    //         vector<double> group;
    //         for(int worker = 0; worker < n; worker++) {
    //             double worker_wage = quality[worker] * managerRatio;
    //             if(worker_wage >= min_wage[worker]) {
    //                 group.push_back(worker_wage);
    //             }
    //         }

    //         if(group.size() < k)
    //             continue;
            
    //         priority_queue<double, vector<double>> pq; //way to represent vector
    //         double sum = 0;

    //         for(double &wage : group) {
    //             sum += wage;
    //             pq.push(wage);

    //             if(pq.size() > k) {
    //                 sum -= pq.top();
    //                 pq.pop();
    //             }
    //         }

    //         result = min(result, sum);

    //     }

    //     return result;
    // }

    //-----------------------------------------------------------

  
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        double sum=0, result=INT_MAX;
        vector<pair<double,int>> details;
        for(int i=0;i<n;i++){
            details.push_back({wage[i]/(double)quality[i],quality[i]});
        }
        sort(details.begin(), details.end());
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(details[i].second);
            sum+=details[i].second;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                result=min(result,sum*details[i].first);
            }
        }
    return result;
    }
};
