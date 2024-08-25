class Solution {
public:

    bool areAlmostEqual(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);

        int n = s1.length(), m = s2.length();
        int maxLen = max(n, m);

        // make the lengths of 2 strings equal by adding zeros to the front

        while(n != maxLen){
            s1 = "0" + s1; n++;
        }
        while(m != maxLen){
            s2 = "0" + s2; m++;
        }

        int diff = 0;

        unordered_map<char,int> mp1, mp2;
        for(int i = 0; i < n; i++){
            diff += (s1[i] != s2[i]);
            mp1[s1[i]]++; mp2[s2[i]]++;
        }
        return diff <= 2 && mp1 == mp2;

    }

    int countPairs(vector<int>& nums) {

        //dump--complex thinking,, make it simple , u can solve by converting it to string----------
//         int n = nums.size();
//         unordered_map<int, vector<int>> mp;

//         for(int i =0; i<n; i++){
//             int temp;
//               while(temp > 0){
//                  temp = nums[i];
//                   int r = temp%10;
//                   mp[nums[i]].push_back(r);
//                   temp = temp/10;
//               }
//         }

// unordered_map<vector<int>, int> mp2;
//         for(auto& it: mp){
//             vector<int> v = it.second;
//             sort(v.begin(), v.end());
//             mp2[v]++;
//         }

//         int ans= 0;
     
//      for(auto & k: mp2){
//         if(k.second % 2 == 0){
//             ans += k.second;
//         }
//      }

//         return ans/2;

//-------not working------------------

// int n = nums.size();

// unordered_map<string, int> mp;

// for(int i = 0; i<n; i++){
//     string x = to_string(nums[i]);
//     sort(x.begin(), x.end());
//     mp[x]++;
// }

// int ans = 0;

// for(auto & it: mp){
//     int frq = it.second;
//     ans += (frq * (frq-1))/2;
// }

// return ans;

    int count = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {

                    count += areAlmostEqual(nums[i], nums[j]);
            
            }
        }
        
        return count;

    }
};