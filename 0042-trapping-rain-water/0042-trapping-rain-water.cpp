class Solution {
public:
    
    //normal array and logic based
    
//     vector<int> getLeftMax(vector<int> & height, int & n){
        
//         vector<int> left(n);
        
//         left[0] = height[0];
        
//         for(int i = 1; i<n; i++){
//             left[i] = max(left[i-1], height[i]); //don't mistake
//         }
        
//         return left;
//     }
    
//     vector<int> getRightMax(vector<int> & height, int & n){
        
//         vector<int> right(n);
        
//     right[n-1] = height[n-1];
        
//         for(int i = n-2; i>=0; i--){
//             right[i] = max(right[i+1], height[i]); // don't mistake
//         }
        
//         return right;
//     }
    
//     int trap(vector<int>& height) {
//         int n = height.size();
        
//         vector<int> leftMax = getLeftMax(height, n);
//         vector<int> rightMax = getRightMax(height, n);
        
//         int sum = 0 ;
        
//         for(int i = 0; i<n; i++){
            
//             int h = min(leftMax[i], rightMax[i]) - height[i];
            
//             sum += h;
//         }
        
//         return sum;
//     }
    
    
    // 2 pointer approach
     int trap(vector<int>& height){
         int i = 0; int j =  height.size()-1;
         
         int ans = 0;
         
        int leftmax = 0; int rightmax = 0;
         
         while(i<=j){
             leftmax = max(leftmax, height[i]);
             rightmax = max(rightmax, height[j]);
             
             if(leftmax < rightmax){
                 ans += (leftmax - height[i]);
                 i++;
             }
             
             else{
                 ans += (rightmax - height[j]);
                 j--;
             }
         }
         
         return ans;
     }
    
};