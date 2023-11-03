class Solution {
public:
    
    //brute force
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int c = 1 ;
        
        for(int i=0; i<target.size(); i++){
            while(c<target[i]){
                result.push_back("Push");
                  result.push_back("Pop");
                c++;
            }
            result.push_back("Push");
            c++;
        }
        
        return result;
    }
};