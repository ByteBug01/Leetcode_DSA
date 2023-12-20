class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        
        int choc = prices[0]+prices[1];
        
        if(choc<=money){
            return money-choc;
        }else{
            return money;
        }
    }
};