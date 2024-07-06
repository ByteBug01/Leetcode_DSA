class Solution {
public:
    int passThePillow(int n, int time) {

int i=1;
int d = 1; 
       while(time > 0){
        
        if(i + d <= n && i+d >=1){ //should be in range of 1 to n,(inclusive)
          i += d;
          time--;
        }else{
            d *= -1; //change direction
        }
       }
       return i;
    }
};