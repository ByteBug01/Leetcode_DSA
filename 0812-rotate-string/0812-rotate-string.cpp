class Solution {
public:
    bool rotateString(string s, string goal) {
        //All rotations of A are contained in A+A. Thus, we can simply 
        //check whether B is a substring of A+A.

       if (s.length() != goal.length()) {
            return false;
        }

        string ss = s + s;
        //check if goal is substring of concatenated string or not
        return ss.find(goal) != string::npos;
    }
};