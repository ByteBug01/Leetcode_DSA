class Solution {
public:

typedef pair<int, int> P;

int calSum( unordered_map<int, int> & frq, int x){
        priority_queue<P> pq;

        for(const auto & it: frq){
            pq.push({it.second, it.first});
        }

int sum =0;

for(int i=0; i<x && !pq.empty(); i++){
    auto top = pq.top();
    pq.pop();

    sum += top.second * top.first;
}

return sum;
}

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        unordered_map<int, int> frq;

        for(int i=0; i<k; i++){
             frq[nums[i]]++;
        }

       vector<int> ans;

       ans.push_back(calSum(frq, x));
        
     for(int i=1; i<= n-k; i++){
        frq[nums[i-1]]--;

        if( frq[nums[i-1]] == 0){
            frq.erase( nums[i-1]);
        }

        frq[nums[i+k -1]]++;

        ans.push_back(calSum(frq, x));
     }


return ans;
    }
};