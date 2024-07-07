// class Solution {
// public:
//     int numWaterBottles(int numBottles, int numExchange) {

//         if(numBottles == numExchange){
//             return numBottles + 1;
//         }

//         if(numBottles/numExchange == numExchange){
//             return numBottles + numExchange + 1;
//         }
        
//         int ans = 0;
//         ans += numBottles;

//         while(numBottles >= numExchange){
//         int a = numBottles/numExchange; //newbottles
//         int b = numBottles%numExchange; //remainingBottles

//         ans += a;

//         numBottles = a + b; 
        
//         // b =   numBottles%numExchange;
//         }
// return ans;

//     }
// };


class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles; 

        while (numBottles >= numExchange) {
            int a = numBottles / numExchange; // new bottles
            int b = numBottles % numExchange; // remaining empty bottles

            ans += a;
            numBottles = a + b; 
        }

        return ans;
    }
};