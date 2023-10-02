class Solution {
public:
    bool winnerOfGame(string color) {
        int cnt1 = 0; int cnt2 = 0;
        for(int i=1; i<color.size(); i++){
            if(color[i]=='A'  && color[i-1]=='A' && color[i+1]=='A' )
            {
                cnt1++;
            }
            if(color[i]=='B'  && color[i-1]=='B' && color[i+1]=='B' )
            {
                cnt2++;
            }
            }
        if(cnt1>cnt2){
            return true;
        }
        return false;
    }
};