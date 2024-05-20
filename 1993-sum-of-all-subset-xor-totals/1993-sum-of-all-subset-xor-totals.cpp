class Solution {
public:

//find all the subsets using recursion fun: allSubsets
// then find subsetXOR sum uisng fun: xorsum

int n;
vector<vector<int>> subsets;
int sum;

void xorsum(vector<vector<int>>& ans){
   sum = 0;

   for(auto & num : ans){
    int subsetxor = 0;
    for(auto & it: num){
        subsetxor ^= it;
    }

    sum += subsetxor;
   }
}

void allSubsets(vector<int>& nums, int i, vector<int> & tmp){
if( i>= n){
    subsets.push_back(tmp);
    return;
}

tmp.push_back(nums[i]); //take curr element
allSubsets(nums, i+1, tmp);
tmp.pop_back(); //skip curr element
allSubsets(nums, i+1, tmp);

}
    int subsetXORSum(vector<int>& nums) {
         n  =nums.size();

         vector<int> tmp;
         
          allSubsets(nums, 0, tmp);

          xorsum( subsets);

         return sum;   
    }
};