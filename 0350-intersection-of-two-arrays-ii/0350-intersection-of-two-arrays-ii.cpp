// class Solution {
// public:

// int n1, n2;

//bakwaas try not working---------------------
// void isIntersect(vector<int>& nums1, vector<int>& nums2, vector<int>&temp, vector<int>& ans){
//     int nn = temp.size();

//     vector<int> v = (n1>n2)?nums1:nums2;
//     int t =  v.size();

//     int i = 0;
//     int j = 0;

//     while(i < nn && j  < t){
//         if(v[i] == temp[j]){
//             i++;
//             j++;
//             ans.push_back(temp[j]);
//         }
//         i++;
//         ans.clear();
//     }

//     // return ans;
// }

  //  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //not working;
//          n1 =  nums1.size();
//          n2 = nums2.size();

//           vector<int> nums = (n1>n2)?nums2:nums1;
//   vector<int> tempans;
//         for(int i = 0; i<(n2>n1)?n1:n2 ; i++){
//             for(int j = 0; j<i; j++){
//             vector<int> temp = vector<int>(nums.begin() + i, nums.begin() + j + 1);
            
//          isIntersect(nums1, nums2, temp, tempans);
//         }
//         }

//         return tempans;
//             }
// };

class Solution {
public:
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> result;
        int i = 0, j = 0;
        
        // Use two pointers to find intersections
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        
        return result;
}
};