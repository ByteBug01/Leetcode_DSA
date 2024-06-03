class Solution {
public:
    int hammingDistance(int x, int y) {
       int  hamming_dis = 0;

       int x_bit = 0;
       int y_bit = 0;
 
 while(x != 0 || y != 0){
    x_bit = x & 1;  //010 & 001 = 0
    y_bit = y & 1;

    if(x_bit != y_bit){
        hamming_dis++;
    }

    x = x >> 1; //0101 = 010 right shift
    y = y>> 1;
 }
return hamming_dis;
    }
};