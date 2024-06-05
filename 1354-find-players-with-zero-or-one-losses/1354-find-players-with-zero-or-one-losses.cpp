class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
//         map<int,int> lost;
//         for (auto m : matches)
//         {
//             if (!lost.count(m[0])) lost[m[0]] = 0;
//             lost[m[1]]++;
//         }
        
//         vector<int> zero, ones;
//         for (auto[k,l] : lost)
//         {
//             if (l == 0) zero.push_back(k);
//             if (l == 1) ones.push_back(k);
//         }
        
//         return {zero,ones}; 
        
       
int n = matches.size();

unordered_map<int, int> lossfrq;

for(int i = 0; i<n; i++){
    int winner  = matches[i][0];
    int looser = matches[i][1];

    lossfrq[looser]++;

    if(lossfrq.find(winner) == lossfrq.end()){
        lossfrq[winner] = 0;
    }
}

  vector<vector<int>> ans(2);
    vector<int> loss_0;
    vector<int> loss_1;


for(auto &[plyer, frq] : lossfrq){
    if(frq == 1){
        loss_1.push_back(plyer);
    }
    else if(frq == 0){
        loss_0.push_back(plyer);
    }
}

sort(begin(loss_0), end(loss_0));
sort(begin(loss_1), end(loss_1));

ans[0] = loss_0;
ans[1] = loss_1;

return ans;
    }
};