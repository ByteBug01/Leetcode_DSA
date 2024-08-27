class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
         int maxLimit = 2000 + 2 * b;  // Set a safe upper bound for positions
        vector<vector<int>> visited(maxLimit + 1, vector<int>(2, 0));  // visited[position][0] means forward, [1] means backward
        
        // Mark forbidden positions as visited
        for (int pos : forbidden) {
            visited[pos][0] = visited[pos][1] = 1;
        }

        if(x == 0) return 0;
        
        queue<pair<int, bool>> q;  // pair<int, bool> where int is position and bool indicates if the last jump was backward
        q.push({0, false});  // Start from position 0 with no backward jump
        visited[0][0] = 1;  // Mark position 0 as visited with forward jump

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            steps++;

            while (size--) {
                auto [curr, back] = q.front();
                q.pop();

                int forwardPos = curr + a;
                int backwardPos = curr - b;

                // Move forward
                if (forwardPos <= maxLimit && !visited[forwardPos][0]) {
                    if (forwardPos == x) return steps;
                    visited[forwardPos][0] = 1;
                    q.push({forwardPos, false});
                }

                // Move backward
                if (!back && backwardPos >= 0 && !visited[backwardPos][1]) {
                    if (backwardPos == x) return steps;
                    visited[backwardPos][1] = 1;
                    q.push({backwardPos, true});
                }
            }
        }

        return -1;  // If we can't reach x
    }
};
