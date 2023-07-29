class Solution {
public:
    vector<vector<double>>dp;
    
    double eatSoup(int A, int B)
    {
        // A empty first, has full probability
        if(A<=0 && B>0) return 1.0;
        
        // A and B empty at same time, has half probability
        if(A<=0 && B<=0) return 0.5;
        
        // B empty first, has 0 probability
        if(A>0 && B<=0) return 0.0;

        // return precalculated result
        if(dp[A][B]!=-1.0) return dp[A][B];
        
        // run recursion for all four operations and add their proabbility results and multiply by 0,25
        // as all operations has equal probability 0.25 and also mutually exclusive 
        return dp[A][B] = 0.25*(eatSoup(A-100,B)+eatSoup(A-75,B-25)+eatSoup(A-50,B-50)+eatSoup(A-25,B-75));

    }

    double soupServings(int N){

        // Corner case probability becomes 1 when N>5000
        if(N>=5000) return 1.0;
        
        // NxN dp vector holds the probability result for soup state (A,B)
        dp.resize(N+1,vector<double>(N+1,-1.0));

        // call recursion with (A=N, B=N)
        return eatSoup(N,N);
    }
};