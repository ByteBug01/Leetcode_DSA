class Solution {
public:
    int minimumPushes(string word) {
         int n = word.size();
    
    unordered_map<char,int> mp;

    for(int i = 0; i<n; i++){
        mp[word[i]]++;
    }

    vector<int> counts;

    for(auto& it: mp){
        counts.push_back(it.second);
    }

    sort(counts.rbegin(), counts.rend()); //desc order

    int presses = 1;
    int ans = 0;
    int keys = 1;

for(int i=0; i<counts.size(); i++){
    ans += counts[i] * presses;
    keys++;

    if(keys > 8){
        keys = 1;
        presses++;
    } 
}

    return ans;
    }
};