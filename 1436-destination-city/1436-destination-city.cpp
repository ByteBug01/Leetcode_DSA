class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        //brute force
//         int n = paths.size();
//         int m = paths[0].size();
        
//         int candidate  = 0;
//         bool goood = true;
        
//         for(int i =0 ; i<n ; i++){
//             candidate = paths[i][1];
//             for(int j=0; j<m; j++){
//                 if(paths[j][0] == candidate){
//                     good= false;
//                     if(good==true){
//                         return candidate;
//                     }
//                 }
//             }
//         }
        
        
        unordered_map<string, int> mp;
        
        for(auto path: paths){
            string source = path[0];
            mp[source] = 1;
        }
        
        for(auto path: paths){
            string dest = path[1];
            if(mp[dest]!=1){
                return dest;
            }
        }
    return "";
    }
};