// class Solution {
// public:
//     int solve(int num1, int num2){
        
//         int longest = 0;
//     for (int i = sizeof(int) * 8 - 1; i >= 0; i--) { // Assuming 32-bit integers
//         int bit1 = (num1 >> i) & 1;
//         int bit2 = (num2 >> i) & 1;
//         if (bit1 == bit2)
//             longest++;
//         else
//             break;
//     }
//     return longest;
        
//     }
    
    
    // string findCommon(string a, string b) {
    //     string common = "";
    //     int i = 0;
    //     while (i < min(a.length(), b.length()) && a[i] == b[i]) {
    //         common += a[i];
    //         i++;
    //     }
    //     return common;
    // }
    
    // int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         int n1 = arr1.size();
//         int n2 = arr2.size();
        
//         int x; 
//         int maxpre = 0;
//         for(int i =0; i<n1; i++){
//             for(int j = 0; j<n2; j++){
                
//                 x = solve(arr1[i], arr2[j]);
//                 maxpre = max(maxpre, x);
//             }
//         }
        
//         return maxpre;
        
        
        
//         string commonPrefix = "";
        
        
//         int minLength = min(arr1.size(), arr2.size());
        
        
//         for (int i = 0; i < minLength; i++) {
//             if (arr1[i] != arr2[i]) {
                
//                 break;
//             }
            
//             commonPrefix += to_string(arr1[i]);
//         }
       
        
//         return commonPrefix.size();
        
//          int minimum = 0;
//         for (int x : arr1) {
//             for (int y : arr2) {
//                 string c = findCommon(to_string(x), to_string(y));
//                 minimum = max(minimum, (int)c.length());
//             }
//         }
//         return minimum;
        
    
        
//     }
// };


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for(auto &num: arr1) {
            int temp = num;
            while(temp > 0) {
                st.insert(temp);
                temp /= 10; 
            }
        }

        int ans = 0;

        for(auto &num: arr2) {
            int temp = num;
            while(temp > 0 && !st.count(temp)) {
                temp /= 10;
            }
            if(temp > 0) {
                ans = max(ans, (int)log10(temp) + 1);
            }
        }

        return ans;
    }
};


 //log10(num) + 1 is for to calculate the no. of digits