// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int>mp;
//         for(int i=0;i<s.length();i++){
//             mp[s[i]]++;
//         }
//         s="";
//         vector<pair<char,int>>vec(mp.begin(), mp.end());

//     sort(vec.begin(), vec.end(), [](const pair<char,int>& a, const pair<char, int>& b) {
//         return a.second > b.second;
//     });
//         for(auto i:vec){
            
//             if(i.second>1){
//                 int count=0;
//                 while(count<i.second){
//                     s+=i.first;
//                     count++;
//                 }
//             }
//             else
//             s+=i.first;
//         }
//         return s;
        
        //-------------------------------------------------
    //     int n = s.length();
        
    //     unordered_map<char, int> mp;
        
    //     for(int i = 0; i<n; i++){
    //         mp[s[i]]++;
    //     }
        
    //     string ans = "";
        
    //     vector<std::pair<char, int>> vec(mp.begin(), mp.end());


    //    sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
    //     return a.second > b.second; 
    // });

        
    //     for(auto it: vec){
    //         int i = it.second ;
    //         while(i--){
    //             ans += it.first;
    //         }
    //     }
        
    //     return ans;
        
    //}

// };

//-------------------------------------------------------------
//using prioity queue  O(nlong)

class Solution {
public:
    typedef pair<char, int> P;
    struct comp {
        bool operator()(P &p1, P &p2) {
            return p1.second<p2.second; //max-heap
        }
    };
    
    string frequencySort(string s) {
        priority_queue<P, vector<P>, comp> pq;
        
        unordered_map<char, int> mp;
        for(char &ch : s) {
            mp[ch]++;
        }
        
        for(auto &it : mp) {
            pq.push({it.first, it.second});
        }
        
        string result = "";
        
        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            
            result += string(temp.second, temp.first);
        }
        return result;
    }
};