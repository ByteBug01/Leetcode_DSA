class Solution {
public:
    //solve again//
     int maxRectangleInHistogram(vector<int> &v){
        stack<int> st;
        int maxA = 0;
        int n = v.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || v[st.top()] >= v[i])){
                int height = v[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() -1;
                maxA = max(maxA,width*height);

            }
            st.push(i);
        }
        return maxA;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<int> v(n,0);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1'){
                    v[j]++;
                }else{
                    v[j] = 0;
                }
            }
            int r = maxRectangleInHistogram(v);
            res = max(res,r);
        }
        return res;
    }
};