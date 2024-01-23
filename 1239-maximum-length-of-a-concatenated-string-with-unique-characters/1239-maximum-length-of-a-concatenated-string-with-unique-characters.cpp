class Solution {
public:
    
    //DP recursive
    
    bool hasDup(string & s1, string &s2){
        int arr[26] =  {0};
        
        for(char& ch: s1 ){
            if(arr[ch-'a'] > 0)
                return true;
            
            arr[ch-'a']++;
        }
        
        for(char &ch: s2){
            if(arr[ch-'a']  >0)
                return true;
        }
        
        return false;
    }
    
    
    
    int solve(vector<string>& arr, int i, string temp, int n){
        if(i >= n){
            return temp.length();
        }
        
        int include  = 0;
        int exclude = 0;
        
        if(hasDup( arr[i], temp)){
            exclude = solve(arr, i+1, temp, n);
        }else{
            exclude = solve(arr, i+1, temp, n);
            include = solve(arr, i+1, temp+arr[i], n);
        }
        
        return max(include, exclude);
    }
    
    
    int maxLength(vector<string>& arr) {
      int n = arr.size();
        
        string temp = "";
        int i = 0;
        return solve(arr, i, temp, n);
    }
};