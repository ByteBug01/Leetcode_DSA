class Solution {
public:
    int accountBalanceAfterPurchase(int pa) {
        // int  remain=10%purchaseAmount;
        // int x = purchaseAmount+remain;
        // int y = purchaseAmount-remain;
        // int mm=max(x,y);
        // return 100-mm;
        int x = pa % 10;
        int y = 10 - x, c = 0;
        if(x < y)
            c = pa - x;
        else
            c = pa + y;
        return (100 - c);
    }
};