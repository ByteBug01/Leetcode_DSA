class Solution {
public:

//2 jugs can give target jug iff gcd of 2 jugs capacity divides target jug capacity fully

int gcd(int a, int b){
    if(a == 0) return b;
    else return gcd(b%a, a);
}


    bool canMeasureWater(int x, int y, int target) {
        if(x+y < target) return false;
        
        int a = gcd(x,y);

        if(target%a == 0) return true;
        else return false;

    }
};