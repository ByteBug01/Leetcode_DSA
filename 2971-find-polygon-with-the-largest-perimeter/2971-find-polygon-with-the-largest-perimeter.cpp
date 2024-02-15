class Solution {
public:
    
//     bool isValidPolygon(const std::vector<int>& sides, int k) {
//     int sum = 0;
//     for (int i = 0; i < k - 1; ++i) {
//         sum += sides[i];
//     }
//     return sum > sides[k - 1];
// }

    
    long long largestPerimeter(vector<int>& nums) {
        
//         sort(nums.rbegin(), nums.rend()); 

//     int n = nums.size();

//     for (int i = 0; i < n - 2; ++i) {
//         for (int j = i + 1; j < n - 1; ++j) {
//             for (int k = j + 1; k < n; ++k) {
//                 if (nums[i] < nums[j] + nums[k]) {
//                     // Found a valid combination, return the perimeter
//                     int perimeter = nums[i] + nums[j] + nums[k];
                    
//                     // Check if adding more sides increases the perimeter
//                     for (int l = k + 1; l < n; ++l) {
//                         if (perimeter + nums[l] > 2 * nums[l]) {
//                             perimeter += nums[l];
//                         } else {
//                             break;
//                         }
//                     }

//                     return perimeter;
//                 }
//             }
//         }
//     }

//     // No valid combination found
//     return -1;
        
        
//         sort(nums.rbegin(), nums.rend()); 

//     int n = nums.size();

//     for (int i = 0; i < n - 2; ++i) {
//         int sum = nums[i];
//         for (int j = i + 1; j < n; ++j) {
//             sum += nums[j];
//             if (sum >  nums[j+1]) {
               
//                 return sum;
//             }
//         }
//     }

    
//     return -1;
        
//         sort(nums.rbegin(), nums.rend()); // Sort in descending order

//     int n = nums.size();
        
//         int k = 3;
        
//         for(int i=0; i<n; i++){
            
            
        

//     for (int i = 0; i <= n - k; ++i) {
//         std::vector<int> selectedSides(nums.begin() + i, nums.begin() + i + k);
//         if (isValidPolygon(selectedSides, k)) {
//             // Print or process the selected sides
//            int sum = 0;
//             for (int side : selectedSides) {
//                 sum += side;
//             }
           
//             return sum;
//         }
//     }
            
//          k+=i;   
//         }
//    return -1;
        
     //...........................................................................// 
        // Correct Solution during contest
        
//         sort(nums.begin(), nums.end());
        
//         long long n = nums.size();
        
//         vector<long long> arr(n);
//         arr[0] = nums[0];
        
//         for(long long i=1; i<n; i++){
//             arr[i] = arr[i-1]+nums[i];
//         }
        
        
//         for(long long i = n-1; i>=2; i--){
//             if(nums[i]< arr[i-1]){
//                 return arr[i];
//             }
//         }
//         return -1;
        
        //.......................................................//
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        long long perimeter = 0;
        long long remainingsum = 0;
        
        for(int i = 0 ; i<n; i++){
            if(nums[i] < remainingsum){
                perimeter =  remainingsum + nums[i];
            }
            
            remainingsum += nums[i];
        }
        
        
        return perimeter == 0?-1: perimeter;
    }
};