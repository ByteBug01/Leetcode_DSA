class Solution {
public:
    bool isCircularSentence(string sentence) {
       vector<string> words;
        string word = "";
        
        for (char ch : sentence) {
            if (ch == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += ch;
            }
        }
        words.push_back(word);  
        
        int n = words.size();
        for (int i = 0; i < n; i++) {
            char lastChar = words[i][words[i].size() - 1];
            char firstCharNext = words[(i + 1) % n][0]; //for first & last
            if (lastChar != firstCharNext) {
                return false;
            }
        }
        
        return true;
    }
};