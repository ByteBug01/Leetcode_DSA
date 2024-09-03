class Solution {
public:
     
    int calSum(int& t){
        int sum = 0;
        while(t>0){
            int r = t%10;
            sum += r;
            t/=10;
        }
        return sum;
    }

    int getLucky(string s, int k) {
        string tmp = "";

        for(char & ch: s){
            tmp += to_string(ch - 'a' + 1);
        }

       int t = 0;

       for(auto ch: tmp){
        t += ch - '0';
       }


       int ans = t;

       while(k-- > 1){
          ans = calSum(ans);
       }

       return ans;
    }
};