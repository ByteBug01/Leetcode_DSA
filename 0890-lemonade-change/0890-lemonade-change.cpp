class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
     //   int n  = bills.size();
      //  int keeper = 0;

        // if(bills[0] != 5) return false;

        // bool k = false;

        // for(int i = 0; i<n; i++){
        //     if(bills[i] == 5){
        //         keeper += 5;
        //         k = true;
        //     }
             
        //     else if(bills[i] > 5 & keeper - bills[i] > 0){
        //           keeper += 5;
        //           keeper -= (bills[i] - 5);
        //           k = true;
        //      }
        //      else{
        //         k = false;
        //         break;
        //      }
        // }

        // return k;

        int n  = bills.size();

        int doller5 = 0;
        int doller10 = 0;

        for(int i = 0; i<n; i++){
            if(bills[i] == 5){
                doller5++;
            }
            else if(bills[i] == 10) {

            if (doller5 > 0){
                 doller5--;
                 doller10++;
            }
            else{
                return false;
            }
         }

         else if(bills[i] == 20){
            if(doller5 > 0 && doller10 > 0){
                doller5--;
                doller10--;
            }else if(doller5>=3){
                doller5 -= 3;
            }else{
                return false;
            }
         }
        }

return true;
    }
};