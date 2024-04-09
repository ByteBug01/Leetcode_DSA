class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
          int ans = 0; 
        for(int i = 0; i < tickets.size(); ++i) { 
            if(tickets[i] < tickets[k]) { // if current element is lower than tickets[k], we add the whole element
                ans += tickets[i];
            }else { // if it's higher or equal, we have to cases:
                ans += tickets[k]; // if i is lower/equal to k, we add the whole tickets[k]
                if(i > k) // if index > k, we basically add tickets[k] - 1
                    --ans; // we just subtract the whole element 1 to do so.
            }
        }
        return ans; 
    }
};