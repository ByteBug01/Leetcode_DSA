class Solution {
public:
//easily with recursion

void solve(int curr, int n, vector<int>& ans){
    if(curr > n) return;

    ans.push_back(curr);

    for(int j = 0; j<=9; j++){
        int x = curr*10 + j;

        if(x> n) return;

        solve(x, n, ans);
    }

}


    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for(int i = 1; i<=9; i++){
            solve(i, n, ans);
        }


        return ans;
    }
};