class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
         int x = horizontalCut.size();
        int y = verticalCut.size();

        long long hPieces = 1;
        long long vPieces = 1;

        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>()); //in descending oreder
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());

        int i = 0;
        int j = 0;

        long long ans = 0;

        while(i < x && j<y){
            if(horizontalCut[i] >= verticalCut[j]){
                ans += horizontalCut[i] * vPieces;
                hPieces++;
                i++;
            }else{
                ans += verticalCut[j] * hPieces;
                vPieces++;
                j++;
            }
        }

        while(i < x){
            ans += horizontalCut[i] * vPieces;
                hPieces++;
                i++;
        }

        while(j < y){
              ans += verticalCut[j] * hPieces;
                vPieces++;
                j++;
        }

        return ans;
    }
};

//Greedy Approach
//T.C : O(xlog + ylogy) where x and y are lengths of horizontal and vertical cuts array
//S.C : O(1)