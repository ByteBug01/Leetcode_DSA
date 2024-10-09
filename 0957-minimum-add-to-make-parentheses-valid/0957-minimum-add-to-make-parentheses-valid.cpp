class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int cnt=0, cnt1 = 0;
        for(auto a:s)
        {
            if(a=='(')
                cnt1++;
            else if(a==')')
            {
                if(cnt1>0)
                   { cnt1--;}
                else
                   { cnt++;}
            }
        }
        return cnt+cnt1;
    }
};