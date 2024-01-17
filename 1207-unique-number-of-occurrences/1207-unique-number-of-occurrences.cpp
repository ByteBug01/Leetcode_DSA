class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n  = arr.size();
     
        unordered_map<int, int> m, m2;
        
        for(int a : arr){
            m[a]++;
        }
        
        for(auto it = m.begin(); it != m.end(); ++it){
            m2[it->second]++;
        }
        
        for(auto it = m2.begin(); it != m2.end(); ++it){
            if(it->second > 1){
                return false;
            }
        }
        
        return true;
    }
};