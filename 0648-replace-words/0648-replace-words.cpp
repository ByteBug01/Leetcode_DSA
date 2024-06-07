class Solution {
public:

string findRoot(string& word, unordered_set<string> & st){
    
    for(int len = 0; len<word.size(); len++){
        string root = word.substr(0, len);

        if(st.count(root)){
            return root;
        }
    }
    return word;
}

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(begin(dictionary), end(dictionary));

        stringstream ss(sentence);
        string word;

string ans ="";
        while(getline(ss, word, ' ')){
            ans += findRoot(word, st) + " ";
        }

///remove last space
ans.pop_back();
        return ans;
    }
};