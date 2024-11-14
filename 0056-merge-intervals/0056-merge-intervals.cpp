class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
      int n = arr.size();
      sort(arr.begin(), arr.end());

      vector<vector<int>> ans;

      for(int i=0; i<n; i++){
        int start = arr[i][0];
        int end = arr[i][1];

        if(!ans.empty() && end <= ans.back()[1]){  //yha pe jo curr ele ka end hai wo ans k last ele k end se chotta hoga 
                                                   //toh wo already covered hai ans ke interval me 
            continue;
        }

        for(int j =i+1; j<n; j++){
            if(arr[j][0] <= end){   //next ele ka start <= curr k end then , update end jo max hoga
                end  = max(arr[j][1], end);
            }else{        //otherwise new interval
                break;
            }
        }

        ans.push_back({start, end});
      
      }

      return ans;
    }
};