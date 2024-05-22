class Solution {
public:
    bool checkIfPangram(string sentence) {

      vector<int> arr(26, 0);

       for(char & ch: sentence){
        arr[ch - 'a']++;
       } 

       for(auto & it: arr){
        if(it == 0){
            return false;
        }
       }

       return true;
    }
};