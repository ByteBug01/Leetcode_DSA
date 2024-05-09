class Solution {
public:
int n;
int solve(string & s, int curr_idx, int prev_val,  vector<vector<int>> &t){
if(curr_idx >= n){
    return 0;
}

//memo
if(t[curr_idx][prev_val] != -1){
return t[curr_idx][prev_val];
}


int flip = INT_MAX;
int no_flip =  INT_MAX;

    if(s[curr_idx] == '0'){
       if(prev_val == 1){
           flip = 1 + solve(s, curr_idx + 1, 1 , t);
          
       }else{ // prev_val == '0'
            flip = 1 + solve(s, curr_idx + 1, 1, t);
            no_flip = solve(s, curr_idx+1, 0, t);
       }


    }else if(s[curr_idx] == '1'){
         if(prev_val == 1){
            no_flip = solve(s, curr_idx+1, 1, t);
       }else{ // prev_val == '0'
            flip = 1 + solve(s, curr_idx + 1, 0, t);
            no_flip = solve(s, curr_idx+1, 1, t);
       }
    }

    return t[curr_idx][prev_val] = min(flip, no_flip);
}

    int minFlipsMonoIncr(string s) {
        n = s.size();
        //memo
        vector<vector<int>> t(n+1, vector<int>(2, -1));
        return solve(s, 0, 0, t);
    }
};