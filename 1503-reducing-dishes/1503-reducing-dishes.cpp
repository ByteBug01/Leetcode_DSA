class Solution {
public:

//similar to 0-1 knapsack
//recursion + memo
int n;
int t[501][501];

int solve(vector<int>& satisfaction, int i , int time){
    if(i >= n){
        return 0;
    }

if(t[i][time] != -1){
    return t[i][time];
}
    int include = time*satisfaction[i] + solve(satisfaction, i+1, time+1);
    int exclude =  solve(satisfaction, i+1, time);

    return t[i][time] = max(include, exclude);
}




    int maxSatisfaction(vector<int>& satisfaction) {
          n = satisfaction.size();
memset(t, -1, sizeof(t));
        
        sort(satisfaction.begin(), satisfaction.end());

        return solve(satisfaction, 0, 1);
    }
};