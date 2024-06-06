class Solution {
public:
int n;

//memoization //LIS VARIENT -------------------------------------------------

int t[1001][1001];

bool isPredecessor(string &s1, string& s2){
    int m = s1.length();
    int n =s2.length();
    if(m >= n || n-m != 1){
return false;
    }
    int i = 0;
    int j = 0;

    while(i < m && j < n){
        if(s1[i] == s2[j]){
            i++;
        }
        j++;
    }

    return i == m;
}

static bool comp(string& s1, string &s2){
    return s1.length() < s2.length(); //jiska length chotta hai wo phle aaye
}

int LIS(vector<string>& words, int p, int curr_idx){

    if(curr_idx == n) return 0;

    if(p != -1 && t[p][curr_idx] != -1){
        return t[p][curr_idx];
    }

    int take = 0, not_take = 0;

    if(p == -1 || isPredecessor(words[p], words[curr_idx])){
        take = 1 + LIS(words, curr_idx, curr_idx+1);
    }

    not_take = LIS(words, p, curr_idx+1);

    if(p != -1){
        t[p][curr_idx] = max(take, not_take);
    }

    return max(take, not_take);
}


    int longestStrChain(vector<string>& words) {
         n = words.size();

         sort(words.begin(), words.end(), comp);

         memset(t, -1, sizeof(t));
         int prev_idx = -1;
         int curr_idx = 0;

         return LIS(words, prev_idx, curr_idx);
    }
};