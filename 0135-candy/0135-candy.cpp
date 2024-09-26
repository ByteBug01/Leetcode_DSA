class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> ans(n, 1);

        for(int l = 1; l<n; l++){
            if(ratings[l-1] < ratings[l] ){
                ans[l] = ans[l-1]+1;
            }
        }


        for(int r = n-2; r>=0; r--){  //think on it....
            if(ratings[r] > ratings[r+1]){
               ans[r] = max(ans[r] , ans[r+1] + 1);
            }
        }

int sum =0;
        for(int i =0; i<n; i++){
            sum += ans[i];
        }


        return sum;
    }
};