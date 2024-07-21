class Solution {
public:
    int minChanges(int n, int k) {
        bitset<32> n_binary(n);
        n_binary.to_string();
 
        bitset<32> k_binary(k);
        k_binary.to_string();

int ans =  0;

        for(int i = 0; i<32; i++){
            if(n_binary[i] == 1 && k_binary[i] == 0){
                ans++;
            }else if(n_binary[i] == 0 && k_binary[i] == 1){
                return -1;
            }
        }

return ans;
    }
};