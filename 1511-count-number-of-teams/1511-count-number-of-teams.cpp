// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         int n  = rating.size();
//         // map<int , int> mp;

//         // for(int i  =0; i<n; i++){
//         //     mp[rating[i]] =  i;
//         // }

//         priority_queue<pair<int , int>, vector<pair<int, int>> max_heap;
//         priority_queue<pair<int , int>, vector<pair<int, int>, greater<pair<int, int>>> min_heap;
        
//         // for(int i =0; i<n; i++){
//         //     max_heap.push({rating[i], i});
//         //     min_heap.push({rating[i], i});
//         // }

//      max_heap.push({rating[0], 0});
//      max_heap.push({rating[1], 1});
//      max_heap.push({rating[2], 2});

//      int i = 3;

//      int cnt = 0;

//      while(!max_heap.empty()){
//             auto it = max_heap.top();
//             int x1 = it.second;
//             max_heap.pop();

//             int x2 = it.second();
            
//             if()
//      }


//     }
// };

// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         int n  = rating.size();

//         vector<pair<int, int>> v;

//         for(int i = 0; i<n; i++){
//             v.push_back({rating[i], i});
//         }

//         sort(v.begin(), v.end());

//         int cnt =0;

//         for(int i = 0; i<n-2; i++){
//             if(v[i].second<v[i+1].second && v[i+1].second < v[i+2].second){
//                 cnt++;
//             }
//         }

//         for(int i = n-1; i>=2; i--){
//             if(v[i].second>v[i-1].second && v[i-1].second > v[i-2].second){
//                 cnt++;
//             }
//         }

//         return cnt;
//     }
// };


class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;
        
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if ((rating[i] < rating[j] && rating[j] < rating[k]) || 
                        (rating[i] > rating[j] && rating[j] > rating[k])) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
