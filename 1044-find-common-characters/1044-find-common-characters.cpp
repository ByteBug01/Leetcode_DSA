class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v(26, INT_MAX);
        
        for(string & word: words){
            vector<int> temp(26, 0);
            for(auto & ch: word){
                  temp[ch - 'a']++;
            }

            for(int i = 0; i<26; i++){
                    v[i] = min(v[i], temp[i]);
                }
        } 

        vector<string> ans;

        for(int i = 0; i<26; i++){
            int x = v[i];
            while(x--){
            ans.push_back(string(1,i+'a'));  
            }
        }
   
   return ans;
    }
};

//ascii value of b = 98
//ascii value of a = 97
// b - 'a' = 98 - 97 = 1;
// 1 + 'a' = 1 + 97 = 98