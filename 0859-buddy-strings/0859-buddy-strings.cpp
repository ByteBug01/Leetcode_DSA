class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
        return false;
        int n = s.size();
        vector<int> fre(26);
        vector<char> vec1,vec2;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=goal[i])
            {
                cnt++;
                vec1.push_back(s[i]);
                vec2.push_back(goal[i]);
            }
            fre[s[i]-'a']++;
        }
        if(cnt==2)
        {
            sort(vec1.begin(),vec1.end());
            sort(vec2.begin(),vec2.end());
            if(vec1[0]==vec2[0] && vec1[1]==vec2[1])
            return true;
            return false;
        }
        else if(cnt==0)
        {
            for(int i=0;i<26;i++)
            {
                if(fre[i]>=2)
                return true;
            }
            return false;
        }
        return false;
    }
};