// #include <bits/stdc++.h>
// using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        // 1: Count the frequency of each integer
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        // 2: Sort the integers based on their frequencies
        vector<pair<int, int>> freq;
        for(auto it : mp) {
            freq.push_back({it.first, it.second});
        }
        sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        // Step 3: Iterate through sorted frequencies and remove elements until k elements                        have been removed
        int removed = 0;
        for(auto& f : freq) {
            if(k >= f.second) {
                k -= f.second;
                removed++;
            } else {
                break;
            }
        }

        // Step 4: Return the no. of unique integers remaining after removals
        return freq.size() - removed;
    }
};
