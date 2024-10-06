//wrong ans----------------------------------

// class Solution {
// public:
//     bool areSentencesSimilar(string sentence1, string sentence2) {
//         int n1 = sentence1.size();
//         int n2 = sentence2.size();

//         if(n2 > n1) { 
//             string temp =sentence1;
//             sentence1 = sentence2;
//             sentence2 = temp;  
//             }


//         unordered_map<string , int> mp1;
//         string tmp = "";
//         int cnt = 0;
//         vector<int> dekho;
//         for(auto & ch: sentence1){
//             if(ch == ' '){ tmp = "";}
//             tmp += ch;
//             cnt++;
//             mp1[tmp] = cnt;
//             dekho.push_back(mp1[tmp]);
//         }

//         // unordered_map<string , int> mp2;
//         // string tmp2 = "";
//         // int cnt2 = 0;

//         //   for(auto & char: sentence2){
//         //     if(char == ' '){ tmp2 = "";}
//         //     tmp 2+= char;
//         //     cnt2++;
//         //     mp2[tmp2] = cnt2;
//         // }

//         string asa = "";
//         vector<int> vis;
//         for(auto& ch: sentence2){
//             if(ch == ' ') asa ="";

//             asa+=ch;

//             if(mp1.find(asa) != mp1.end()){
//                 vis.push_back(mp1[asa]);
//             }
//         }


//         if(vis.size() == 1 && v[0] != 1 && mp1.size() > 1){ return false;}


// if(vis[0] == 0 && vis[vis.size() - 1] == mp1.end()) return true;

// return false;

//     }
// };

//nice prblm--------------------
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1 == sentence2) return true;

        if (sentence1.size() < sentence2.size()) swap(sentence1, sentence2);

        vector<string> words1, words2;

        stringstream ss1(sentence1), ss2(sentence2);
        string word;

        //Split sentence1 into words
        while (ss1 >> word) words1.push_back(word);

        //Split sentence2 into words
        while (ss2 >> word) words2.push_back(word);

        int n1 = words1.size();
        int n2 = words2.size();

                    //Check for prefix match
        int i = 0;
        while (i < n2 && words1[i] == words2[i]) i++;

              //Check for suffix match
        int j = 0;
        while (j < n2 && words1[n1-j-1] == words2[n2-j-1]) j++;

        // The sentences are similar if the total matched words (prefix + suffix) cover sentence2
        return i+j >= n2;
    }
};
