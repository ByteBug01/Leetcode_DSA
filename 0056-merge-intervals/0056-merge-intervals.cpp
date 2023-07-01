class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        
       sort(arr.begin(),arr.end() );
        
        int n = arr.size();
        
            vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(ans.empty()){
                ans.push_back(arr[i]);
            }
            else{
                vector<int>& v = ans.back();
                int y= v[1]; // end of previous interval
                //comapare 'y' with i's start time
                
                //overlapping
                if(arr[i][0]<=y){
                    v[1]=max(y, arr[i][1]);
                }
                //not overlapping
                else
                {
                    ans.push_back(arr[i]);
                }
            }
        }
        return ans;
    }
}; 