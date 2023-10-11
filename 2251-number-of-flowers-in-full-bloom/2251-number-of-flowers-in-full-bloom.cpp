class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    //     int n = flowers.size(); int m = people.size();
    //     // sort(flowers.begin(), flowers.end());
    //     vector<int> ans;
    //     int count =0;
    //     for(int i =0; i<n ; i++)
    //     {
    //     for(int j = 0; j<m ; j++)
    //      {
    //         if(flowers[i][0]<people[j] && people[j]<flowers[i][1])
    //         {
    //             count++;
    //             ans.push_back(count);
    //         }
    //       }
    //     } 
    //    return ans;
   vector<int> sortedPeopleAt(people.begin(), people.end());
   sort(sortedPeopleAt.begin(), sortedPeopleAt.end());

   sort(flowers.begin(), flowers.end());

   unordered_map<int, int>  bloomCnt;
   priority_queue<int, vector<int>, greater<int>> bloomEndTimes;

   int flowerIdx = 0;

   for(int personTime: sortedPeopleAt){

       while(flowerIdx< flowers.size() && flowers[flowerIdx][0]<=personTime)
       bloomEndTimes.push(flowers[flowerIdx++][1]);

       while(!bloomEndTimes.empty() && bloomEndTimes.top() < personTime)
       bloomEndTimes.pop();

       bloomCnt[personTime] = bloomEndTimes.size();
   }
    vector<int> flowerCnts;
for(int arrivalTime: people)
            flowerCnts.push_back(bloomCnt[arrivalTime]);


return flowerCnts;
    }
};