// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//       string str="";
//       bool check=false;
//       for(int i=0; i<strs[0].size(); i++){
//           char c = strs[0][i];
//           for(int j=1; j<strs.size(); j++){
//               if(c!=strs[j][i]) check=true;
//           }
//           if(!check) str.push_back(c);
//           else break;
//       }  
//       return str;
//     }
// };

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        int n = strs.size();

        string first = strs[0];
        string last = strs[strs.size() - 1];
        
        int i = 0;
   
        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }

        return strs[0].substr(0, i);
    }
};