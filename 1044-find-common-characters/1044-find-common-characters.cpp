class Solution {
public:
    void update(string& word, int count[26]){
        for(char &ch: word){
            count[ch - 'a']++;
        }
    }

    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;

        int count[26] = {0};

        update(words[0], count);

        for(int i = 1; i<words.size(); i++){
            int temp[26] = {0};

            update(words[i], temp);

            for(int j=0; j<26; j++){
                count[j] = min(temp[j], count[j]);
            }
        }

        for(int i=0; i<26; i++){
            int n = count[i];
            while(n--){
                ans.push_back(string(1, i+'a'));
            }
        }

        return ans;
    }
};

//ascii value of b = 98
//ascii value of a = 97
// b - 'a' = 98 - 97 = 1;
// 1 + 'a' = 1 + 97 = 98