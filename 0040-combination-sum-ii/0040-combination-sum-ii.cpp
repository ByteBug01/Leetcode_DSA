class Solution {
public:

void solve(vector<pair<int, int>>& frqList , int target, int start, vector<int>&path, vector<vector<int>>& ans){
    if(target == 0) {
        ans.push_back(path);
        return;
    }

    if(target < 0) return;

    for(int i = start; i< frqList.size(); i++){
       pair<int, int>& entry = frqList[i];

       int candidate = entry.first;
       int & freq = entry.second;

       if(freq <= 0) continue;

       path.push_back(candidate);
       freq--;
       solve(frqList, target-candidate, i, path, ans);
       freq++;
        path.pop_back();
    }
}


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        // sort(candidates.begin(), candidates.end());

        map<int, int> frq;

        for(int & cand: candidates){
            if(frq.find(cand) != frq.end()){
                frq[cand] += 1;
            }else
            frq[cand] = 1;
        }

        vector<pair<int, int>> frqList(frq.begin(), frq.end());

        solve( frqList, target, 0, path, ans);

        return ans;
    }
};