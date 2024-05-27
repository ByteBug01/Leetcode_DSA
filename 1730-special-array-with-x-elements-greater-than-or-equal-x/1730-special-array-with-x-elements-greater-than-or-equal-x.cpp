class Solution {
public:
// approach 1: sort + binary search

int binarysearch(vector<int>& nums, int x){
    int i = 0;
    int j = nums.size() - 1;
int idx = nums.size();
    while(i<=j){
        int mid = (i+j)/2;

        if(nums[mid] >= x){
            idx = mid;
            j = mid - 1;
        }else{
            i = mid +1;
        }
    }

    return idx;
}


    int specialArray(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));
int i ;

for(int x =0; x<=n; x++){
    i = binarysearch(nums, x); // for idx of first element >= x

    int cnt = n -i;
    if(cnt == x){
        return x;
    }
}
   return -1;     
    }
};