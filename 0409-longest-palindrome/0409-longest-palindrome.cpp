class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        int ans=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int count=0;
        for(auto i:mp){
            if(i.second%2==1 && count==1){  // when we find one old then convert remaining old to even 
                ans=ans+i.second-1;
            }
            else if(i.second%2==1){  // when we find first old then
                count++;
                if(count==1){
                ans=ans+i.second;   //add all element beacuse one element are at middle
                }
            }
            else if(i.second%2==0){  //for even case add all element
                ans=ans+i.second;
            }
            
        }
        return ans;
    }
};