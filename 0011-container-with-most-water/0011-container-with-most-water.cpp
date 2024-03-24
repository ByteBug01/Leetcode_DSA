class Solution {
public:
    int maxArea(vector<int>& height) {
//         int start = 0;
//         int end = height.size()-1;
//         int area;
//         int maxarea = 0;

//         while(start<end)
//         {
//             area = min(height[start], height[end])*(end-start);
//             if(area>maxarea)
//             maxarea = area;

//             if(min(height[start],height[end])== height[start])
//             start++;
//             else
//             end--;
//         }
//         return maxarea;
        
        int n = height.size();
        
        int i = 0;
        int j = n-1;
        
        int maxwater = 0 ;
        
        while(i<j){
            int w = j - i;
            
            int h = min(height[i], height[j]);
            
            int area = h * w;
            
            maxwater = max(maxwater, area);
            
            if(height[i] < height[j]) { i++; }
            else { j-- ; }
            
        }
        
        return maxwater;
    }
};