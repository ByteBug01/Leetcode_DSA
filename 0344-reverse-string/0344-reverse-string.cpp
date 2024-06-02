class Solution {
public:
    void reverseString(vector<char>& s) {
        // 19ms------------
    //     int n = s.size();
    //     int i = 0;
    //     int j = n-1;
    //   while(i<j){
    //     swap(s[i], s[j]);
    //     i++;
    //     j--;
    //   }
 int n = s.size();
 for(int i=0; i<n/2; i++){
    swap(s[i], s[n-i-1]);
 }

    }
};