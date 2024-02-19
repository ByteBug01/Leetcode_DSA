class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }
        
        if(n%2 != 0){
            return false;
        }
        else{
            for(int i = 1; i<=31; i++ ){
                if(pow(2, i) == n){
                    return true;
                }
            }
        }
        
        return false;
    }
};