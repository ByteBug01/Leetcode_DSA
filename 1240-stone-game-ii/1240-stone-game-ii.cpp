class Solution {
public:
    int n;

    int t[2][101][101];

    int solve(vector<int>& piles, int person, int i, int m) {
        if (i >= n) return 0;

        if(t[person][i][m] != -1) return t[person][i][m];

        int ans = (person == 1) ? INT_MIN : INT_MAX;
        int stones = 0;

        for (int x = 1; x <= min(2 * m, n - i); x++) {
            stones += piles[i + x - 1];

            if (person == 1) { // Alice
                ans = max(ans, stones + solve(piles, 0, i + x, max(m, x)));
            } else { // Bob
                ans = min(ans, solve(piles, 1, i + x, max(m, x)));
            }
        }

        return t[person][i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        memset(t, -1, sizeof(t));
        
        return solve(piles, 1, 0, 1);
    }
};
