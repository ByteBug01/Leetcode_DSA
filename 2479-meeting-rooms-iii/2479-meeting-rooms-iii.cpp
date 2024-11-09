// class Solution {
// public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         sort(meetings.begin(), meetings.end());

//         vector<pair<int, int>> occupiedRoom(n, {0,0});

//         int size = meetings.size();

//         for(int i = 0; i<size; i++){
//             int start = meetings[i][0];
//             int end = meetings[i][1];
//             int duration = end - start;
//             bool available = false;
//             int minTimeRoom = INT_MAX;
//             int minTime = 0; 

//             // for(int i=0; i<n; i++){
//             //     if(occupiedRoom[i] == 0){
//             //         occupiedRoom[i] = end;
//             //     }
//             // }
//             int j = 0;
//             while(j < n){
//                 if(occupiedRoom[j].first <= start){
//                    occupiedRoom[j].first = end;
//                     occupiedRoom[j].second++;
//                     available = true;
//                 }

//                 if(minTimeRoom > occupiedRoom[j].first){
//                     minTimeRoom = occupiedRoom[j].first;
//                     minTime = j;
//                 }
//             }

//             if(!available){
//                 occupiedRoom[minTime] += duration;
//                 occupiedRoom[minTime].second++;
//             }
//         }

//         int ans = 0;
//         for(int i = n-1; i>=0; i--){
//             if(ans <= occupiedRoom[i].second){
//                 ans = occupiedRoom[i].second;
//             }
//         }

//         return ans;
//     }
// };


// class Solution {
// public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         sort(meetings.begin(), meetings.end());

//         // Min heap to track free rooms by room index
//         priority_queue<int, vector<int>, greater<int>> freeRooms;
//         for (int i = 0; i < n; ++i) {
//             freeRooms.push(i);
//         }

//         // Min heap to track occupied rooms by (end time, room index)
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedRooms;

//         // Count of meetings each room hosted
//         vector<int> meetingCount(n, 0);

//         for (auto& meeting : meetings) {
//             int start = meeting[0];
//             int end = meeting[1];
//             int duration = end - start;

//             // Free up rooms that have finished their meetings before the current meeting starts
//             while (!occupiedRooms.empty() && occupiedRooms.top().first <= start) {
//                 freeRooms.push(occupiedRooms.top().second);
//                 occupiedRooms.pop();
//             }

//             if (!freeRooms.empty()) {
//                 // Assign a free room
//                 int room = freeRooms.top();
//                 freeRooms.pop();
//                 occupiedRooms.push({end, room});
//                 meetingCount[room]++;
//             } else {
//                 // No free room; choose the one that becomes free the soonest
//                 auto nextAvailable = occupiedRooms.top();
//                 occupiedRooms.pop();

//                 int room = nextAvailable.second;
//                 int newEnd = nextAvailable.first + duration;
//                 occupiedRooms.push({newEnd, room});
//                 meetingCount[room]++;
//             }
//         }

//         // Find the room with the most meetings; if tie, return the smallest index
//         int maxMeetings = 0, result = 0;
//         for (int i = 0; i < n; ++i) {
//             if (meetingCount[i] > maxMeetings) {
//                 maxMeetings = meetingCount[i];
//                 result = i;
//             }
//         }

//         return result;
//     }
// };


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        int m = meetings.size();

        sort(meetings.begin(), meetings.end());

        vector<long long> earlyAvailableRoom(n, 0);
        vector<int> roomCnt(n, 0);

        for(auto & meet: meetings){
            int start = meet[0];
            int end = meet[1];
            int duration = end- start;
            bool available = false;

            long long earlyEndRoom = LLONG_MAX;
            int earlyTime = 0;


        for(int j = 0 ; j<n; j++){
            if(earlyAvailableRoom[j] <= start){
                earlyAvailableRoom[j] = end;
                roomCnt[j]++;
                available = true;
                break;
            }

            if(earlyEndRoom > earlyAvailableRoom[j]){
                earlyEndRoom = earlyAvailableRoom[j];
                earlyTime = j;
            }
        }


        if(!available){
            earlyAvailableRoom[earlyTime] += duration;
            roomCnt[earlyTime]++;
        }

        }

        int ansRoom = -1;
        int maxUse = 0;

        for(int i=0; i<n; i++){
            if(maxUse < roomCnt[i]){
                maxUse = roomCnt[i];
                ansRoom = i;
            }
        }

     return ansRoom;
    }
};


