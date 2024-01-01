class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // if(s.size()==0) return 0;
        // sort(g.begin(),g.end());
        // sort(s.begin(),s.end());
        // int cnt=0;
        // for(int i=0;cnt<g.size() && i<s.size();i++){
        //     if(s[i]>=g[cnt]){
        //         cnt++;
        //     }       
        // }
        // return cnt;
        
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        
        int m = g.size();
        int n = s.size();
        
        int i = 0, j = 0;
        
        while(i<m && j<n){
            if(g[i] <= s[j]){
                i++;
            }
            j++;
        }
        
        return i;
    }
};