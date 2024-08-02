// class Solution {
// public:
//wrong answer coming-----------------------------------
//     int minSwaps(vector<int>& nums) {
//         int n  = nums.size();
          
//           int x, y;
//           int cnt0 = 0;
//         for(int i = 0; i<n; i++){
//              if(nums[i] == 1){
//                 x = i;
//                 break;
//              }
//              if(nums[n-i-1] == 1){
//                 y = n-i-1;
//                 break;
//              }
//         }

// int cnt1 = 0;
// int ans = 0;
//         if(x == 0 && y == n-1){
//             int a, b;
//              for(int i = x; i<=y; i++){
//              if(nums[i] == 0){
//                 a = i;
//                 break;
//              }
//              if(nums[n-i-1] == 0){
//                 b = n-i-1;
//                 break;
//              }
//         }

//         for(int i =a; i<=b; i++){
//            if(nums[a] == 1){
//             cnt1++;
//            }
//          }

//          ans = cnt1;
//         }else{
//         for(int i = x; i<=y; i++){
//             if(nums[i] == 0){
//                 cnt0++;
//             }
//         }
//         ans = cnt0;
//         }

// return ans;
//     }
// };

//-----wrong output-----
// class Solution {
// public:

// int n;

// int solve(vector<int>& merge, int tot, int x){

// int mini = tot;
//        int curr = 0;

//        for(int i =0; i<tot; i++){ //window of size 'tot1'
//             if(merge[i]== x) curr++;
//        }

//        mini = curr;

//        for(int i =1; i<n; i++){
//         if(merge[i] == x) curr--;
//         if(merge[i+tot-1] == x) curr++;

//         mini = min(mini, curr);
//        }


//        return mini;
// }


//     int minSwaps(vector<int>& nums) {
//         n  = nums.size();
       
//        int tot1 = 0;
//        for(int i =0; i<n; i++){
//         tot1+=nums[i];
//        }

//        int tot0 = n-tot1;

//        if(tot1 == 0 || tot1== n) return 0;

//        vector<int> merge(nums.begin(), nums.end());
//        merge.insert(merge.end(), nums.begin(), nums.end());

//        int min0 = solve(merge, tot0, 0);
//        int min1 = solve(merge, tot1, 1);

// return min(min1, min0);
//     }
// };


class Solution {
public:

int n;

int minSwaps(vector<int>& nums) {
    int n = nums.size();

    vector<int> temp(2*n);

    for(int i = 0; i<2*n; i++){
        temp[i] = nums[i%n]; //circular array
    }

    int tot1 = 0;

    for(int & num: nums){
          if(num == 1) tot1++;
    }

    int i = 0;
    int j = 0;

    int max1 = 0;
    int curr1 = 0;

    while(j < 2*n){
        if(temp[j] == 1){
            curr1++;
        }

        if(j-i+1 > tot1){
            curr1 -= temp[i];
            i++;
        } 

        max1 = max(max1, curr1);
        j++;
    }

return tot1 - max1;

}
};