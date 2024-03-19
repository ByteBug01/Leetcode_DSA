class Solution {
public:
    // revisit again
    int leastInterval(vector<char>& tasks, int n) {
//         int k = tasks.size();
        
//         unordered_map<int, int> freq;
        
//         for(auto i: tasks){
//             mp[i]++;
//         }
        
//         vector<int> ind;
//         vector<pair<int, bool>> pairs;
        
//         for(auto it: mp){
//             pairs.push_back((it.second, true));
//         }
        
//         for(int  i = 0; i<mp.size(); i++){
//             while(i.second != 0){
                
//             }
//         }
        
        vector<int> mp(26, 0);
       
        for(auto &ch : tasks){
            mp[ch - 'A']++;
        }
        
        int time =  0;
        
        priority_queue<int> pq; // by default max-heap
        
        for(int i = 0; i< 26; i++){
            if(mp[i] > 0){
                pq.push(mp[i]);
            }
        }
        
        while(!pq.empty()){
            
            vector<int> temp;
            
            for(int i = 1; i <= n + 1; i++){
                
                 if(!pq.empty()){
                int frq = pq.top();
                pq.pop();
                frq--;
                temp.push_back(frq);
                 }
            }
            for(int &f :  temp ){
                if(f > 0){
                    pq.push(f);
                }
            }
            
            if(pq.empty()){
                time += temp.size(); // temp{1, 0} = {1} A B _| A B _| (A _ ) <- (A)
            }else{
                time += n+1;
            }
            
        }
        return time;
    }
};