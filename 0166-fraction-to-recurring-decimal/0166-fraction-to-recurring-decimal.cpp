class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if(denominator == 0) return "";
        if(numerator == 0) return "0";

        string ans;
    if ((numerator < 0) ^ (denominator < 0)) {
        ans += "-";
    }

    long long num = abs(static_cast<long long>(numerator));
    long long deno = abs(static_cast<long long>(denominator));


    ans += to_string(num / deno);
    long long r = num % deno;

    if (r == 0) {
        return ans; 
    }

    ans += ".";

    unordered_map<long long, int> r_pos;
    string frac;

    while(r!= 0){
        if(r_pos.find(r) != r_pos.end()){
            int i = r_pos[r];
            frac.insert(i, "(");
            frac += ")";
            return ans + frac;
        }
    

    r_pos[r] = frac.size();

    r *= 10;

    frac += to_string(r/deno);
    r %= deno;
     }
      return ans + frac;
    }
};