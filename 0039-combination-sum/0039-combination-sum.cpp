class Solution {
public:

//bactrack--------------------------------------------------------
void solve(vector<int>& candidates, int target, int start, vector<int>&path, vector<vector<int>>& ans){
    if(target == 0) {
        ans.push_back(path);
        return;
    }

    if(target < 0) return;

    for(int i = start; i< candidates.size(); i++){
        path.push_back(candidates[i]);

        solve(candidates, target - candidates[i], i, path, ans);

        path.pop_back();
    }
}



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0, path, ans);

        return ans;
    }
};