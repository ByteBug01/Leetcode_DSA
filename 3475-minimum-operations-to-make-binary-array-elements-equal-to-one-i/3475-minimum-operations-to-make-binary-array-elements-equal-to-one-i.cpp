class Solution {
public:

//we iterate through array, whenever we encounter a 0, we flip the current element and the next two elements,
//After processing the array, we check if the last two elements are 1s. If they are not, 
//it means it's impossible to make all elements equal with the given operations, so we return -1
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        for(int i = 0; i<=n-3; i++){
            if(nums[i] == 0){
                for(int j  =0 ; j<3; j++){
                    nums[i+j] = 1 - nums[i +j];
                }
                   ans++;
            }
        }


        for(int i = n-2; i<n; i++){
            if(nums[i] == 0){
                return -1;
            }
        }

        return ans;
    }
};