// class Solution {
// public:

//wrong ans-----------------------
//     bool checkInclusion(string s1, string s2) {
//         int n1 = s1.size();
//         int n2 = s2.size();

//         set<char>st;
//         for(auto& it: s1){
//             st.insert(it);
//         }
//         int cnt = 0;
//         for(int i =0; i<n2; i++){
//             if(st.find(s2[i]) != st.end()){
//                 cnt++;
//             }else{
//                 cnt = 0;
//             }

//             if(cnt == n1) return true;
//         }

//         return false;
//     }
// };


class Solution {
public:
bool allpresent(vector<int> counter){
     for(auto it: counter){
        if(it > 0) return false;
     }
     return true;
}

    bool checkInclusion(string s1, string s2) {

            int n1 = s1.length();
            int n2  = s2.length();

            vector<int> counter(26, 0);

            for(auto it: s1){
                counter[it - 'a']++; 
            }

            int i  =0; int j =0;
            int ans = 0;

            while(j < n2){
                counter[s2[j] - 'a']--;

                while(j-i+1 == n1){
                    if(allpresent(counter)) ans++;

                    counter[s2[i] - 'a']++;
                    i++;
                }
                j++;
            }
return (ans) ? true: false;

    }
};