// class Solution {
// public:
//     void set(int i, vector<int> &nums, vector<int>v, vector<vector<int>> & ans){
//          if(i==nums.size())
//              return;
         
//          v.push_back(nums[i]);
//          ans.push_back(v);
//          for(int j=i+1; j<nums.size(); j++){
//              set(j,nums,v,ans);
//          }
//      }
    
    
    
    
    
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> v;
//         vector<vector<int>> ans;
//         ans.push_back(v);
//         for(int i=0; i<nums.size(); i++){
//             set(i,nums, v, ans);
//         }
//         return ans;
//     }
// };

//-------------------------------------------------
//Recursion

class Solution {
public:

vector<vector<int>> ans;
int n;
void solve(vector<int>& nums,int i, vector<int> &tmp){
    //base case
if( i>= n){
    ans.push_back(tmp);
    return;
}

tmp.push_back(nums[i]); //take curr element
solve(nums, i+1, tmp);
tmp.pop_back(); //skip curr element
solve(nums, i+1, tmp);

}
 vector<vector<int>> subsets(vector<int>& nums) {
    n = nums.size();

            vector<int> tmp;

            solve(nums, 0, tmp);

            return ans;
 }
};