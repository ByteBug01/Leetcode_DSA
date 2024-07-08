// class Solution {
// public:


//------------------not working-------------------------------
//     int findTheWinner(int n, int k) {
//         vector<int> temp;

//         int cnt = 1;
//        vector<int> nums(n);

//        for(int i =1; i<=n; i++){
//         nums.push_back(i);
//        }
//          int i = 0;
//         while(temp.size() > 1){
//             if(i == n){
//                 i = 0;
//             }
//              if(cnt == k){
//                 continue;
//              } 
//              temp.push_back(nums[i]);
//              i++;
//         }

// int ans;
//          for(int i =0; i<temp.size(); i++){
//         ans = temp[i];
//        }

//        return ans;
//     }
// };


class Solution {
public:
    int findTheWinner(int n, int k) {

         vector<int> friends;
        for (int i = 1; i <= n; i++) {
            friends.push_back(i);
        }

        int i= 0;

        while (friends.size() > 1) {
            i= (i + k - 1) % friends.size(); //mod friend.size() to evaluate the vector assuming circle
            
            friends.erase(friends.begin() + i);
        }

        // The last remaining friend is the winner
        return friends[0];
    }
};