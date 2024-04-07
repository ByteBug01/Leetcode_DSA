class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, star;
        int n  = s.length();
        
        // for processing close bracket
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] == '(') open.push(i);
            
            else if(s[i] == '*') star.push(i);
            
            else{
                if(!open.empty())
                    open.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        
        while(!open.empty()){
            if(star.empty())
                return false;
            else if(open.top() < star.top()){ //opening bracket left side of *
                open.pop();
                star.pop();
            }
            else  //opening bracket right side of *
                return false;
        }
        return true;
    }
};