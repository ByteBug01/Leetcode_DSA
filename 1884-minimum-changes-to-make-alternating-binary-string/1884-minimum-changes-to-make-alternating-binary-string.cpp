class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        int start0 =  0; //010101...
        int start1 = 0; //101010....

        for(int i  =0; i<n; i++){
            if(i%2 == 0){ //even position
                  if(s[i] == '0'){ // agr 1 se start hora string, toh even position me 1 ana chiye
                    start1++; 
                  }else{ //agr 0 se start hora string, toh even position me 0 ana chiye
                    start0++;
                  }
            }else{
                if(s[i] == '0'){
                    start0++;
                }else{
                    start1++;
                }
            }
        }

        
            return min(start0, start1);
        
    }
};