class Solution {
public:

int hppy(int n ){
    int sum = 0;
    while(n > 0){
        int digi = n %10;
        sum += digi*digi;
        n/=10;
    }
    return sum;
}
    bool isHappy(int n) {
        unordered_set<int> seen;
       while(n!= 1 && !seen.count(n)){
          seen.insert(n);
          n = hppy(n);
       } 
return n==1;
    }
};