class Solution {
public:
    int minOperations(vector<int>& nums)
    {
       int n = nums.size();
        
        //sort
        // uniqueness
        
        set<int> st(begin(nums), end(nums));
        
        vector<int> temp(begin(st), end(st));
        
        int result = INT_MAX;
        
        for(int i = 0; i<temp.size(); i++){
            int l = temp[i];
            int r = l+n-1;
            
            //r-l = n-1
            
            int j = upper_bound(begin(temp), end(temp), r)- begin(temp);
            
            int within_range = j-i;
            int out_of_range = n-within_range;
        
            result=min(result, out_of_range );
        }
        return result;
    }
};