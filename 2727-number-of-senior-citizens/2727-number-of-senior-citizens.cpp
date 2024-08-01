class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(auto & s: details){
      
       int a = s[11] - '0';
       int b = s[12] - '0';

       int age = a*10 + b;

       if(age > 60){
        cnt++;
       }
             
        }
    
return cnt;
    }
};