class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int x = horizontalCut.size();
        int y = verticalCut.size();

        int hPieces = 1;
        int vPieces = 1;

        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>()); //in descending oreder
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());

        int i = 0;
        int j = 0;

        int ans = 0;

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