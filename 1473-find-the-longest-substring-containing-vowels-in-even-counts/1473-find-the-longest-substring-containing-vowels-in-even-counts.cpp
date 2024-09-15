class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();

        unordered_map<string, int> mp;
        vector<int> state(5, 0);

        string currstate = "00000";
        mp[currstate] = -1;

        int res = 0;

        for(int i = 0; i<n; i++){
            if(s[i] == 'a'){
                state[0] = (state[0]+1)%2;
            } else if(s[i] == 'e'){
                state[1] = (state[1]+1)%2;
            } 
            else if(s[i] == 'i'){
                state[2] = (state[2]+1)%2;
            } 
            else if(s[i] == 'o'){
                state[3] = (state[3]+1)%2;
            } 
            else if(s[i] == 'u'){
                state[4] = (state[4]+1)%2;
            } 
        

string curr = "";
for(int i =0; i<5; i++){
    curr+= to_string(state[i]);
}

if(mp.find(curr) != mp.end()){
   res = max(res, i-mp[curr]);
}else{
    mp[curr] = i;
}
        }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
    return res;
    }
};