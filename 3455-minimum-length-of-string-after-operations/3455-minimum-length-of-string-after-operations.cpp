// class Solution {
// public:
//     int minimumLength(string s) {
//         int n = s.length();

//         unordered_map<int, vector<int>> mp;

//         for(int i = 0; i<n; i++){
//             mp[s[i]].push_back(i);
//         }

// for(auto &it: mp){
//     vector<int> idxs = it.second;
//     int i  =0;
//     while(idxs.size() > 2){
//         idxs.erase(i+1);
//         i++;
//     }
// }

// string ans = "";

// for(auto &it: mp){
//     vector<int> idxs = it.second;
//     int i  =0;

//     while(i < idxs.size()){
//         ans[i] += it.first;
//         i++;
//     }
// }

// return ans;

//     }
// };

// class Solution {
// public:
//     int minimumLength(string s) {
//         int n = s.length();

//         // Step 1: Store the indices of each character
//         unordered_map<char, vector<int>> mp;
//         for(int i = 0; i < n; i++) {
//             mp[s[i]].push_back(i);
//         }

//         // Step 2: Remove pairs of indices until only the boundary indices or single indices remain
//         for(auto &it : mp) {
//             vector<int> &idxs = it.second;
//             int i = 0;
//             while(idxs.size() > 2) {
//                 idxs.erase(idxs.begin() + i + 1);
//                 idxs.pop_back();
//             }
//         }

//         // Step 3: Construct the final string from the remaining indices
//         string ans = s;
//         for(auto &it : mp) {
//             vector<int> &idxs = it.second;
//             int size = idxs.size();
//             if(size > 2) {
//                 ans = ans.substr(idxs[1] + 1, idxs[size - 2] - idxs[1] - 1);
//             }
//         }

//         // Return the length of the final string
//         return ans.length();
//     }
// };

//----------------why you are constructing a new string and finding its size, instead count the size in the map itself

class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int cnt=0;
        map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            if(mpp[s[i]]>2){
                cnt=cnt+2;
                mpp[s[i]]=mpp[s[i]]-2;
            }
        }
        int ans=n-cnt;
        return ans;
    }
};