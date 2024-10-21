// class Solution {
// public:
//     int maxUniqueSplit(string s) {
//         unordered_map<string, int> mp;
//         int n = s.length();

        // int j  =0;
        // for(int i=0; i<n; i++){
        //     string tmp = s.substr(i, j);
        //         if(mp.find(tmp) == mp.end()){
        //             mp[tmp]++;
        //         }else{
        //             j++;
        //         }
            
        // }

        // for(int i  =0; i<n; i++){
        //     for(int j =0; j<n; j++){
        //         string tmp = s.substr(i,j);
        //         if(mp.find(tmp) == mp.end()){
        //             mp[tmp]++;
        //         }
        //     }
        // }

//      int ans= 0;
//        for(int i =0; i<n; i++){
//         for(int j=1; j<=n-i; j++){
//             string tmp = s.substr(i, j);

//             if(mp.find(tmp) == mp.end()){
//                 mp[tmp] = 1;
//                 ans++;
//             }
//         }
//        }

//         return ans;
//     }
// };


class Solution 
{
public:

 int backtrack(const string& s, unordered_set<string>& seen, int start) {
        if (start == s.length()) return 0;
        
        int maxSplits = 0;
        for (int end = start + 1; end <= s.length(); ++end) {
            string substring = s.substr(start, end - start);
            
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxSplits = max(maxSplits, 1 + backtrack(s, seen, end));
                seen.erase(substring);  
            }
        }
        return maxSplits;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s, seen, 0);
    }

};

