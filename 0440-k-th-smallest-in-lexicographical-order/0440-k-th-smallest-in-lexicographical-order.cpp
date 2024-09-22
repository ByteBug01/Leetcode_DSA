// class Solution {
// public:

// //just like yesterproblem: 386. Lexicographical Numbers
//  void solve(int curr, int n, int &ans, vector<int> &order, int k) {
//         if(curr > n) return;

//         order.push_back(curr);
        
//         if(order.size() == k) {
//             ans = curr;
//             return;
//         }

//         for(int j = 0; j <= 9; j++) {
//             int x = curr * 10 + j;
//             if(x > n) return;
//             solve(x, n, ans, order, k);
//         }
//     }

//     int findKthNumber(int n, int k) {
//               int ans = -1;  
//         vector<int> order;
//         for(int i = 1; i <= 9; i++) {
//             solve(i, n, ans, order, k);
//             if(ans != -1) break;  //stop here, as ans is found at kth pos
//         }
//         return ans;
//     }
// };

class Solution {
public:
    long countSteps(long curr, long n) {
        long steps = 0;
        long first = curr, last = curr;
        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        long curr = 1;
        k--;
        
        while (k > 0) {
            long steps = countSteps(curr, n);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }
};
