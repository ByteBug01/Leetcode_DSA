// // class Solution {
// // public:
// //     int countDays(int days, vector<vector<int>>& meetings) {
        
// //          sort(meetings.begin(), meetings.end());

// //     int available_days = 0;
// //     int current_end = 0;

// //     for (const auto& meeting : meetings) {
// //         int start = meeting[0];
// //         int end = meeting[1];

       
// //         if (start > current_end + 1) {
// //             available_days += (start - 1) - (current_end + 1) + 1;
// //         }

// //         current_end = max(current_end, end);
// //     }

// //     if (current_end < days) {
// //         available_days += days - current_end;
// //     }

// //     return available_days;
// //     }
// // };

// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
//          sort(meetings.begin(), meetings.end());
// int n =meetings.size();
// int last  = 1;
// int ans = 0;
//          for(int i = 0; i<n; i++){
//           int  start = meetings[i][0];
//           int end = meetings[i][1];

//           if(i == 0){  // days= 10, last = 1, (2, 5) (7, 8)
//           ans += start - last;
//           }
//           else if(start > last){   // not overlapping like: (2, 5) (4, 7) (6, 9)
//             ans +=  start - last - 1;
//           }

//          last = max(last, end); // update the last , as last should be max, as when the case of overlapping interval comes

//          }
//         if(last < days)
//          ans += days - last;

//          return ans; 
//     }
// };


class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
       sort(meetings.begin(), meetings.end());

       int ans  = 0;
       int lastEnd = 0;

        for(auto & x: meetings){
            int a =  x[0];
            int b =  x[1];

            if(a > lastEnd){
                ans += a - (lastEnd+1);
            }

        lastEnd =  max(b, lastEnd);
        }

        if(lastEnd < days) ans += days - lastEnd; //edge case


        return ans;
    }};